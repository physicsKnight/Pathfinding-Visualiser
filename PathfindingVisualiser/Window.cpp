#include "Window.h"
#include <iostream>


Window::Window(const std::string& title, int width, int height) {
	this->title = title;
	this->width = width;
	this->height = height;

	if (init() == false) {
		running = false;
	}
}

Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}


bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "failed to initialize" << std::endl;
		return false;
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,width, height, 0);

	if (window == nullptr) {
		std::cerr << "failed to create window" << std::endl;
		return false;
	}

	return true;
}
