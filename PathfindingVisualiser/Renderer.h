#pragma once

#include <SDL/SDL.h>

#include "Node.h"

class Renderer {
public:
    Renderer(SDL_Renderer *renderer, SDL_Window *window);
    void drawCell(Node node);
    void drawGrid();

private:
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
}
