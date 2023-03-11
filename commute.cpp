//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "commute"
#define maxn 200002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

typedef int arr[maxn];

arr f, g, be, len, d, pos, cycle;
int n, cnt = 0;


void read()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i], pos[f[i]] = i;
}

void make_cycle()
{
    fill(d, d+n+1, n+1);
    for (int i = 1; i <= n; i++)
        if (!cycle[i])
        {
            len[++cnt] = 1;
            be[cnt] = i;
            cycle[i] = cnt;
            for (int u = f[i]; u != i; u = f[u]){
                len[cnt]++;
                cycle[u] = cnt;
                if (f[be[cnt]] > f[u]) be[cnt] = u;
            }
            if (d[len[cnt]] > f[be[cnt]])
                d[len[cnt]] = f[be[cnt]];
        }

}

void calc()
{
//    fill(kt, kt+n+1, 1);
    for (int i = 1; i <= n; i++)
        if (d[i] <= n)
            for (int j = i+i; j <= n; j += i) MIN(d[j], d[i]);

    for (int i = 1; i <= cnt; i++)
    {
        int u = be[i];
        int v = pos[d[len[i]]];
        do {
            g[u] = v;
            u = f[u];
            v = f[v];
        } while (u != be[i]);
    }
}


int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    read();
	make_cycle();
    calc();
    for (int i = 1; i <= n; i++) cout << g[i] << " ";
    return 0;
}
