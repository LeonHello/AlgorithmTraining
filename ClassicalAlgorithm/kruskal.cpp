#include<iostream>

#define INF 1 << 30
#define MAXN 50
using namespace std;

typedef struct {
    int s, e, w;
} edg;

bool cmp(edg a, edg b) {
    return a.w < b.w;
}

edg edges[MAXN];
int p[MAXN];
int N, M;//顶点数 边数

void init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        edges[i].s = s;
        edges[i].e = e;
        edges[i].w = cost;
    }
    sort(edges, edges + M, cmp);
}

void UFset() {
    for (int i = 0; i < MAXN; i++)
        p[i] = i;
}

int find(int x) {
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

int hb(int r1, int r2) {
    int s1 = find(r1);
    int s2 = find(r2);
    if (s1 != s2) {
        p[s2] = s1;
        return 1;
    }
    return 0;
}

int kruskal() {
    init();
    UFset();
    int ans = 0;
    int bs = 0;//bst中边数
    for (int i = 0; i < M; i++) {
        if (hb(edges[i].s, edges[i].e)) {
            ans += edges[i].w;
            bs++;
        }
        if (bs == N - 1) break;
    }
    return ans;
}

int main() {
    cout << kruskal() << endl;
    return 0;
}