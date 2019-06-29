#include <iostream>
using namespace std;
// 1. 字母和字母    p[j] == s[i]: dp[i][j] = dp[i-1][j-1]
// 2. 字母和点号    p[j] == '.':  dp[i][j] = dp[i-1][j-1]
// 3. 字母和星号    p[j] == '*':
//     3.1 p[j-1] != s[i]:  dp[i][j] = dp[i][j-2]
//     3.2 p[j-1] == s[i] or p[j-1] == '.':
//              dp[i][j] = (dp[i-1][j] || dp[i][j-1] || dp[i][j-2])
bool isMatch1(string s, string p)
{
    int slen = s.length();
    int plen = p.length();
    bool dp[slen + 1][plen + 1];
    dp[0][0] = true;
    for (int i = 0; i < slen; ++i)
    {
        for (int j = 0; j < plen; ++j)
        {
            if (p[j] == s[i] || p[j] == '.')
                dp[i + 1][j + 1] = dp[i][j];
            if (p[j] == '*')
            {
                if (p[j - 1] != s[i])
                    dp[i + 1][j + 1] = dp[i + 1][j - 1];
                if (p[j - 1] == s[i] || p[j - 1] == '.')
                {
                    dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1]);
                }
            }
        }
    }
    return dp[slen][plen];
}
bool isMatch(string s, string p)
{
    int plen = p.length();
    int slen = s.length();

    if (!plen)
        return slen == 0;

    bool first_match = slen && (s[0] == p[0] || p[0] == '.');

    if (plen >= 2 && p[1] == '*')
    {
        return isMatch(s, p.substr(2, plen - 2)) ||
               (first_match && isMatch(s.substr(1, slen - 1), p));
    }
    else
    {
        return first_match && isMatch(s.substr(1, slen - 1), p.substr(1, plen - 1));
    }
}
int main(int argc, char **argv)
{
    string s = "aaa";
    string p = "aaaa";
    cout << isMatch(s, p) << endl;
    return 0;
}