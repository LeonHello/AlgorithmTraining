#include<iostream>
using namespace std;
bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int ans = 0;
    while(x > ans){
        int pop = x % 10;
        x /= 10;
        ans = ans * 10 + pop;
    }
    return x == ans || x == ans / 10;
}

int main(){
    int x = 1000001;
    cout<<isPalindrome(x)<<endl;
}