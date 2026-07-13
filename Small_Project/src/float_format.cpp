#include "float_format.h"

std::string formatFloat(const std::string& input) {
    size_t dot = input.find('.');
    std::string F = input.substr(0, dot);
    std::string I = input.substr(dot + 1);

    size_t s = I.find_first_not_of('0');
    std::string G = (s == std::string::npos) ? "" : I.substr(s);

    size_t e = F.find_last_not_of('0');
    std::string J = (e == std::string::npos) ? "0" : F.substr(0, e + 1);

    int hashes = 5 - (int)G.size();
    std::string H(hashes, '#');

    return G + H + "." + J + "\n";
}