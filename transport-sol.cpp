#include <bits/stdc++.h>
using namespace std;
const int maxN = 500, inf = 0x3f3f3f3f;
struct Node
{
    int to, value, next;
} edge[maxN * 2 + 1];
int n, m, K, e, d, x, y, t, p, a, b, dis[maxN + 1], f[maxN + 1];
int tot, head[maxN + 1];
bool flag[maxN + 1][maxN + 1], vis[maxN + 1];
bool mark[maxN + 1];
inline void add(int x, int y, int t)
{
    edge[++tot] = {y, t, head[x]};
    head[x] = tot;
    edge[++tot] = {x, t, head[y]};
    head[y] = tot;
}
inline void spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i = head[x]; i; i = edge[i].next)
            if (!mark[edge[i].to] && dis[x] + edge[i].value < dis[edge[i].to])
            {
                dis[edge[i].to] = dis[x] + edge[i].value;
                if (!vis[edge[i].to])
                {
                    vis[edge[i].to] = true;
                    q.push(edge[i].to);
                }
            }
    }
}
inline void work()
{
    f[0] = -K;
    for (int i = 1; i <= n; i++)
    {
        memset(mark, false, sizeof(mark));
        for (int j = i; j >= 1; j--)
        {
            for (int k = 1; k <= m; k++)
                if (flag[k][j])
                    mark[k] = true;
            spfa();
            if (dis[m] >= inf)
                continue;
            f[i] = min(f[i], f[j - 1] + (i - j + 1) * dis[m] + K);
        }
    }
    cout << f[n];
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n >> m >> K >> e;
    for (int i = 1; i <= e; i++)
    {
        cin >> x >> y >> t;
        add(x, y, t);
    }
    cin >> d;
    for (int i = 1; i <= d; i++)
    {
        cin >> p >> a >> b;
        for (int j = a; j <= b; j++)
            flag[p][j] = true;
    }
    memset(f, 0x3f, sizeof(f));
    work();
    return 0;
}