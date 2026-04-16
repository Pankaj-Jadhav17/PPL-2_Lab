#include <iostream>
#include "GCDLCM.h"
using namespace std;

int main() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0) {
        cout << "Please enter positive integers only." << endl;
        return 0;
    }
    GCDLCM obj(a, b);
    cout << "GCD: " << obj.findGCD() << endl;
    cout << "LCM: " << obj.findLCM() << endl;
    return 0;
}