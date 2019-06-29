#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    //1 2 3 4 5
    //4 3 5 1 2
    //4 3 5 2 1
    if(pushV.size() == 0) return false;
    stack<int> s;
    int j = 0;
    for(int i = 0; i < pushV.size(); ++i) {
        s.push(pushV[i]);
        while(!s.empty() && s.top() == popV[j]) {
            s.pop();
            j++;
        }
    }
    return s.empty();
}

int main() {
    return 0;
}