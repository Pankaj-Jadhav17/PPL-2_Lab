#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int accessCharacter(string s){
        for(int i=0; i<s.size(); i++){
            cout << s[i] << endl;
        }
        return 0;
    }
};

int main(){
    solution is_object;
    string s = "Hello World";
    is_object.accessCharacter(s);
    return 0;
}