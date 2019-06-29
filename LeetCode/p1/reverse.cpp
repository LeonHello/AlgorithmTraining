#include<iostream>
using namespace std;
int reverse(int x){
    int ans = 0;
    while(x != 0){
        int pop = x % 10;
        x /= 10;
        if(ans > INT32_MAX / 10 || (ans == INT32_MAX / 10 && pop > 7))
            return 0;
        if(ans < INT32_MIN/10 || (ans == INT32_MIN / 10 && pop < -8))
            return 0;
        ans = ans * 10 + pop;
    }
    return ans;
}

void test(int *b){
    *b = 10;
}
int main(){
    int x = 100;
    int y[5] = {1,2,3,4,5};
    test(y);
    cout<<y[1]<<endl;
}