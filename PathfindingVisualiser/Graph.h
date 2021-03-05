#pragma once
#include <vector>
#include "Config.h"
#include "Node.h"

int rows;
int cols;

class Graph{
private:
	std::vector<std::vector<Node>> graph(rows, std::vector<int> (cols));
	std::vector<std::vector<Node>> adjList(rows*cols);

public:
	void init();
	void clear();
	void resize(int r, int c);
};