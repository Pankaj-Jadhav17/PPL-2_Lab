#include "../include/Queen.h"

Queen::Queen() : row(-1), col(-1) {}

Queen::Queen(int row, int col) : row(row), col(col) {}

int Queen::getRow() const { return row; }
int Queen::getCol() const { return col; }

void Queen::setRow(int r) { row = r; }
void Queen::setCol(int c) { col = c; }