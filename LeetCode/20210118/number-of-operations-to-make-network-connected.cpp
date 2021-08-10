#include <bits/stdc++.h>
using namespace std;
class UFset
{
public:
    vector<int> fa;
    vector<int> rank;
    int setCnt;
    UFset(int n)
    {
        fa = vector<int>(n, 0);
        rank = vector<int>(n, 1);
        setCnt = n;
        for (int i = 0; i < n; i++)
        {
            fa[i] = i;
        }
    }
    int find(int x)
    {
        return x == fa[x] ? fa[x] : (fa[x] = find(fa[x]));
    }
    void merge(int x, int y)
    {
        int xx = find(x);
        int yy = find(y);
        if (xx != yy)
        {
            setCnt--;
            if (rank[xx] <= rank[yy])
                fa[xx] = yy;
            else
                fa[yy] = xx;
            if (rank[xx] == rank[yy])
                rank[yy]++;
        }
    }
};
class Solution
{
public:
    int makeConnected(int n, vector<vector<int> > &connections)
    {
        int size = connections.size();
        if (size < n - 1)
            return -1;
        UFset ufset(n);
        for (int i = 0; i < size; i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            ufset.merge(a, b);
        }
        return ufset.setCnt - 1;
    }
};
int main(int argc, char *argv[])
{
    int n = 5;
    vector<vector<int> > connections(4, vector<int>(2, 0));
    connections[0][0] = 0;
    connections[0][1] = 1;

    connections[1][0] = 0;
    connections[1][1] = 2;

    connections[2][0] = 3;
    connections[2][1] = 4;

    connections[3][0] = 2;
    connections[3][1] = 3;
    
    Solution s;
    cout << s.makeConnected(n, connections) << endl;
    return 0;
}