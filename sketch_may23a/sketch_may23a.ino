#include <Gamebuino-Meta.h>
#include "Player.h"
#include "World.h"
#include "Platform.h"

Player *player;
Platform *platform;
World *world;

void setup()
{
    gb.begin();
    player = new Player(10, 50, 100, 1);
    world = new World();

// Plateforme 1
platform = new Platform(0, 60, 20, 1);
world->addPlatform(platform, 0);
platform = new Platform(20, 59, 20, 1);
world->addPlatform(platform, 1);
platform = new Platform(40, 58, 20, 1);
world->addPlatform(platform, 2);

// Plateforme 2
platform = new Platform(10, 50, 20, 1);
world->addPlatform(platform, 3);
platform = new Platform(30, 51, 20, 1);
world->addPlatform(platform, 4);
platform = new Platform(50, 52, 20, 1);
world->addPlatform(platform, 5);

// Plateforme 3
platform = new Platform(0, 40, 20, 1);
world->addPlatform(platform, 6);
platform = new Platform(20, 41, 20, 1);
world->addPlatform(platform, 7);
platform = new Platform(40, 42, 20, 1);
world->addPlatform(platform, 8);

// Plateforme 4
platform = new Platform(70, 30, 20, 1);
world->addPlatform(platform, 9);
platform = new Platform(50, 31, 20, 1);
world->addPlatform(platform, 10);
platform = new Platform(30, 32, 20, 1);
world->addPlatform(platform, 11);

// Plateforme 5
platform = new Platform(0, 20, 20, 1);
world->addPlatform(platform, 12);
platform = new Platform(20, 21, 20, 1);
world->addPlatform(platform, 13);
platform = new Platform(40, 22, 20, 1);
world->addPlatform(platform, 14);

// Plateforme 6
platform = new Platform(10, 10, 20, 1);
world->addPlatform(platform, 15);
platform = new Platform(30, 11, 20, 1);
world->addPlatform(platform, 16);
platform = new Platform(50, 12, 20, 1);
world->addPlatform(platform, 17);
platform = new Platform(70, 13, 20, 1);
world->addPlatform(platform, 18);
platform = new Platform(90, 14, 20, 1);
world->addPlatform(platform, 19);

}

void loop()
{
    while (!gb.update())
        ;
    gb.display.clear();
    player->update(world);
    player->draw();
    world->draw();
}