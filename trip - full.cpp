//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "trip"

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m, s, t;

vector <int> ke[maxn];
int used[maxn], dist[maxn], q[maxn], tr[maxn], par[maxn][20], pmin[maxn][20];

void BFS(){
    memset(dist, 1, sizeof(dist));
    dist[s] = 0;
    used[s] = 1;
    int l = 1, r = 1;
    q[1] = s;
    while (l <= r){
        int u = q[l++];
        for (int v : ke[u])
            if (!used[v]) {
                q[++r] = v;
                dist[v] = dist[u] + 1;
                used[v] = 1;
                if (v == t) return;
        }
    }
}

bool Better(int u, int v){
    int umin = n+1, vmin = n+1;
    for (int i = 17; i >= 0; i--)
        if (par[u][i] != par[v][i])
        {
            MIN(umin, pmin[u][i]);
            MIN(vmin, pmin[v][i]);
            u = par[u][i]; v = par[v][i];
        }
    MIN(umin, u);
    MIN(vmin, v);
    return (umin < vmin);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m >> s >> t;
    swap(s,t);
    for (int u, v, i = 1; i <= m; i++) {
        cin >> u  >> v;
        ke[u].PB(v);
        ke[v].PB(u);
    }
    BFS();
    if (!used[t]){
        cout << -1;
        cerr << -1 << endl;
        return 0;
    }

    for (int u, i = 1; u = q[i]; i++)
    {
        //cout << u << " ";
        for (int v : ke[u])
            if (dist[v] == dist[u] - 1){
                if (tr[u] == 0 || Better(v, tr[u])) tr[u] = v;
        }
        pmin[u][0] = u;
        par[u][0] = tr[u];
        for (int j = 1; j < 18; j++) {
            int x = par[u][j-1];
            par[u][j] = par[x][j-1];
            pmin[u][j] = min(pmin[u][j-1], pmin[x][j-1]);
        }
    }
    int cnt = 0;
    for (; s != t; t = tr[t]) {
        cout << t << " ";
    }
    cout << t;
        return 0;
}

