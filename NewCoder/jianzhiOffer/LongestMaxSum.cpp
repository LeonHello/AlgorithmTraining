#include<iostream>
using namespace std;
int LongestMaxSum(int a[], int size) {
    int MaxSum = 0;
    for(int i = 0; i < size; i++) {
        int ThisSum = 0;
        for(int j = i; j < size; j++) {
            ThisSum += a[j];
            if(ThisSum > MaxSum) 
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) 
        cin>>a[i];
    cout<<LongestMaxSum(a, n)<<endl;
    return 0;
}