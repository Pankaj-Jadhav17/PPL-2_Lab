#include"../include/Matrix.hpp"
#include<fstream>

void InverseMatrix::findInverse(string filename) {
    ofstream file(filename, ios::app);

    vector<vector<double>> inverse(n, vector<double>(2*n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = mat[i][j];
            for(int j=n; j<2*n; j++) {
                if(j==i+n) {
            
            }
