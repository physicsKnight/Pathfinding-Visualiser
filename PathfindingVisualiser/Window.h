#pragma once

#include <string>
#include <SDL/SDL.h>

#include "Graph.h"
#include "Renderer.h"

class Window {
public:
    Window(const std::string &title, int width, int height, Graph graph);
    ~Window();
    bool isRunning() { return running; }
    void pollEvents();
    void clear();
    void update();

private:
    bool init();
    void handkleKeyboardEvent();
    void clickCell(int row, int col);

    std::string title;
    int width = 800;
    int height = 600;
    bool running = true;

    Graph *graph = nullptr;
    Renderer *graphRenderer = nullptr;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};
