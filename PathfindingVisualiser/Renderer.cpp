#include "Renderer.h"
#include "Config.h"

Renderer::Renderer(SDL_Renderer *renderer, SDL_Window *window) {
    this->renderer = renderer;
    this->window = window;
}

void Renderer::drawCell(Node *node) {
    if (node->state == condif::NONE)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    else if (node->state == config::BARRIER)
        SDL_SetRenderDrawcOLOR(renderer, 255, 0, 0, 255);
    else if (node->state == config::START)
        SDL_SetRenderDrawcOLOR(renderer, 0, 255, 0, 255);
    else if (node->state == config::END)
        SDL_SetRenderDrawcOLOR(renderer, 255, 0, 0, 255);

    SDL_Rect rect = {node->col * CELLSIZE,
                     node->row * CELLSIZE,
                     CELLSIZE,   CELLSIZE};
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::drawGrid() {
}
