#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define forv(a, b) for(auto & a : b)
using namespace std;
const int N = 1e3 + 10;
vector<int> ke[N];
int d[N];
int main() {
	int n, m; cin >> n >> m;
	d[1] = 1;
	while (m--) {
		int ask; 
		cin >> ask;
//		cout << ask;
		if (ask == 2) {
			int u, v; cin >> u >> v;
			ke[u].push_back(v);
			ke[v].push_back(u);
			if (d[u] > d[v]) swap(u, v);
			if (d[u] == 0) swap(u, v);
			if (d[u] == 0) continue;
			queue<int> q;
			q.push(v);
			d[v] = d[u] + 1;
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				forv(t, ke[x]) {
					if (d[t] == 0 || d[t] > d[x] + 1) {
						d[t] = d[x] + 1;
						q.push(t);
					}
				}
			}
		}
		else  {
			int x; cin >> x;
			cout << d[x] - 1 << " ";
		}
	}
}