#include "fraction.h"
#include <iostream>
#include <cmath>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void printFraction(const std::string& input) {
    size_t dot = input.find('.');
    long long I = std::stoll(input.substr(0, dot));
    std::string F_str = input.substr(dot + 1);

    long long N = std::stoll(F_str);
    long long D = 1;
    for (char ch : F_str) { (void)ch; D *= 10; }

    if (N == 0) {
        std::cout << I << "\n";
        return;
    }

    long long g = gcd(N, D);
    N /= g; D /= g;

    if (I == 0)
        std::cout << N << " / " << D << "\n";
    else
        std::cout << I << " + " << N << " / " << D << "\n";
}