#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Pattern1(int n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter the number of rows and columns: ";
    cin >> n;

    obj.Pattern1(n);

    return 0;
}