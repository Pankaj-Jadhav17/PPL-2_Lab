#include<iostream>
#include "Triangle.h"

using namespace std;

int main()
{
    double a,b,c;

    cout<<"Please enter the 3 valid sides of the triangle\n";

    cin>>a;
    cin>>b;
    cin>>c;

    cout<<"\nYou entered "<<a<<", "<<b<<", "<<c<<endl;

    Triangle t(a,b,c);

    t.displaySides();
    t.triangleType();
    t.internalAngles();
    t.area();
    t.angleProperty();
    t.assignVertices();

    return 0;
}