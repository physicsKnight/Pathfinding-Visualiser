#include <SDL/SDL.h>
#include <string>
#include <iostream>
#include "Window.h"
#include "config.h"

int main(int argc, char** argv) {
    std::string title = "Pathfinding Visualiser";
    int width = 800;
    int height = 600;

    Window window(title, width, height);

    while (window.isRunning()) {
        window.pollEvents();
        window.clear();
    }
    return 0;
}
