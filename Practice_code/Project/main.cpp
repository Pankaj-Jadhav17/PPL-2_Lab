#include <iostream>
#include <string>
#include <fstream>
#include "base_conversion.h"
#include "float_format.h"
#include "file_stats.h"
#include "conic.h"
#include "fraction.h"

static void runQ1() {
    long long num; int base;
    std::cout << "Enter number and base: ";
    std::cin >> num >> base;
    std::cout << convertBase(num, base) << "\n";
}

static void runQ2() {
    std::string input;
    std::cout << "Enter number in F.I format: ";
    std::cin >> input;
    std::cout << formatFloat(input);
}

static void runQ3() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    FileStats s = analyzeFile(filename);
    if (s.characters == 0 && s.lines == 0) {
        std::cout << "File not found or empty.\n";
        return;
    }
    std::cout << "number of lines : " << s.lines << "\n";
    std::cout << "number of words: " << s.words << "\n";
    std::cout << "number of characters: " << s.characters << "\n";
    std::cout << "number of sentences: " << s.sentences << "\n";
}

static void runQ4() {
    double a, b, c, h, g, f;
    std::cout << "Enter a b c h g f: ";
    std::cin >> a >> b >> c >> h >> g >> f;
    std::cout << classifyConic(a, b, c, h, g, f) << "\n";
}

static void runQ5() {
    std::string input;
    std::cout << "Enter number in I.F format: ";
    std::cin >> input;
    printFraction(input);
}

int main() {
    int choice;
    std::cout << "Select Question:\n";
    std::cout << "1. Base Conversion\n";
    std::cout << "2. Float Format (F.I)\n";
    std::cout << "3. File Statistics\n";
    std::cout << "4. Conic Section Classifier\n";
    std::cout << "5. Fraction Converter\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: runQ1(); break;
        case 2: runQ2(); break;
        case 3: runQ3(); break;
        case 4: runQ4(); break;
        case 5: runQ5(); break;
        default: std::cout << "Invalid choice.\n";
    }
    return 0;
}