#pragma once

namespace config {
    extern int rows;
    extern int cols;

    enum Mode(NONE = 0, START = 1, END = 2, WEIGHT = 3, BARRIER = 4);
    extern Mode mode;
}
