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
    int vy;   // Vitesse verticale (pour le saut)
    int height;
    int width;
    int jumpHeight;
    bool isJumping = false; // Statut de saut
    bool isGoingDown = false;
    int pv;
    int sprite; //type a changer
    bool isClimbingLadder;

    bool isAboveThePlatform(int vitesse, Platform *platform);

public:
    Player(int startX, int startY, int playerWidth, int playerHeight, int definedJumpHeight, int startPv, int sprite);

    void jump();

    void move();

    void update(World *world);

    void draw();

    void climb_ladder();

    void death();
};

Player::Player(int startX, int startY, int playerWidth, int playerHeight, int definedJumpHeight, int startPv,
               int sprite) : x(startX), y(startY), width(playerWidth), height(playerHeight),
                             jumpHeight(definedJumpHeight), pv(startPv), sprite(sprite) {}

bool Player::isAboveThePlatform(int vitesse, Platform *platform) {
    return y + height <= platform->getY() && platform->getX() + platform->getWidth() > x && x > platform->getX() && y + height >= platform->getY() - vitesse;
}

void Player::update(World *world) {
    // Contrôle du mouvement horizontal
    if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
        x--;
    }
    if (gb.buttons.repeat(BUTTON_RIGHT, 0)) {
        x++;
    }

    // Contrôle du saut
    if (gb.buttons.pressed(BUTTON_A) && !isJumping) {
        isJumping = true;
        vy = -jumpHeight; // vitesse initiale de saut
    }

//     Mise à jour de la physique du saut
    if (isJumping) {
        y += vy;
        vy++; // gravité
        if (vy > 0) isGoingDown = true;
        Platform **platforms = world->getPlatforms();
        for (int i = 19; i >= 0; --i) {
            if (platforms[i] != nullptr) {
//                if (platforms[i] >)
                if (isGoingDown && Player::isAboveThePlatform(vy, platforms[i])) {
                    gb.display.print(isGoingDown);
                    y = platforms[i]->getY() - height;
                    isJumping = false;
                    isGoingDown = false;
                }
            }
        }
    }
//    if (isJumping) {
//        y += vy;
//        vy++; // gravité
//        if (y >= 50) { // supposons que le sol se trouve à y=100
//            y = 50;
//            isJumping = false;
//        }
//    }
}

void Player::draw() {
    gb.display.setColor(WHITE);
    gb.display.fillRect(x, y, width, height); // dessine le joueur comme un carré blanc de 10x10
}


#endif //DK_REPO_PLAYER_H
