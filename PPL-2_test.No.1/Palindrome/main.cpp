#include <iostream>
#include "Palindrome.h"
using namespace std;

int main() {
    string input;
    cout << "Enter text: ";
    getline(cin, input);
    Palindrome obj(input);
    if (obj.isPalindrome()) {
        cout << "Output: Palindrome!" << endl;
    } else {
        cout << "Output: No." << endl;
    }
    return 0;
}