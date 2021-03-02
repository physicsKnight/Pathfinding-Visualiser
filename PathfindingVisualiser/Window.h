#pragma once

#include <string>

class Window {
public:
	Window(const std::string &title, int width, int height);
	~Window();

private:
	std::string title;
	int width = 800;
	int height = 600;
	bool closed = false;
};
