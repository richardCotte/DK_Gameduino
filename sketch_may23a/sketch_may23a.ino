#include <Gamebuino-Meta.h>
#include "Player.h"
#include "World.h"
#include "Platform.h"

Player* player;
Platform* platform;
World* world;

int playerStartX = 10;
int playerStartY = 50;
int playerHeight = 8;
int playerWidth = 3;
int playerJumpHeight = 5;
int playerStartPv = 100;

void setup() {
	gb.begin();
	player = new Player(playerStartX, playerStartY, playerWidth, playerHeight, playerJumpHeight, playerStartPv, 1);
	world = new World();

	platform = new Platform(0, 62, 79, 5);
	world->addPlatform(platform, 0);

	platform = new Platform(10, 60, 10, 3);
	world->addPlatform(platform, 1);

	platform = new Platform(20, 59, 10, 3);
	world->addPlatform(platform, 2);

	platform = new Platform(30, 58, 10, 3);
	world->addPlatform(platform, 3);

	platform = new Platform(40, 57, 10, 3);
	world->addPlatform(platform, 4);
}

void loop() {
	while (!gb.update());
	gb.display.clear();
	player->update(world);
	player->draw();
	world->draw();
}