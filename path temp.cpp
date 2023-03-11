//source: 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int par[N], st[N], ed[N];

int root(int x) {
    return par[x] < 0 ? x : par[x] = root(par[x]);
}

void join(int x, int y) {
    if ((x = root(x)) == (y = root(y))) return;
    if (par[x] > par[y]) swap(par[x], par[y]);
    par[x] += par[y]; st[x] += st[y]; ed[x] += ed[y];
    par[y] = x;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, mx, u, v; cin >> n >> m >> mx >> u >> v;
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= m; ++i) {
        int x, y, w; cin >> x >> y >> w;
        edges.emplace_back(w, x, y);
    }
    for (int i = 1; i <= u; ++i) {
        int x; cin >> x;
        st[x] = 1;
    }
    for (int i = 1; i <= v; ++i) {
        int x; cin >> x;
        ed[x] = 1;
    }
    memset(par, -1, sizeof(par));

    ll res = 0;
    sort(edges.begin(), edges.end());
    int it = 0;
    for (; it < n; ++it) {
        int w, x, y; tie(w, x, y) = edges[it];
        if (w >= mx) break;
        join(x, y);
    }
    for (int i = 1; i <= n; ++i) if (par[i] < 0) res -= 1LL * st[i] * ed[i];
    
    for (; it < n; ++it) {
        int w, x, y; tie(w, x, y) = edges[it];
        if (w > mx) break;
        join(x, y);
    }
    for (int i = 1; i <= n; ++i) if (par[i] < 0) res += 1LL * st[i] * ed[i];

    cout << res << "\n";
}