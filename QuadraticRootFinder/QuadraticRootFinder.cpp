#include "QuadraticRootFinder.h"
#include <iostream>
#include <cmath>
using namespace std;

QuadraticRootFinder::QuadraticRootFinder(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void QuadraticRootFinder::solve() {
    cout << "\n Equation: " << a << "x^2 + " << b << "x + " << c << " = 0\n";

    double disc = (b * b) - (4 * a * c);   // discriminant = b^2 - 4ac
    cout << " Discriminant = " << disc << "\n\n";

    if (disc > 0) {
        // ✅ Two distinct REAL roots
        double x1 = (-b + sqrt(disc)) / (2 * a);
        double x2 = (-b - sqrt(disc)) / (2 * a);
        cout << " Two Real Roots:\n";
        cout << "   x1 = " << x1 << "\n";
        cout << "   x2 = " << x2 << "\n";

    } else if (disc == 0) {
        // ✅ One repeated real root
        double x = -b / (2 * a);
        cout << " One Repeated Real Root:\n";
        cout << "   x = " << x << "\n";

    } else {
        // ✅ Complex roots — disc < 0, use complex<double>
        // Formula: x = (-b ± sqrt(disc)) / 2a
        // sqrt of negative number → use complex<double>

        complex<double> sqrtDisc = sqrt(complex<double>(disc));   // sqrt(-ve) gives imaginary
        complex<double> x1 = (complex<double>(-b) + sqrtDisc) / complex<double>(2 * a);
        complex<double> x2 = (complex<double>(-b) - sqrtDisc) / complex<double>(2 * a);

        cout << " Complex Roots:\n";
        cout << "   x1 = " << x1.real() << " + " << x1.imag() << "i\n";
        cout << "   x2 = " << x2.real() << " - " << abs(x2.imag()) << "i\n";
    }
}