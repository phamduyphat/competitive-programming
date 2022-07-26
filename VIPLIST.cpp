#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define forv(a, b) for(auto & a : b) 
#define ii pair<int, int>
using namespace std;
const int N = 1e5 + 10;
bool f[N];
int deg[N];
vector<int> ke[N];
int main() {
	freopen("VIPLIST.INP","r",stdin);
	freopen("VIPLIST.OUT", "w", stdout);
//	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	map <pair<int, int>, int > d;
	while (m--) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		if (d[ii(x, y)] == 0) deg[x]++;
		if (d[ii(x, y)] == 0) deg[y]++;
		d[ii(x, y)] = 1; d[ii(y, x)] = 1;
	}
	int res = n;
	queue<int> q;
	forin(i, 1, n) if (deg[i] < k) {
		f[i] = 1;
		q.push(i);
		res--;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		forv(v, ke[u]) {
			if (f[v]) continue;
			deg[v]--;
			if (deg[v] < k) {
				res--;
				q.push(v);
				f[v] = 1;
			}
		}
	}
	cout << res << "\n";
	forin(i, 1, n) if (!f[i]) cout << i << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}