//
// Created by rcott on 23/05/2023.
//

#ifndef DK_REPO_WORLD_H
#define DK_REPO_WORLD_H

#include "Platform.h"
#include "Barrel.h"

class World {
private:
	Platform* platforms[22] = {};
	Barrel* barrels[20] = {};
public:
	World();
	void addPlatform(Platform* platform, int index);
	void addBarrel(Barrel* barrel, int index);
	void draw();
	void update();
	Platform** getPlatforms();
	Barrel** getBarrels();
};

World::World() {}

void World::update() {
	for (Barrel* barrel : barrels) {
		if (barrel != nullptr) {
			barrel->update();
		}
	}
}

void World::addPlatform(Platform* platform, int index) {
	platforms[index] = platform;
}


void World::addBarrel(Barrel* barrel, int index) {
	barrels[index] = barrel;
}

void World::draw() {
	for (Platform* platform : platforms) {
		if (platform != nullptr) {
			platform->draw();
		}
	}
	for (Barrel* barrel : barrels) {
		if (barrel != nullptr) {
			barrel->draw();
		}
	}
}

Platform** World::getPlatforms() {
	return platforms;
}

Barrel** World::getBarrels() {
	return barrels;
}
#endif //DK_REPO_WORLD_H
