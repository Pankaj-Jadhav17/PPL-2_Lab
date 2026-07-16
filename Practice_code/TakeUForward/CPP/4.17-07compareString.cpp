#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int compareString(string s1, string s2){
       return s1 == s2;
    }
};
int main(){
    solution Obj;
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    if(Obj.compareString(s1, s2))
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;
    return 0;
}