// To determine the length of a string, we can use the size or length function. These functions return the 
// number of characters in the string. For example, if we have s as our string, you can find its length like 
// this:
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int findLength(string s){
        return s.size();
    }

};


int main(){
    solution is_object;
    string s = "Hello World";
    cout << is_object.findLength(s) << endl;
    return 0;
}