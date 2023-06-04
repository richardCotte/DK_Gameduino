//
// Created by rcott on 23/05/2023.
//

#ifndef DK_REPO_PLATFORM_H
#define DK_REPO_PLATFORM_H

class Platform {
private:
    int x;
    int y;
    int height;
    int width;
public:
    Platform(int platX, int platY, int platWidth, int platHeight);
    void draw();
};

Platform::Platform(int platX, int platY, int platWidth, int platHeight) : x(platX), y(platY), width(platWidth), height(platHeight) {}

void Platform::draw() {
    gb.display.setColor(RED);
    gb.display.fillRect(x, y, width, height);
}

#endif //DK_REPO_PLATFORM_H
