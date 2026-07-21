#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int Pattern3(int n){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                cout << j << " ";
            }
            cout << endl;
        }
        return 0;
    }
};

int main(){
    solution obj;
    int n;
    cout << "Enter the number of rows and columns: ";
    cin >> n;
    obj.Pattern3(n);
    return 0;
}