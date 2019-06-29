#include<iostream>
using namespace std;

int Fibonacci(int n) {
    int a = 0; 
    int b = 1;
    while(n--) {
        b = b + a;
        a = b - a;
    }
    return a;
}

int main() {
    // 0 1 1 2 3 5
    cout<<Fibonacci(5)<<endl;
    return 0;
}