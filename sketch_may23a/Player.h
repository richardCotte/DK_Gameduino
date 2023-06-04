//
// Created by rcott on 23/05/2023.
//

#ifndef DK_REPO_PLAYER_H
#define DK_REPO_PLAYER_H

#include "World.h"
#include "Platform.h"

class Player {
private:
	int x, y; // Position du joueur
	int vy = 1;   // Vitesse verticale (pour la gravité)
	int height;
	int width;
	int jumpHeight;
	bool isOnTheGround;
	bool isClimbing;
	int pv;
	int sprite; //type a changer

	bool isOnThePlatform(Platform* platform);
	bool isOnTheLadder(Ladder* ladder);

public:
	Player(int startX, int startY, int playerWidth, int playerHeight, int definedJumpHeight, int startPv, int sprite);

	void update(World* world);

	void draw();
};

Player::Player(int startX, int startY, int playerWidth, int playerHeight, int definedJumpHeight, int startPv,
	int sprite) : x(startX), y(startY), width(playerWidth), height(playerHeight),
	jumpHeight(definedJumpHeight), pv(startPv), sprite(sprite) {}

bool Player::isOnThePlatform(Platform* platform) {
	// Offset du sol : si le joueur est déjà au sol, l'offset est de 1, sinon 0
	const int groundOffset = isOnTheGround ? 1 : 0;

	// Calcul des coordonnées des rayons de détection gauche et droit
	const int leftRayY = y + height - groundOffset;
	const int rightRayY = y + height - groundOffset;
	const int leftRayX = x;
	const int rightRayX = x + width - 1;
	const int rayWidth = 1;
	const int rayHeight = gb.display.height() - (y + height);

	// Détection de collision avec les rayons de détection gauche et droit
	bool isLeftRayTouching = gb.collide.rectRect(leftRayX, leftRayY, rayWidth, rayHeight, platform->getX(), platform->getY(), platform->getWidth(), 1);
	bool isRightRayTouching = gb.collide.rectRect(rightRayX, rightRayY, rayWidth, rayHeight, platform->getX(), platform->getY(), platform->getWidth(), 1);

	// Détection de collision avec la plateforme
	bool isPlayerTouching = gb.collide.rectRect(x, y, width, height + 1 + vy, platform->getX(), platform->getY(), platform->getWidth(), platform->getHeight());

	// Vérification si le joueur est sur la plateforme
	return (isLeftRayTouching || isRightRayTouching) && isPlayerTouching;
}

void Player::update(World* world) {
	// Contrôle du mouvement horizontal
	if (gb.buttons.repeat(BUTTON_LEFT, 0) && x > 0) {
		x--;
	}
	if (gb.buttons.repeat(BUTTON_RIGHT, 0) && x + width < 79) {
		x++;
	}

	// Vérification si le joueur est sur une plateforme
	bool foundPlatform = false;
	Platform** platforms = world->getPlatforms();
	for (int i = 19; i >= 0; i--) {
		if (platforms[i] != nullptr && isOnThePlatform(platforms[i])) {
			// Le joueur est sur une plateforme
			foundPlatform = true;
			isOnTheGround = true;
			vy = 0;
			y = platforms[i]->getY() - height;
			break;
		}
	}

	// Gestion de la gravité et du saut
	if (foundPlatform) {
		// Le joueur est sur une plateforme
		vy = 0;
	}
	else {
		// Le joueur est dans les airs
		isOnTheGround = false;
		// Gestion de la gravité
		y += vy;
		vy++;
	}

	// Gestion du saut
	if (gb.buttons.pressed(BUTTON_A) && isOnTheGround) {
		//Son de saut
		gb.sound.play("/sound/jump.wav");
		vy = -jumpHeight;
	}
}

void Player::draw() {
	gb.display.setColor(YELLOW);
	gb.display.fillRect(x, y, width, height);
	gb.display.setColor(BLUE);
	gb.display.fillRect(x, y + height, 1, gb.display.height() - (y + height));
	gb.display.fillRect(x + width - 1, y + height, 1, gb.display.height() - (y + height));
}


#endif //DK_REPO_PLAYER_H
