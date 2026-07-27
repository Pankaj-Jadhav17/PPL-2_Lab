#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int Pattern8(int n){
        for(int i=0; i<n; i++){
            for(int j=n; j>i; j--){
                cout<<n-j+1<<"";
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
    obj.Pattern8(n);
    return 0;
}
