#include "base_conversion.h"

std::string convertBase(long long num, int base) {
    if (num == 0) return "0";
    const char digits[] = "0123456789ABCDEF";
    std::string result;
    while (num > 0) {
        result = digits[num % base] + result;
        num /= base;
    }
    return result;
}