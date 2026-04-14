#include"Factor.h"
#include<cmath>
Factor::Factor(double a, double b, double c){
    this->a = a;
    this->b = b;
    this->c = c;
}
void Factor::computeRoots(){
    complex<double> discriminant = (b*b - 4.0*a*c);
    z1 = (-b + sqrt(discriminant)) / (2.0*a);
    z2 = (-b - sqrt(discriminant)) / (2.0*a);
}
void Factor::printFactorization(){
    cout<<"(";
     if(real(z1) != 0)
        cout<<"x+"<<z1;
        else
        cout<<"x"<<z1;
    cout<<")(";
        if(real(z2) != 0)
        cout<<"x+"<<z2;
        else        
        cout<<"x"<<z2;
    cout<<")"<<endl;
}
