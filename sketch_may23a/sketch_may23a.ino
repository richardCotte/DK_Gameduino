#include <Gamebuino-Meta.h>
#include "Player.h"
#include "World.h"
#include "Platform.h"
#include "Barrel.h"

Player* player;
Platform* platform;
World* world;
Barrel* barrel;

int playerStartX = 10;
int playerStartY = 50;
int playerHeight = 6;
int playerWidth = 2;
int playerJumpHeight = 3;
int playerStartPv = 3;
int barrelSize = 5;
int barrelSpeed = 1;

void setup() {
	gb.begin();

	//Main theme
	gb.sound.play("/sound/main.wav", true);

	player = new Player(playerStartX, playerStartY, playerWidth, playerHeight, playerJumpHeight, playerStartPv);
	world = new World();
	barrel = new Barrel(barrelSize, 4, 4, barrelSpeed);
	world->addBarrel(barrel, 0);

	createPlateforms(world);
}

void loop() {
	while (!gb.update());
	gb.display.clear();
	player->update(world);
	player->draw();
	world->draw();
	world->update();
}

void createPlateforms(World* world) {
	// Plateforme 1
	platform = new Platform(0, 60, 20, 1);
	world->addPlatform(platform, 0);
	platform = new Platform(20, 59, 20, 1);
	world->addPlatform(platform, 1);
	platform = new Platform(40, 58, 20, 1);
	world->addPlatform(platform, 2);

	// Plateforme 2
	platform = new Platform(50, 52, 20, 1);
	world->addPlatform(platform, 3);
	platform = new Platform(30, 51, 20, 1);
	world->addPlatform(platform, 4);
	platform = new Platform(10, 50, 20, 1);
	world->addPlatform(platform, 5);

	// Plateforme 3
	platform = new Platform(0, 44, 20, 1);
	world->addPlatform(platform, 6);
	platform = new Platform(20, 43, 20, 1);
	world->addPlatform(platform, 7);
	platform = new Platform(40, 42, 20, 1);
	world->addPlatform(platform, 8);

	// Plateforme 4
	platform = new Platform(55, 36, 20, 1);
	world->addPlatform(platform, 9);
	platform = new Platform(35, 35, 20, 1);
	world->addPlatform(platform, 10);
	platform = new Platform(15, 34, 20, 1);
	world->addPlatform(platform, 11);

	// Plateforme 5
	platform = new Platform(0, 28, 20, 1);
	world->addPlatform(platform, 12);
	platform = new Platform(20, 27, 20, 1);
	world->addPlatform(platform, 13);
	platform = new Platform(40, 26, 20, 1);
	world->addPlatform(platform, 14);

	// Plateforme 6
	platform = new Platform(50, 20, 20, 1);
	world->addPlatform(platform, 15);
	platform = new Platform(30, 19, 20, 1);
	world->addPlatform(platform, 16);
	platform = new Platform(10, 18, 20, 1);
	world->addPlatform(platform, 17);

	// Plateforme 7
	platform = new Platform(5, 12, 20, 1);
	world->addPlatform(platform, 18);
	platform = new Platform(25, 11, 20, 1);
	world->addPlatform(platform, 19);
}