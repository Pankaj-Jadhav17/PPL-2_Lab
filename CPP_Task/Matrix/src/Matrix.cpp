#include "../include/Matrix.hpp"
#include <stdexcept>
#include <iomanip>
#include <cmath>

using namespace std;

// Default constructor
Matrix::Matrix() : rows(0), cols(0) {}

// Parameterized constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0)
        throw invalid_argument("Invalid matrix size");

    data.assign(rows, vector<double>(cols, 0));
}

// Getters
int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

// Element access
double Matrix::getElement(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw out_of_range("Index out of range");
    return data[i][j];
}

void Matrix::setElement(int i, int j, double val) {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw out_of_range("Index out of range");
    data[i][j] = val;
}

// Check square
bool Matrix::isSquare() const {
    return rows == cols;
}

// Multiplication
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows)
        throw invalid_argument("Matrix multiplication not possible");

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < other.cols; j++)
            for (int k = 0; k < cols; k++)
                result.data[i][j] += data[i][k] * other.data[k][j];

    return result;
}

// Display
void Matrix::display(const string& label) const {
    if (!label.empty())
        cout << label << "\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(10) << fixed << setprecision(4) << data[i][j] << " ";
        }
        cout << "\n";
    }
}

// ================= CONSTRUCTORS =================
Matrix::Matrix(int r, int c, const vector<vector<double>>& values)
    : rows(r), cols(c), data(values) {}

Matrix::Matrix(const Matrix& other)
    : rows(other.rows), cols(other.cols), data(other.data) {}

Matrix::~Matrix() {}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

// ================= OPERATORS =================
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw invalid_argument("Matrix addition size mismatch");
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw invalid_argument("Matrix subtraction size mismatch");
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] * scalar;
    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (data[i][j] != other.data[i][j]) return false;
    return true;
}

// ================= UTILITIES =================
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[j][i] = data[i][j];
    return result;
}

bool Matrix::isIdentity() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            double expected = (i == j) ? 1.0 : 0.0;
            if (data[i][j] != expected) return false;
        }
    return true;
}

void Matrix::fillIdentity() {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = (i == j) ? 1.0 : 0.0;
}

void Matrix::fillZero() {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = 0.0;
}

void Matrix::inputFromUser() {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Enter [" << i << "][" << j << "]: ";
            cin >> data[i][j];
        }
}

double Matrix::compute() const {
    // Frobenius norm
    double sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += data[i][j] * data[i][j];
    return sqrt(sum);
}

void Matrix::printInfo() const {
    cout << "Matrix (" << rows << "x" << cols << ")\n";
}

// ================= FRIENDS =================
Matrix operator*(double scalar, const Matrix& m) {
    return m * scalar;
}

ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++)
            os << setw(10) << fixed << setprecision(4) << m.data[i][j] << " ";
        os << "\n";
    }
    return os;
}