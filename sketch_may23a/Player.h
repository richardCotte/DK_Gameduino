//
// Created by rcott on 23/05/2023.
//

#ifndef DK_REPO_PLAYER_H
#define DK_REPO_PLAYER_H

#include "World.h"
#include "Platform.h"
#include "Barrel.h"

class Player {
private:
	int x, y, goalX, goalY; // Position du joueur et du but
	int defaultX, defaultY; // Position par défaut en cas de loose ou de win
	int vy = 1;   // Vitesse verticale (pour la gravité)
	int height, goalHeight;
	int width, goalWidth;
	int jumpHeight;
	bool isOnTheGround;
	int pv, defaultPv;
	int score;

	bool isOnThePlatform(Platform* platform);
	bool isTouchingBarrel(Barrel* barrel);
	void drawPlayer();
	void drawScore();
	void drawGoal();
	void drawPv();
	void hitOrFall();
	void defaultSpawn();

public:
	Player(int startX, int startY, int playerWidth, int playerHeight, int definedJumpHeight, int startPv);

	void update(World* world);

	void draw();
};

Player::Player(int startX, int startY, int playerWidth, int playerHeight, int definedJumpHeight, int startPv) : x(startX), y(startY), width(playerWidth), height(playerHeight),
jumpHeight(definedJumpHeight), pv(startPv) {
	score = 0;
	goalX = 38;
	goalY = 3;
	goalHeight = 4;
	goalWidth = 4;
	defaultX = startX;
	defaultY = startY;
	defaultPv = startPv;
}

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

bool Player::isTouchingBarrel(Barrel* barrel) {
	return gb.collide.rectRect(x, y, width, height + 1 + vy, barrel->getX(), barrel->getY(), barrel->getSize(), barrel->getSize());
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
	for (int i = 22; i >= 0; i--) {
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
		// Son de saut
		gb.sound.play("/sound/jump.wav");
		vy = -jumpHeight;
	}

	bool isPlayerTouchingGoal = gb.collide.rectRect(x, y, width, height + vy, goalX, goalY, goalWidth, goalHeight);

	// Gestion du score et remise a 0
	if (isPlayerTouchingGoal) {
		gb.sound.play("/sound/win.wav");
		score++;
		defaultSpawn();
	}

	if (y > 63) {
		hitOrFall();
	}

	Barrel** barrels = world->getBarrels();
	for (int i = 15; i >= 0; i--) {
		if (barrels[i] != nullptr && isTouchingBarrel(barrels[i])) {
			hitOrFall();
		}
	}
}

void Player::draw() {
	drawPlayer();
	drawGoal();
	drawScore();
	drawPv();
}

void Player::drawPlayer() {
	// Dessin du joueur
	gb.display.setColor(YELLOW);
	gb.display.fillRect(x, y, width, height);
	gb.display.setColor(BLUE);
	gb.display.fillRect(x, y + height, 1, gb.display.height() - (y + height));
	gb.display.fillRect(x + width - 1, y + height, 1, gb.display.height() - (y + height));
}

void Player::drawGoal() {
	// Dessin de l'objectif
	gb.display.setColor(YELLOW);
	gb.display.fillRect(goalX, goalY, goalWidth, goalHeight);
}

void Player::drawScore() {
	gb.display.setColor(WHITE);
	gb.display.print("Score : ");
	gb.display.print(score);
}

void Player::drawPv() {
	gb.display.setColor(RED);
	gb.display.print("   Pv : ");
	gb.display.print(pv);
}

void Player::hitOrFall() {
	defaultSpawn();
	pv--;
	gb.sound.play("/sound/hit.wav");
	if (pv == 0) {
		score = 0;
		pv = defaultPv;
		gb.sound.play("/sound/death.wav");
	}
}

void Player::defaultSpawn() {
	x = defaultX;
	y = defaultY;
}


#endif //DK_REPO_PLAYER_H
