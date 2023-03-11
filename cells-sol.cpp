#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define forv(a, b) for(auto & a : b)
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;
const int N = 1e6 + 10;
int Down[N], Right[N], Left[N], Up[N], bit[N];
int n, m, k;
vector<pair<int, int>> v[N];
void add(int pos, int val) {
    while (pos <= n) {
        bit[pos] += val;
        pos += pos & -pos;
    }
}
int get(int pos) {
    int ret = 0;
    while (pos) {
        ret += bit[pos];
        pos -= pos & -pos;
    }
    return ret;
}
int main() {
    #define task "cells"
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen ("task.inp", "r")) {
        freopen ("task.inp", "r", stdin);
        freopen ("task.out", "w", stdout);
    }
    if (fopen (task".inp", "r")) {
        freopen (task".inp", "r", stdin);
        freopen (task".out", "w", stdout);
    }
    cin >> n >> m >> k;
    n++, m++;
    fill (Right + 1, Right + n + 1, m + 1);
    fill (Up + 1, Up + m + 1, n + 1);
    while (k--) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x++, y++;
        if (c == 'N') Up[y] = min(Up[y], x);
        else if (c == 'E') Right[x] = min(Right[x], y);
        else if (c == 'S') Down[y] = max(Down[y], x);
        else Left[x] = max(Left[x], y);
    }
    long long res = 0;
    for(int i = 1; i <= n; i++) {
        if (Left[i]) {
            v[1].push_back({i, 1});
            v[Left[i] + 1].push_back({i, -1});
        }
        Right[i] = max(Right[i], Left[i] + 1);
        if (Right[i] != m + 1) {
            v[Right[i]].push_back({i, 1});
        }
        res += Left[i] + m - Right[i] + 1;
    }
    for(int i = 1; i <= m; i++) {
        forv(t, v[i]) add(t.fi, t.se);
        if (Down[i]) {
            res -= get(Down[i]);
        }
        Up[i] = max(Up[i], Down[i] + 1);
        if (Up[i] != n + 1) {
            res -= get(n) - get(Up[i] - 1);
        }
        res += Down[i] + n - Up[i] + 1;
    }
    cout << res;
}
