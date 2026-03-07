#include "../include/Board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = 0;
}

bool Board::isSafe(int row, int col) const {
    // Check all placed queens for conflicts
    for (const Queen& q : queens) {
        int r = q.getRow();
        int c = q.getCol();

        // Same row, same column, or same diagonal
        if (r == row || c == col ||
            (r - c) == (row - col) ||
            (r + c) == (row + col))
            return false;
    }
    return true;
}

bool Board::solve(int col) {
    if (col >= SIZE)
        return true;

    for (int row = 0; row < SIZE; row++) {
        if (isSafe(row, col)) {
            grid[row][col] = 1;
            queens.push_back(Queen(row, col));

            if (solve(col + 1))
                return true;

            grid[row][col] = 0;
            queens.pop_back();
        }
    }
    return false;
}

void Board::solveQueens() {
    if (!solve(0))
        std::cout << "No solution found.\n";
}

void Board::printBoard() const {
    std::string separator = "";
    for (int k = 0; k < SIZE; k++)
        separator += "----";
    separator += "-";

    std::cout << "\n";
    std::cout << separator << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            std::cout << (grid[i][j] == 1 ? "| Q " : "| . ");
        std::cout << "|\n";
        std::cout << separator << "\n";
    }
    std::cout << "\n";
}