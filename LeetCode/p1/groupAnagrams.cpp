#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector< vector<string> > groupAnagrams(vector<string>& strs) {
    vector< vector<string> > ans;
    map< string, vector<string> > temp;
    for(int i = 0; i < strs.size(); i++){
        string j = strs[i];
        sort(j.begin(), j.end());
        temp[j].push_back(strs[i]); 
    }
    for(map<string, vector<string> >::iterator i = temp.begin(); i != temp.end(); i++){
        ans.push_back(i->second);
    }
    return ans;
}

int main(){
    string s[6] = {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs(s, s+6);
    vector< vector<string> >  ans = groupAnagrams(strs);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
    }
    return 0;
}