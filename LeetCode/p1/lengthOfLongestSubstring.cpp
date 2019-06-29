#include<iostream>
#include<map>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int length = s.length();
    int ans = 0;
    map<char, int> mp;
    map<char, int>::iterator iter;
    //to find the longest part of the string [i, j]
    int i = 0;
    for(int j = 0; j < length; j++){
        iter = mp.find(s[j]);
        if(iter != mp.end()){
            i = max(iter->second, i);
        }
        ans = max(j - i + 1, ans);
        mp[s[j]] = j + 1;
    }
    return ans;
}
int main(){
    string s = "pwwkew";
    //j = 0; p 1  ans = 1
    //j = 1; w 2  ans = 2
    //j = 2; i = 0->2 ans = 2 ; w 3
    //j = 3; k 4;
    //j = 4; e 5;
    //j = 5; i = 2->3 ans = 3; w 6
    cout<<lengthOfLongestSubstring(s)<<endl;
}