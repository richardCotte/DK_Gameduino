//
// Created by rcott on 23/05/2023.
//

#ifndef DK_REPO_WORLD_H
#define DK_REPO_WORLD_H

#include "Platform.h"
#include "Ladder.h"

class World {
private:
	Platform* platforms[19] = {};
	Ladder* ladders[20] = {};
public:
	World();
	void addPlatform(Platform* platform, int index);
	void addLadder(Ladder* ladder, int index);
	void draw();
	Platform** getPlatforms();
	Ladder** getLadders();
};

World::World() {}

void World::addPlatform(Platform* platform, int index) {
	platforms[index] = platform;
}

void World::addLadder(Ladder* ladder, int index) {
	ladders[index] = ladder;
}

void World::draw() {
	for (Platform* platform : platforms) {
		if (platform != nullptr) {
			platform->draw();
		}
	}
	for (Ladder* ladder : ladders) {
		if (ladder != nullptr) {
			ladder->draw();
		}
	}
}

Platform** World::getPlatforms() {
	return platforms;
}

Ladder** World::getLadders() {
	return ladders;
}

#endif //DK_REPO_WORLD_H
