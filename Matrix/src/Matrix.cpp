#include<iostream>
#include "../include/Matrix.hpp"
#include<fstream>
#include<sstream>
#include<cmath> 
using namespace std;

Matrix::Matrix() {
    n = 0;
}

void Matrix::readMatrix(string filename) {
    ifstream infile(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file>>n;
    string line;
    mat.resize(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            file >> mat[i][j];
        }
}
    file.close();
}

void Matrix::printMatrixToFile(string filename) {
    ofstream outfile(filename);
    file<<"Original Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            file << mat[i][j] << " ";
        }
        file << endl;
    }
    file.close();   
}
