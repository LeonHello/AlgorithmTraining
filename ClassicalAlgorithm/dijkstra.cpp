#include <iostream>
#define INF 1 << 30
#define MAXN 505
using namespace std;

int edges[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];
int N, M;

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            if (i == j)
                edges[i][j] = 0;
            else
                edges[i][j] = INF;
        }
    }
    for (int i = 0; i < MAXN; i++)
    {
        dist[i] = INF;
        vis[i] = false;
    }
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        edges[s][e] = cost;
    }
}

int dijkstra(int s, int e)
{
    dist[s] = 0;
    for (int i = 1; i <= N; i++)
    {
        int min = INF;
        int x = -1;
        for (int j = 1; j <= N; j++)
        {
            if (!vis[j] && dist[j] < min)
            {
                min = dist[j];
                x = j;
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
    return dist[e];
}

int main()
{
    init();
    cout << dijkstra(1, 4) << endl;
    return 0;
}