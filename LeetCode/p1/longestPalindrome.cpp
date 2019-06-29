#include<iostream>
using namespace std;
string longestPalindrome(string s) {
    int len = s.length();
    int ans = 1;
    string strans = s.substr(0, 1);
    //to find odd length of the answer
    for(int i = 0; i < len; i++){
        int temp = 1;
        int p = i - 1;
        int q = i + 1;
        while(p >= 0 && q < len){
            if(s[p] == s[q]){
                p--;
                q++;
                temp += 2;
            }else break;
        }
        if(temp > ans){
            ans = temp;
            strans = s.substr(p + 1, temp);
        }
    }
    
    //to find even length of the answer
    for(int i = 0; i < len; i++){
        int temp = 0;
        int p = i;
        int q = i + 1;
        while(p >= 0 && q < len){
            if(s[p] == s[q]){
                p--;
                q++;
                temp += 2;
            }else break;
        }
        if(temp > ans){
            ans = temp;
            strans = s.substr(p + 1, temp);
        }
    }

    return strans;
}

int main(){
    string s = "a";
    cout<<longestPalindrome(s)<<endl;
}