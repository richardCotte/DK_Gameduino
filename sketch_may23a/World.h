//
// Created by rcott on 23/05/2023.
//

#ifndef DK_REPO_WORLD_H
#define DK_REPO_WORLD_H

#include "Platform.h"

class World {
private:
    Platform* platforms[20] = {};
//    Ladder ladders;
public:
    World();
    void addPlatform(Platform *platform, int index);
    void draw();
};

World::World() {}

void World::addPlatform(Platform* platform, int index) {
    platforms[index] = platform;
}

void World::draw(){
    for (Platform* platform : platforms) {
        if (platform != nullptr) {
            platform->draw();
        }
    }
}

#endif //DK_REPO_WORLD_H
