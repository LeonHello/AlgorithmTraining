#include <iostream>
using namespace std;
int integerBreak(int n)
{
    /*
    2 ret 1
    3 ret 2
    4 ret 2*2
    5 ret 3*2
    6 ret 3*3
    7 ret 3*2*2
    8 ret 3*3*2
    9 ret 3*3*3
    10 ret 3*3*2*2
    */
    if (n < 4)
        return n - 1;
    if(n == 4)return 4;
    if(n == 5)return 6;
    if(n == 6)return 9;
    return 3*integerBreak(n - 3);
}

int main(int argc, char *argv[])
{
    cout<<integerBreak(10)<<endl;
    return 0;
}