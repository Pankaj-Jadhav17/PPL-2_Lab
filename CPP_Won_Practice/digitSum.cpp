#include<iostream>
using namespace std;
int digitSum(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return (sum > 9) ? digitSum(sum) : sum;
}
int main(){
    long long n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<digitSum(n)<<endl;
}
