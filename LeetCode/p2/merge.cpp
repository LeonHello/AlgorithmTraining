#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > merge(vector<vector<int> > &intervals)
{
    vector<vector<int> > res;
    int len = intervals.size();
    if (len == 0)
        return res;
    for (int i = len - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (intervals[j][0] > intervals[j + 1][0])
            {
                int t = intervals[j][0];
                intervals[j][0] = intervals[j + 1][0];
                intervals[j + 1][0] = t;
                t = intervals[j][1];
                intervals[j][1] = intervals[j + 1][1];
                intervals[j + 1][1] = t;
            }
        }
    }
    int cur = 0;
    vector<int> t;
    t.push_back(intervals[0][0]);
    t.push_back(intervals[0][1]);
    res.push_back(t);
    for (int i = 1; i < len; i++)
    {
        if (res[cur][1] >= intervals[i][0])
        {
            if (res[cur][1] <= intervals[i][1])
            {
                res[cur][1] = intervals[i][1];
            }
        }
        else
        {
            cur++;
            t[0] = intervals[i][0];
            t[1] = intervals[i][1];
            res.push_back(t);
        }
    }
    return res;
}
int main(int argc, char *argv[])
{
    return 0;
}