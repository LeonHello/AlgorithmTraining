#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int kthSmallest1(vector<vector<int> > &matrix, int k)
{
    priority_queue<int, vector<int>, less<int> > q;
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            q.push(matrix[i][j]);
            if (q.size() > k)
                q.pop();
        }
    return q.top();
}
int kthSmallest(vector<vector<int> > &matrix, int k)
{
    int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix[n - 1][n - 1];
    int mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < n; ++i)
        {
            vector<int> ma = matrix[i];
            c1 += lower_bound(ma.begin(), ma.end(), mid) - ma.begin();
            c2 += upper_bound(ma.begin(), ma.end(), mid) - ma.begin();
        }
        if (k > c1 && k <= c2)
            return mid;
        else if (k > c2)
            l = ++mid;
        else
            r = --mid;
    }
    return mid;
}

int main()
{
    return 0;
}