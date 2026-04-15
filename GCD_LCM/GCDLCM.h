#ifndef GCDLCM_H
#define GCDLCM_H

class GCDLCM {
private:
    int a, b;
public:
    GCDLCM(int a, int b);
    int findGCD() const;
    int findLCM() const;
};
#endif