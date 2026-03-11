#include "QuadraticRootFinder.h"
#include <iostream>
using namespace std;

int main() {
    double a, b, c;

    cout << "=== Quadratic Root Finder ===\n";
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    cout << "Enter c: "; cin >> c;

    QuadraticRootFinder solver(a, b, c);
    solver.solve();

    return 0;
}