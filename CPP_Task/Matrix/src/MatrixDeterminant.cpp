#include "../include/MatrixDeterminant.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace std;

#define EPS 1e-9

// Constructor
MatrixDeterminant::MatrixDeterminant(int n) : Matrix(n, n) {}

// LU determinant (FAST)
double MatrixDeterminant::determinantLU() const {
    if (!isSquare())
        throw runtime_error("Determinant requires square matrix");
    int n = rows;
    vector<vector<double>> temp = data;
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        int pivot = i;

        for (int j = i + 1; j < n; j++) {
            if (fabs(temp[j][i]) > fabs(temp[pivot][i]))
                pivot = j;
        }

        if (fabs(temp[pivot][i]) < EPS)
            return 0.0;

        if (i != pivot) {
            swap(temp[i], temp[pivot]);
            det *= -1;
        }

        det *= temp[i][i];

        for (int j = i + 1; j < n; j++) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i; k < n; k++)
                temp[j][k] -= factor * temp[i][k];
        }
    }

    return det;
}

// Laplace (slow)
double MatrixDeterminant::determinantLaplace() const {
    if (!isSquare())
        throw runtime_error("Determinant requires square matrix");

    return determinantRecursive(data, rows);
}
//  Recursive helper
double MatrixDeterminant::determinantRecursive(const vector<vector<double>>& mat, int n) const {
    if (n == 1) return mat[0][0];

    double det = 0;

    for (int col = 0; col < n; col++) {
        MatrixDeterminant sub = getSubMatrix(Matrix(n, n, mat), 0, col);
        double sign = (col % 2 == 0) ? 1 : -1;

        det += sign * mat[0][col] * determinantRecursive(sub.data, n - 1);
    }

    return det;
}

//Submatrix
MatrixDeterminant MatrixDeterminant::getSubMatrix(const Matrix& m, int skipRow, int skipCol) {
    int n = m.getRows();
    vector<vector<double>> sub(n - 1, vector<double>(n - 1));
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i == skipRow) continue;
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (j == skipCol) continue;
            sub[r][c++] = m.getElement(i, j);
        }
        r++;
    }
    return MatrixDeterminant(n - 1, sub);
}

//Cofactor matrix
Matrix MatrixDeterminant::cofactorMatrix() const {
    int n = rows;
    Matrix cof(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            MatrixDeterminant sub = getSubMatrix(*this, i, j);
            double sign = ((i + j) % 2 == 0) ? 1 : -1;
            cof.setElement(i, j, sign * sub.determinantLU());
        }
    }

    return cof;
}

// Adjugate
Matrix MatrixDeterminant::adjugate() const {
    return cofactorMatrix().transpose();
}
// Rank
int MatrixDeterminant::rank() const {
    vector<vector<double>> temp = data;

    int m = rows;
    int n = cols;
    int rank = 0;

    for (int col = 0, row = 0; col < n && row < m; col++) {
        int pivot = row;

        for (int i = row + 1; i < m; i++) {
            if (fabs(temp[i][col]) > fabs(temp[pivot][col]))
                pivot = i;
        }

        if (fabs(temp[pivot][col]) < EPS)
            continue;

        swap(temp[pivot], temp[row]);

        for (int i = row + 1; i < m; i++) {
            double factor = temp[i][col] / temp[row][col];
            for (int j = col; j < n; j++)
                temp[i][j] -= factor * temp[row][j];
        }
        row++;
        rank++;
    }
    return rank;
}
// ================= MISSING CONSTRUCTORS =================
MatrixDeterminant::MatrixDeterminant() : Matrix() {}

MatrixDeterminant::MatrixDeterminant(int size, const vector<vector<double>>& values)
    : Matrix(size, size, values) {}

MatrixDeterminant::MatrixDeterminant(const MatrixDeterminant& other)
    : Matrix(other) {}

MatrixDeterminant::MatrixDeterminant(const Matrix& base)
    : Matrix(base) {}

MatrixDeterminant::~MatrixDeterminant() {}

double MatrixDeterminant::compute() const {
    return determinantLU();
}

void MatrixDeterminant::printInfo() const {
    cout << "MatrixDeterminant (" << rows << "x" << cols << ")\n";
}