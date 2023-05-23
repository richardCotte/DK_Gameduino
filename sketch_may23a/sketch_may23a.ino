#include <Gamebuino-Meta.h>
#include "Player.h"
#include "World.h"
#include "Platform.h"

Player *player;
Platform *platform;
World *world;

void setup() {
    gb.begin();
    player = new Player(10, 50, 100, 1);
    world = new World();

    platform = new Platform(10, 50, 50, 50);
    world->addPlatform(platform, 0);
}

void loop() {
    while (!gb.update());
    gb.display.clear();
    player->update(world);
    player->draw();
    world->draw();
}