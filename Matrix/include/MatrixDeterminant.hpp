#ifndef MATRIX_DETERMINANT_H
#define MATRIX_DETERMINANT_H
#include "Matrix.hpp"
using namespace std;

class MatrixDeterminant : public Matrix {
public:
    MatrixDeterminant();
    MatrixDeterminant(int size);                          // square n×n
    MatrixDeterminant(int size, const vector<vector<double>>& values);
    MatrixDeterminant(const MatrixDeterminant& other);
    MatrixDeterminant(const Matrix& base);               // up-cast from base
    virtual ~MatrixDeterminant();

    double compute()       const override;   // returns determinant
    void   printInfo()     const override;

    double determinantLaplace()    const;    // cofactor expansion O(n!)
    double determinantLU()         const;    // LU decomposition  O(n³)

    Matrix cofactorMatrix()        const;
    Matrix adjugate()              const;    // adj(A) = cof(A)^T
    int    rank()                  const;    // rank via row-reduction

    static MatrixDeterminant getSubMatrix(const Matrix& m, int skipRow, int skipCol);

protected:
    double determinantRecursive(const vector<vector<double>>& mat,int n) const;
};

#endif