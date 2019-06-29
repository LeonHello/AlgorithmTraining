#include<iostream>
using namespace std;
string convert(string s, int numRows) {
    int numOfGroup = numRows * 2 - 2;
    int len = s.length();
    int group = len / numOfGroup;
    int yushu = len - group * numOfGroup;

}
/*
string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
*/
int main(){

}