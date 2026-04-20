#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku {

private:
    int grid[9][9];

public:
    void readFile();
    void writeFile();
    bool isSafe(int r,int c,int num);
    bool solve();
};

#endif