#ifndef FACTOR_H
#define FACTOR_H
#include<iostream>
#include<complex>
using namespace std;

class Factor{
    private:
        double a, b, c;
        complex<double> z1, z2;
    public:
        Factor(double a, double b, double c);
        void computeRoots();
        void printFactorization();
};

#endif