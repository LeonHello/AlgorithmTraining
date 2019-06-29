#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
    stack<int> stackT, stackMin;
public:
    void push(int value) {
        stackT.push(value);
        if(stackMin.empty())
            stackMin.push(value);
        else if(value <= stackMin.top())
            stackMin.push(value);
    }
    void pop() {
        if(stackT.top() == stackMin.top()) 
            stackMin.pop();
        stackT.pop();
    }
    int top() {
        return stackT.top();
    }
    int min() {
        return stackMin.top();
    }
};

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> res;
    int row = matrix.size();
    int col = matrix[0].size();
         
    // 输入的二维数组非法，返回空的数组
    if (row == 0 || col == 0)  return res;
     
    // 定义四个关键变量，表示左上和右下的打印范围
    int left = 0, top = 0, right = col - 1, bottom = row - 1;
    while (left <= right && top <= bottom)
    {
        // left to right
        for (int i = left; i <= right; ++i)  
            res.push_back(matrix[top][i]);
        // top to bottom
        for (int i = top + 1; i <= bottom; ++i)  
            res.push_back(matrix[i][right]);
        // right to left
        if (top < bottom)
            for (int i = right - 1; i >= left; --i)  
                res.push_back(matrix[bottom][i]);
        // bottom to top
        if (left < right)
            for (int i = bottom - 1; i > top; --i)  
                res.push_back(matrix[i][left]);
        left++, top++, right--, bottom--;
    }
    return res;
}

int main() {
    return 0;
}