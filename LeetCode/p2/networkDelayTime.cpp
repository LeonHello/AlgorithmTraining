#include <iostream>
#include <vector>
using namespace std;

int MAXN = 105;
int INF = (1 << 30);
int networkDelayTime(vector<vector<int> > &times, int N, int K)
{
    //init
    int edges[MAXN][MAXN];
    int dist[MAXN];
    bool vis[MAXN];
    for (int i = 0; i < MAXN; i++)
    {
        dist[i] = INF;
        vis[i] = false;
    }

    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            edges[i][j] = INF;
        }
    }

    for (int k = 0; k < times.size(); k++)
    {
        int i = times[k][0];
        int j = times[k][1];
        edges[i][j] = times[k][2];
    }

    //dj
    dist[K] = 0;
    for (int i = 1; i <= N; i++)
    {
        int x = K;
        int min = (1 << 20);
        for (int j = 1; j <= N; j++)
        {
            if (!vis[j] && dist[j] < min)
            {
                x = j;
                min = dist[j];
            }
        }

        vis[x] = true;

        for (int j = 1; j <= N; j++)
        {
            if (!vis[j] && dist[j] > dist[x] + edges[x][j])
            {
                dist[j] = dist[x] + edges[x][j];
            }
        }
    }

    //寻找最大的路径
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
            return -1;
        if (dist[i] > max)
            max = dist[i];
    }
    return max;
}
int main(int argc, char *argv[])
{
    vector<vector<int> > times;
    vector<int> t1;
    t1.push_back(2);
    t1.push_back(1);
    t1.push_back(1);
    times.push_back(t1);
    vector<int> t2;
    t2.push_back(2);
    t2.push_back(3);
    t2.push_back(1);
    times.push_back(t2);
    vector<int> t3;
    t3.push_back(3);
    t3.push_back(4);
    t3.push_back(1);
    times.push_back(t3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << times[i][j] << " ";
        }
        cout << endl;
    }
    cout << networkDelayTime(times, 4, 2) << endl;
    return 0;
}