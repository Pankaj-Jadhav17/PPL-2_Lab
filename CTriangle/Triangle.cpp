#include<iostream>
#include<cmath>
#include "Triangle.h"

using namespace std;

Triangle::Triangle(double x,double y,double z)
{
    a=x;
    b=y;
    c=z;
}

void Triangle::displaySides()
{
    cout<<"\nThe sides are: "<<a<<", "<<b<<", "<<c<<endl;
}

void Triangle::triangleType()
{
    if(a==b && b==c)
        cout<<"\nThis is an equilateral triangle\n";

    else if(a==b || b==c || a==c)
        cout<<"\nThis is an isosceles triangle\n";

    else
        cout<<"\nThis is a scalene triangle\n";
}

void Triangle::internalAngles()
{
    double A,B,C;

    A = acos((b*b+c*c-a*a)/(2*b*c))*180/M_PI;
    B = acos((a*a+c*c-b*b)/(2*a*c))*180/M_PI;
    C = acos((a*a+b*b-c*c)/(2*a*b))*180/M_PI;

    cout<<"\nIts internal angles are: (in degrees) "
        <<A<<", "<<B<<", "<<C<<endl;
}

void Triangle::area()
{
    double s=(a+b+c)/2;

    double ar=sqrt(s*(s-a)*(s-b)*(s-c));

    cout<<"\nIts area is "<<ar<<" sq. units"<<endl;
}

void Triangle::angleProperty()
{
    if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
    {
        cout<<"\nThis triangle is right angled.\n";
        cout<<"\nThis triangle does not have an obtuse angle.\n";
    }

    else if(a*a + b*b < c*c || a*a + c*c < b*b || b*b + c*c < a*a)
    {
        cout<<"\nThis triangle is obtuse angled.\n";
    }

    else
    {
        cout<<"\nThis triangle is acute angled.\n";
    }
}

void Triangle::assignVertices()
{
    cout<<"\nWe may assign the following vertices in X-Y plane:\n";

    cout<<"(0,0) (0,"<<b<<") ("<<a<<","<<b/2<<")\n";
}