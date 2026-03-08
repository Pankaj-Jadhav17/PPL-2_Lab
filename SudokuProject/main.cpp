#include<iostream>
#include "Sudoku.h"

using namespace std;

int main()
{
    Sudoku s;

    s.readFile();

    if(s.solve())
        s.writeFile();
    else
        cout<<"No solution\n";

    return 0;
}