#ifndef BOARD_H
#define BOARD_H

#include "Queen.h"
#include <vector>

class Board {
private:
    static const int SIZE = 8;
    int grid[SIZE][SIZE];
    std::vector<Queen> queens;

    bool isSafe(int row, int col) const;
    bool solve(int col);

public:
    Board();
    void solveQueens();
    void printBoard() const;
};

#endif