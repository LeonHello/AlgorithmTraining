#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<string> generateParenthesis(int n) {
    char chg[2 * n + 1];
    chg[2*n] = '\0';
    for(int i = 0; i < n; i++){
        chg[i] = '(';
        chg[2 * n - i - 1] = ')';
    }
    string all[100000];
    int j = 0;
    do{ 
        //check is Valid or Not
        stack<char> temp;
        int i = 0;
        for(; i < 2*n; i++){
            if(chg[i] == '('){
                temp.push(chg[i]);
            }
            if(chg[i] == ')'){
                if(!temp.empty())
                    temp.pop();
                else 
                    break;
            }
        }
        if(i == 2*n){
            all[j] = chg;
            j++;
        }
    }while(next_permutation(chg, chg + 2 * n));  
    vector<string> ans(all, all + j);
    return ans;
}

int main(){
    vector<string> s = generateParenthesis(4);
    for(int i = 0; i < s.size(); i++){
        cout<<s[i]<<endl;
    }
    return 0;
}