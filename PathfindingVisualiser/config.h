#pragma once

namespace config {
    extern int rows;
    extern int cols;
    extern int CELLSIZE;

    typedef enum {NONE = 0, START = 1, END = 2, WEIGHT = 3, BARRIER = 4} Mode;
    extern Mode state;
}
