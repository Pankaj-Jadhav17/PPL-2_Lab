#ifndef QUADRATIC_ROOT_FINDER_H
#define QUADRATIC_ROOT_FINDER_H

#include <complex>

class QuadraticRootFinder {
private:
    double a, b, c;       // ax² + bx + c = 0
    double discriminant;  // b² - 4ac

public:
    QuadraticRootFinder(double a, double b, double c);
    void solve();         // Solves and prints the roots
};

#endif