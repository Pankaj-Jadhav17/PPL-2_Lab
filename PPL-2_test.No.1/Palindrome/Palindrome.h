#ifndef PALINDROME_H
#define PALINDROME_H
#include <string>

class Palindrome {
private:
    std::string text;
public:
    Palindrome(const std::string& text);
    bool isPalindrome() const;
};
#endif