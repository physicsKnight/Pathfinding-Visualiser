#include <iostream>

#include "Window.h"
#include "config.h"

Window::Window(const std::string& title, int width, int height, Graph graph) {
    this->title = title;
    this->width = width;
    this->height = height;
    this-> graph = graph;

    running = init();

    graph = new Graph();
    graphRenderer = new Renderer(renderer, window);
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    delete graph;
    delete graphRenderer;
}


bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "failed to initialize\n" << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (window == nullptr) {
        std::cerr << "failed to create window\n" << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "failed to create renderer\n" << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Window::pollEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            handkleKeyboardEvent();
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;
        default:
            break;
        }
    }
}

void Window::handkleKeyboardEvent() {
    SDL_PumpEvents();
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W])
        config::mode = config::WEIGHT;
    else if (state[SDL_SCANCODE_B])
        config::mode = config::BARRIER;
    else if (state[SDL_SCANCODE_S])
        config::mode = config::START;
    else if (state[SDL_SCANCODE_E])
        config::mode = config::END;
    else if (state[SDL_SCANCODE_ESCAPE]) {
    }
}

void Window::clickCell(int row, int col) {
}

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
