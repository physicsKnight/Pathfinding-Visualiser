namespace config {
    int rows = 10;
    int cols = 10;
    int CELLSIZE = 10;

    typedef enum {NONE = 0, START = 1, END = 2, WEIGHT = 3, BARRIER = 4} Mode;
    Mode mode = NONE;
}
