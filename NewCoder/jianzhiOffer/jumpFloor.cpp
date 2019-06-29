#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int jumpFloor(int number) {
    if (number <= 0) {
        return number;
    }
    number++;
    int a = 0; 
    int b = 1;
    while(number--) {
        b = b + a;
        a = b - a;
    }
    return a;
}
int JumpFloorII(int number) {
    // return pow(2, number - 1);
    if (number == 1) {
        return 1;
    }
    else {
        return 2 * JumpFloorII(number - 1);
    }    
}

int rectCover(int number) {
    if (number <= 0) {
        return number;
    }
    int f1 = 1;
    int f2 = 2;
    int f3;
     
    for (int i = 3; i <= number; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}
//0 1 1 2 3 5
//1 2 3 5 8 13
int main() {
    cout<<rectCover(5)<<endl;
    return 0;
}