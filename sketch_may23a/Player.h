//
// Created by rcott on 23/05/2023.
//

#ifndef DK_REPO_PLAYER_H
#define DK_REPO_PLAYER_H

#include "World.h"

class Player {
private:
    int x, y; // Position du joueur
    int vy;   // Vitesse verticale (pour le saut)
    bool isJumping = false; // Statut de saut
    int pv;
    int sprite; //type a changer
    bool isClimbingLadder;
public:
    Player(int startX, int startY, int startPv, int sprite);

    void jump();

    void move();

    void update(World* world);

    void draw();

    void climb_ladder();

    void death();
};

Player::Player(int startX, int startY, int startPv, int sprite) : x(startX), y(startY), pv(startPv), sprite(sprite){}

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
        vy = -5; // vitesse initiale de saut
    }

    // Mise à jour de la physique du saut
    if (isJumping) {
        y += vy;
        vy++; // gravité
        if (y >= 50) { // supposons que le sol se trouve à y=100
            y = 50;
            isJumping = false;
        }
    }
}

void Player::draw() {
    gb.display.setColor(WHITE);
    gb.display.fillRect(x, y, 5, 10); // dessine le joueur comme un carré blanc de 10x10
}


#endif //DK_REPO_PLAYER_H
