#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int Pattern6(int n){
        for(int i=0; i<=n-1; i++){
            for(int j=0; j<i+1; j++){
                cout<<"*";
            }
            cout<<endl;
        }
        return 0;
    }
};

int main(){
    solution obj;
    int n;
    cout<<"Enter a array size";
    cin>>n;
    obj.Pattern6(n);
    return 0;
}