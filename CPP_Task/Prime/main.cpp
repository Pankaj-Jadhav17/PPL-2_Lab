#include "Prime.hpp"
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Prime obj(n);
    if (obj.isPrime()) {
        cout << "Output: Prime number" << endl;
    } else {
        cout << "Output: Not a prime number" << endl;
    }
    return 0;
}