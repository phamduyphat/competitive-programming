//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "LCA"
#define maxn 100005
#define maxh 20

#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m, root;
int par[maxn][maxh];
int h[maxn];
vector <int> a[maxn];

void nhap()
{
    cin >> n >> root >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
}

void DFS(int u)
{
    for (int v : a[u])
        if (v != par[u][0]){
            h[v] = h[u] + 1;
            par[v][0] = u;
            for (int i = 1; i <= 17; i++)
                par[v][i] = par[par[v][i-1]][i-1];
            DFS(v);
        }
}

int lca(int u, int v) //O(logN)
{
    // Dua 2 dinh ve cung do sau
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u]-h[v];
    for (int i = 0; i <= 17;i++) // for 17->0
        if ((delta >> i) & 1) u = par[u][i];
	
    if (u == v) return u; // quan trong
    // Nhay len toi khi gap nhau
    for (int i = 17; i >= 0; i --)
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[v][0]; // par[u][0]
}

int main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
//    nhap();
//    h[root] = 1;
//    DFS(root);
//    while (m--)
//    {
//        int u, v;
//        cin >> u >> v;
//        cout << lca(u,v) << "\n";
//    }


    return 0;
}
