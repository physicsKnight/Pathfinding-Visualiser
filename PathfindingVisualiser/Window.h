#pragma once

#include <string>
#include <SDL/SDL.h>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();
    bool isRunning() { return running; }
    void pollEvents();
    void clear();

private:
    bool init();
    std::string title;
    int width = 800;
    int height = 600;
    bool running = true;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};
