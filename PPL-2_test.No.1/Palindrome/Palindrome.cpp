#include "Palindrome.h"
#include <cctype>
using namespace std;

Palindrome::Palindrome(const string& text) {
    this->text = text;
}

bool Palindrome::isPalindrome() const {
    string cleaned = "";
    for (char ch : text) {
        if (!isspace(ch)) {
            cleaned += tolower(ch);
        }
    }
    int left = 0;
    int right = cleaned.length() - 1;

    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}