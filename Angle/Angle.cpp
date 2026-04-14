#include "Angle.h"
#include <cmath>
using namespace std;

// Constructor
Angle::Angle(double x1, double y1, double x2, double y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

double Angle::computeAngle() const {
    double dot = x1 * x2 + y1 * y2;

    double magA = sqrt(x1 * x1 + y1 * y1);
    double magB = sqrt(x2 * x2 + y2 * y2);
    double cosTheta = dot / (magA * magB);

    if (cosTheta > 1) cosTheta = 1;
    if (cosTheta < -1) cosTheta = -1;

    double angleRad = acos(cosTheta);

    // Convert to degrees
    double angleDeg = angleRad * (180.0 / M_PI);
    return angleDeg;
}