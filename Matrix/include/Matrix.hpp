#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
    protected:
        int n;
        vector<vector<double>> mat;
    public:
        Matrix();
        void readMatrix(string filename);
        void printMatrixToFile(string filename);
};

class InverseMatrix : public Matrix {
    public:
        void findInverse(string filename);
};
#endif // MATRIX_HPP
