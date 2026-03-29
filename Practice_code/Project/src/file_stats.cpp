
#include "file_stats.h"
#include <fstream>
#include <cctype>

FileStats analyzeFile(const std::string& filename) {
    FileStats stats = {0, 0, 0, 0};
    std::ifstream file(filename);
    if (!file.is_open()) return stats;

    char c;
    bool inWord = false;
    char last = '\n';

    while (file.get(c)) {
        stats.characters++;
        last = c;

        if (c == '\n') {
            stats.lines++;
            inWord = false;
        } else if (std::isspace(c)) {
            inWord = false;
        } else {
            if (!inWord) stats.words++;
            inWord = true;
        }

        if (c == '.' || c == '!' || c == '?') stats.sentences++;
    }

    if (stats.characters > 0 && last != '\n') stats.lines++;

    return stats;
}