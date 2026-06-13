#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    long long l;
    char ch;
    float f;
    double d;

    cin >> n >> l >> ch >> f >> d;

    cout << n << endl;
    cout << l << endl;
    cout << ch << endl;
    cout << fixed << setprecision(3) << f << endl;
    cout << fixed << setprecision(9) << d << endl;

    return 0;
}
