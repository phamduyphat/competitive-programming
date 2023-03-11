//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "shopping"
#define maxn 200005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define haimu(x) (1<<(x))

using namespace std;

int n, q;
long long a[maxn], f[maxn][19];

int main()
{
	//ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    a[++n] = 0;
    for (int i = 1; i <= n; i++) f[i][0] = a[i];
    for (int i = 1; i <= 17; i++)
        for (int u = n - haimu(i) + 1; u >= 1; u--)
            f[u][i] = min(f[u][i-1], f[u+haimu(i-1)][i-1]);
    while (q--){
        long long v;
        int l, r;
        scanf("%lld%d%d", &v, &l, &r);
        while (l <= r){
            int u = l;
            for (int i = 17; i >= 0; i--)
                if (f[u][i] > v) u += haimu(i);
            if (u > r) break;
            v %= a[u];
            l = u+1;
        }
        printf("%lld\n", v);
    }
    return 0;
}

