#pragma once
#include "Config.h"

class Node {
private:
    int row;
    int column;
    int weight;
    int val;
    int state = 0;

public:
    Node(int row, int column, int val, int weight = 0) {
        this->row = row;
        this->column = column;
        this->weight = weight;
        this->val = val;
    }

    int getRow() { return this->row; }
    int getColumn() { return this->column; }
    int getVal() { return this->val; }
    int getWeight() { return this->weight; }

    void setWeight(int weight) { this->weight = weight; }
    void setState(int state) { this->state = state; }
};
