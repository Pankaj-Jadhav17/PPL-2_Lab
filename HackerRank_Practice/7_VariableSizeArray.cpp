#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        vector<int> temp;
        for(int j=0;j<k;j++){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    for(int i=0; i<q; i++){
        int row,col;
        cin >> row >> col;
        cout<<arr[row][col] <<endl;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    // Complete this function  
    int sum = *a + *b;
    int diff = abs(*a - *b);
    
    *a = sum;
    *b = diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
