#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int Pattern5(int n){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                cout << i <<"";
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
    obj.Pattern5(n);
    return 0;
}