#include "Graph.h"
#include "Config.h"

void Graph::init() {
    graph.resize(config::rows, std::vector<Node>(config::cols));
    adjList.resize(config::rows * config::cols);

    // add nodes to graph
    int count = 0;
    for (int i = 0; i < config::rows; ++i) {
        for (int j = 0; j < config::cols; ++j) {
            Node node(i, j, count);
            graph[i][j] = node;
        }
    }

    // add correct edges to each node
    for (int i = 0; i < config::rows; ++i) {
        for (int j = 0; j < config::cols; ++j) {
            addEdges(graph[i][j].getVal(), i, j);
        }
    }
}

bool inGraph(int row, int col) {
    return (row >= 0 && row < config::rows) &&
           (col >= 0 && col < config::cols);
}

void Graph::addEdges(int val, int r, int c) {
    if (inGraph(r-1, c)) // up
        adjList[val].push_back(graph[r-1][c]);

    if (inGraph(r, c+1)) // right
        adjList[val].push_back(graph[r][c+1]);

    if (inGraph(r+1, c)) // down
        adjList[val].push_back(graph[r+1][c]);

    if (inGraph(r, c-1)) // left
        adjList[val].push_back(graph[r][c-1]);
}

void Graph::clear() {
    graph.clear();
    adjList.clear();
}
