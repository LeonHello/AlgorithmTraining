#include<iostream>

using namespace std;
char ops[] = {'+', '-', '*', '/'};
const int INF = 1 << 20;
int cnt(0);

int cal(int num1, int num2, int s) {
    switch (s) {
        case 0 :
            return num1 + num2;
        case 1 :
            return num1 - num2;
        case 2 :
            return num1 * num2;
        case 3 :
            if (num2 == 0 || num1 % num2 != 0)
                return INF;
            return num1 / num2;
        case 4 :
            return num2 - num1;
        case 5 :
            if (num1 == 0 || num2 % num1 != 0)
                return INF;
            return num2 / num1;
    }
    return 0;
}

void solve(string s[], int num[], int deep) {
    if (deep == 2) {
        for (int i = 0; i < 4; ++i)
            if (cal(num[0], num[1], i) == 24)
                cout << s[0].c_str() << ops[i] << s[1].c_str() << endl, cnt++;
        if (cal(num[0], num[1], 4) == 24)
            cout << s[1].c_str() << "-" << s[0].c_str() << endl, cnt++;
        if (cal(num[0], num[1], 5) == 24)
            cout << s[1].c_str() << "/" << s[0].c_str() << endl, cnt++;
        return;
    }
    for (int i = 0; i < deep; ++i)
        for (int j = i + 1; j < deep; ++j) {
            int now = 0;
            int next_num[deep - 1];
            string next_s[deep - 1];
            for (int k = 0; k < deep; ++k) {
                if (k != i && k != j) {
                    next_num[now] = num[k];
                    next_s[now++] = s[k];
                }
            }
            for (int k = 0; k < 4; ++k) {
                next_num[now] = cal(num[i], num[j], k);
                next_s[now] = '(' + s[i] + ops[k] + s[j] + ')';
                solve(next_s, next_num, deep - 1);
            }

            next_num[now] = cal(num[i], num[j], 4);
            next_s[now] = '(' + s[j] + '-' + s[i] + ')';
            solve(next_s, next_num, deep - 1);
            next_num[now] = cal(num[i], num[j], 5);
            next_s[now] = '(' + s[j] + '/' + s[i] + ')';
            solve(next_s, next_num, deep - 1);
        }
    return;
}

int main() {
    int num[4];
    string s[4];
    cout << "请输入四个1到13的数字: " << endl;
    for (int i = 0; i < 4; ++i) {
        cin >> num[i];
        s[i] += (num[i] + '0');
    }
    solve(s, num, 4);
    cout << endl << "解法总数: " << cnt << endl;
    return 0;
}