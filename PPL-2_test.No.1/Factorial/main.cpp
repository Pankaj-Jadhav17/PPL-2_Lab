#include"Factor.h"
#include<iostream>
using namespace std;

int main(){
    double a,b,c;
    cout<<"Enter a,b,c : ";
    cin>>a>>b>>c;
    Factor f(a,b,c);
    f.computeRoots();
    f.printFactorization();
    return 0;
}