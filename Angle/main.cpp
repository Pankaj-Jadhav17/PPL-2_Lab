#include <iostream>
#include "Angle.h"
using namespace std;

int main() {
    double x1, y1, x2, y2;
    
    cout << "Enter coordinates of A (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates of B (x2 y2): ";
    cin >> x2 >> y2;

    Angle obj(x1, y1, x2, y2);

    double result = obj.computeAngle();

    cout << "Angle AOB: " << result << " deg" << endl;

    return 0;
}