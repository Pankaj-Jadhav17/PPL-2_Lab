#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <string>
using namespace std;

class Matrix {
protected:
    int rows;
    int cols;
    vector<vector<double>> data;

public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, const vector<vector<double>>& values);
    Matrix(const Matrix& other);            // copy constructor
    virtual ~Matrix();                      // virtual destructor (OOP best-practice)

    Matrix& operator=(const Matrix& other);

    int  getRows()                        const;
    int  getCols()                        const;
    double getElement(int r, int c)       const;
    void   setElement(int r, int c, double value);

    void display(const string& label = "") const;
    void inputFromUser();

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar)       const;
    bool   operator==(const Matrix& other)const;

    Matrix transpose()                    const;
    bool   isSquare()                     const;
    bool   isIdentity()                   const;
    void   fillIdentity();
    void   fillZero();

 
    virtual double compute()              const;   // Frobenius norm (base default)
    virtual void   printInfo()            const;   // basic dimension info

    friend Matrix operator*(double scalar, const Matrix& m);
    friend ostream& operator<<(ostream& os, const Matrix& m);
};

#endif