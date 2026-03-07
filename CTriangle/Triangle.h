#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
private:
    double a,b,c;

public:

    Triangle(double,double,double);

    void displaySides();
    void triangleType();
    void internalAngles();
    void area();
    void angleProperty();
    void assignVertices();
};

#endif