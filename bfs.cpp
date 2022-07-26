#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define forv(a, b) for(auto & a : b)
using namespace std;
const int N = 1e3 + 10;
vector<int> ke[N];
int d[N];
void solve() {
	int n, m; cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	int s; cin >> s;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		forv(v, ke[u]) {
			if (d[v]) continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
		forv(v, ke[u]) ke[u].pop_back();
	}
	forin(i, 1, n) {
		if (i == s) continue;
		if (d[i] == 0) cout << -1;
		else cout << d[i] * 6;
		cout << " ";
	}
	memset(d, 0, sizeof(d));
}
int main() {
	int q; cin >> q;
	while (q--) {
		solve();
		cout << "\n";
	}
}