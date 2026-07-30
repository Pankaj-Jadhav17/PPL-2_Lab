#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int Pattern10(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                cout<<" ";
            }
            for(int j = 0; j < 2*n-(2*i+1); j++){
                cout<<"*";
            }
            for(int j=0; j<i; j++){
                cout<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
};

int main(){
    solution obj;
    int n;
    cout<<"Enter a size of matrix: ";
    cin >> n;
    obj.Pattern10(n);
    return 0;
}