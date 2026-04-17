#include "SymmetricDate.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Check leap year
bool isLeap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Validate date
bool SymmetricDate::isValidDate(int d, int m, int y) const {
    if (m < 1 || m > 12) return false;
    if (d < 1) return false;

    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (isLeap(y)) daysInMonth[1] = 29;

    return d <= daysInMonth[m - 1];
}

// Find symmetric dates
void SymmetricDate::findDates() const {
    for (int year = 2001; year <= 2100; year++) {

        int y = year;

        // Reverse year to get DDMM
        int d1 = y % 10; y /= 10;
        int d2 = y % 10; y /= 10;
        int d3 = y % 10; y /= 10;
        int d4 = y % 10;

        int day = d1 * 10 + d2;
        int month = d3 * 10 + d4;

        if (isValidDate(day, month, year)) {
            cout << setw(2) << setfill('0') << day << "-"
                 << setw(2) << setfill('0') << month << "-"
                 << year << endl;
        }
    }
}