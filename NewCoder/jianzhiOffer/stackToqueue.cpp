#include<iostream>
#include<stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        //栈1入队
        stack1.push(node);
    }

    int pop() {
        //栈2出队
        if(stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ans = stack2.top();
        stack2.pop();
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution a;
    a.push(1);
    a.push(2);
    cout<<a.pop()<<a.pop()<<endl;
    return 0;
}