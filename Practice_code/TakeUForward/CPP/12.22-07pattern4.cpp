#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int Pattern4(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==n-1 || j==0 || j==n-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        return 0;
    }
};

int main(){
    solution obj;
    int n;
    cout<<"Enter the number of rows and columns:";
    cin>>n;
    obj.Pattern4(n);
    return 0;
}