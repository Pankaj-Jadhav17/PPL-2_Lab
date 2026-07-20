#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int ForLoop(int low, int high){
        int sum = 0;
        for(int i=low; i<=high; i++){
            sum += i;
            // int sum = (high * (high + 1) / 2) - ((low - 1) * low / 2);
        }
        return sum;
    }
};

int main(){
    solution Obj;
    int low, high;
    cout << "Enter low and high calues:";
    cin >> low >> high;
    cout<<"Sum of numbers from " << low << " to " << high << " is: " << Obj.ForLoop(low, high) << endl;
}