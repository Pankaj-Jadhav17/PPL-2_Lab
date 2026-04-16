#include "GCDLCM.h"

using namespace std;

// Constructor
GCDLCM::GCDLCM(int a, int b) {
    this->a = a;
    this->b = b;
}

// Euclid's Algorithm
int GCDLCM::findGCD() const {
    int x = a;
    int y = b;

    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// LCM formula
int GCDLCM::findLCM() const {
    int gcd = findGCD();
    return (a * b) / gcd;
}