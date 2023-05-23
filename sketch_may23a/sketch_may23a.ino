#include <Gamebuino-Meta.h>

void setup() {
    gb.begin();
}

void loop() {
    while (!gb.update());
    gb.display.clear();
    gb.display.print("hello, world");
}