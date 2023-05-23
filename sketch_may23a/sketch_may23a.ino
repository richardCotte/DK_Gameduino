#include <Gamebuino-Meta.h>
#include "Player.h"
#include "World.h"
#include "Platform.h"

Player *player;
Platform *platform;
World *world;

int playerStartX = 10;
int playerStartY = 50;
int playerHeight = 8;
int playerWidth = 2;
int playerJumpHeight = 5;
int playerStartPv = 100;

void setup() {
    gb.begin();
    player = new Player(playerStartX, playerStartY, playerWidth, playerHeight, playerJumpHeight, playerStartPv, 1);
    world = new World();

    platform = new Platform(30, 50, 50, 5);
    world->addPlatform(platform, 0);
    platform = new Platform(15, 45, 50, 5);
    world->addPlatform(platform, 1);
}

void loop() {
    while (!gb.update());
    gb.display.clear();
    player->update(world);
    player->draw();
    world->draw();
}