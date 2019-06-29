#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int len = strs.size();
    string ans = "";
    if(len == 0) return ans;
    if(len == 1) return strs[0];
    int minLen = strs[0].length();
    for(int i = 1; i < len; i++){
        minLen = minLen > strs[i].length() ? strs[i].length() : minLen;
    }
    if(minLen == 0) return ans;
    int k = 0;
    while(k < minLen && strs[0][k] == strs[1][k]){
        k++;
    }
    ans = strs[0].substr(0, k);
    for(int i = 2; i < len; i++){
        int j = 0;
        while(j < minLen && strs[i][j] == ans[j]){
            j++;
        }
        ans = strs[i].substr(0, j);
    }
    return ans;
}

int main(){
    string arr[2] = {"c", "c"};
    vector<string> strs(arr, arr + 2);
    cout<<longestCommonPrefix(strs)<<endl;
}