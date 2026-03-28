#include "../include/Matrixinverse.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>

using namespace std;

#define EPS 1e-9

// ================= CONSTRUCTORS =================
MatrixInverse::MatrixInverse() : MatrixDeterminant() {}

MatrixInverse::MatrixInverse(int size) : MatrixDeterminant(size) {}

MatrixInverse::MatrixInverse(int size, const vector<vector<double>>& values)
    : MatrixDeterminant(size, values) {}

MatrixInverse::MatrixInverse(const MatrixInverse& other)
    : MatrixDeterminant(other) {}

MatrixInverse::MatrixInverse(const Matrix& base)
    : MatrixDeterminant(base) {}

MatrixInverse::~MatrixInverse() {}


// ================= OVERRIDES =================
double MatrixInverse::compute() const {
    return determinantLU();  // inherited
}

void MatrixInverse::printInfo() const {
    cout << "MatrixInverse (" << rows << "x" << cols << ")\n";
}


// ================= GAUSS-JORDAN INVERSE =================
Matrix MatrixInverse::inverseGaussJordan() const {
    if (!isSquare())
        throw runtime_error("Inverse requires square matrix");

    int n = rows;
    vector<vector<double>> aug(n, vector<double>(2 * n, 0));

    // Create augmented matrix [A | I]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            aug[i][j] = data[i][j];

        aug[i][i + n] = 1.0;
    }
    for (int i = 0; i < n; i++) {
        int pivot = i;

        for (int j = i + 1; j < n; j++) {
            if (fabs(aug[j][i]) > fabs(aug[pivot][i]))
                pivot = j;
        }
        if (fabs(aug[pivot][i]) < EPS)
            throw runtime_error("Matrix is singular");

        swap(aug[i], aug[pivot]);

        double div = aug[i][i];
        for (int j = 0; j < 2 * n; j++)
            aug[i][j] /= div;

        for (int k = 0; k < n; k++) {
            if (k == i) continue;

            double factor = aug[k][i];
            for (int j = 0; j < 2 * n; j++)
                aug[k][j] -= factor * aug[i][j];
        }
    }
    Matrix inv(n, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv.setElement(i, j, aug[i][j + n]);

    return inv;
}

// ================= ADJUGATE INVERSE =================
Matrix MatrixInverse::inverseAdjugate() const {
    double det = determinantLU();

    if (fabs(det) < EPS)
        throw runtime_error("Matrix is singular");

    Matrix adj = adjugate();
    return adj * (1.0 / det);
}

// ================= VERIFY =================
bool MatrixInverse::verify() const {
    Matrix inv = inverseGaussJordan();
    Matrix result = (*this) * inv;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double expected = (i == j) ? 1.0 : 0.0;

            if (fabs(result.getElement(i, j) - expected) > 1e-6)
                return false;
        }
    }
    return true;
}

// ================= CONDITION NUMBER =================
double MatrixInverse::conditionNumber() const {
    Matrix inv = inverseGaussJordan();
    return frobeniusNorm(*this) * frobeniusNorm(inv);
}

// ================= SOLVE Ax = b =================
vector<double> MatrixInverse::solve(const vector<double>& b) const {
    if ((int)b.size() != rows)
        throw runtime_error("Dimension mismatch");

    Matrix inv = inverseGaussJordan();
    vector<double> x(rows, 0);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            x[i] += inv.getElement(i, j) * b[j];

    return x;
}

// ================= FROBENIUS NORM =================
double MatrixInverse::frobeniusNorm(const Matrix& m) const {
    double sum = 0;

    for (int i = 0; i < m.getRows(); i++)
        for (int j = 0; j < m.getCols(); j++)
            sum += pow(m.getElement(i, j), 2);

    return sqrt(sum);
}