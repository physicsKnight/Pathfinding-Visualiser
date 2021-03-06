#pragma once
#include <vector>
#include "Node.h"

class Graph{
private:
	std::vector<std::vector<Node>> graph;
    std::vector<std::vector<Node>> adjList;
    void addEdges(int val, int r, int c);

public:
	void init();
	void clear();
};
