#include<iostream>
#include<fstream>
#include "Sudoku.h"

using namespace std;

void Sudoku::readFile()
{
    ifstream in("input.txt");

    char ch;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            in >> ch;
            grid[i][j] = ch - '0';
        }
    }

    in.close();
}

void Sudoku::writeFile()
{
    ofstream out("output.txt");

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            out << grid[i][j];
        out << endl;
    }

    out.close();
}

bool Sudoku::isSafe(int r,int c,int num)
{
    for(int i=0;i<9;i++)
        if(grid[r][i]==num || grid[i][c]==num)
            return false;

    int sr=r-r%3, sc=c-c%3;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(grid[sr+i][sc+j]==num)
                return false;

    return true;
}

bool Sudoku::solve()
{
    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){

            if(grid[r][c]==0){

                for(int num=1;num<=9;num++){

                    if(isSafe(r,c,num)){

                        grid[r][c]=num;

                        if(solve())
                            return true;

                        grid[r][c]=0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}