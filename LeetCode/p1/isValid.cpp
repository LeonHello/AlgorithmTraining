#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> a;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') 
            a.push(s[i]);
        else if(s[i] == ')') {
            if(!a.empty()) {
                char temp = a.top();
                if(temp == '(')
                    a.pop();
                else return false;
            }
            else return false;
        }
        else if(s[i] == '}') {
            if(!a.empty()) {
                char temp = a.top();
                if(temp == '{')
                    a.pop();
                else return false;
            }
            else return false;
        }
        else if(s[i] == ']') {
            if(!a.empty()) {
                char temp = a.top();
                if(temp == '[')
                    a.pop();
                else return false;
            }
            else return false;
        }
    }    
    if(a.empty())
        return true;
    else
        return false;
}
int main(){
    string s = "{[}]()";
    cout<<isValid(s)<<endl;
    return 0;
}