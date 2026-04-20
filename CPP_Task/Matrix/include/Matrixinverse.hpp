#ifndef MATRIX_INVERSE_H
#define MATRIX_INVERSE_H
#include"MatrixDeterminant.hpp"
using namespace std;

class MatrixInverse : public MatrixDeterminant {
public:
    MatrixInverse();
    MatrixInverse(int size);
    MatrixInverse(int size, const vector<vector<double>>& values);
    MatrixInverse(const MatrixInverse& other);
    MatrixInverse(const Matrix& base);           // up-cast from base
    virtual ~MatrixInverse();

    double compute()    const override;          // returns determinant
    void   printInfo()  const override;

    Matrix inverseGaussJordan() const;           // recommended (stable)
    Matrix inverseAdjugate()    const;           // adj(A) / det(A)

    bool   verify()             const;           // A × A⁻¹ ≈ I ?
    double conditionNumber()    const;           // ||A|| · ||A⁻¹||

    vector<double> solve(const vector<double>& b) const;

private:
    double frobeniusNorm(const Matrix& m) const;
};

#endif