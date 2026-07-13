#pragma once
#include <string>

struct FileStats {
    int lines, words, characters, sentences;
};

FileStats analyzeFile(const std::string& filename);

