/* input

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10, mod = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int sum(int l, int r) {
	return (1LL * r * (r + 1) / 2 - 1LL * (l - 1) * l / 2) % mod;
}

struct MulIT {
	int T[4 * N], lazy[4 * N];

	void push(int s, int l, int r) {
		add(T[s], 1LL * sum(l, r) * lazy[s] % mod);
		if (l != r) {
			add(lazy[s << 1], lazy[s]);
			add(lazy[s << 1 | 1], lazy[s]);
		}
		lazy[s] = 0;
	}

	void up(int s, int l, int r, int u, int v, int val) {
		push(s, l, r);
		if (l > v || r < u) return;
		if (l >= u && r <= v) {
			add(T[s], 1LL * sum(l, r) * val % mod);
			if (l != r) {
				add(lazy[s << 1], val);
				add(lazy[s << 1 | 1], val);
			}
			return;
		}
		int mid = (l + r) >> 1;
		up(s << 1, l, mid, u, v, val);
		up(s << 1 | 1, mid + 1, r, u, v, val);
		T[s] = (T[s << 1] + T[s << 1 | 1]) % mod;
	}

	int get(int s, int l, int r, int u, int v) {
		push(s, l, r);
		if (l > v || r < u) return 0;
		if (l >= u && r <= v) return T[s];
		int mid = (l + r) >> 1;
		return (get(s << 1, l, mid, u, v) + get(s << 1 | 1, mid + 1, r, u, v)) % mod;
	}
} it1;

struct SumIT {
	int T[4 * N], lazy[4 * N];

	void push(int s, int l, int r) {
		add(T[s], 1LL * (r - l + 1) * lazy[s] % mod);
		if (l != r) {
			add(lazy[s << 1], lazy[s]);
			add(lazy[s << 1 | 1], lazy[s]);
		}
		lazy[s] = 0;
	}

	void up(int s, int l, int r, int u, int v, int val) {
		push(s, l, r);
		if (l > v || r < u) return;
		if (l >= u && r <= v) {
			add(T[s], 1LL * (r - l + 1) * val % mod);
			if (l != r) {
				add(lazy[s << 1], val);
				add(lazy[s << 1 | 1], val);
			}
			return;
		}
		int mid = (l + r) >> 1;
		up(s << 1, l, mid, u, v, val);
		up(s << 1 | 1, mid + 1, r, u, v, val);
		T[s] = (T[s << 1] + T[s << 1 | 1]) % mod;
	}

	int get(int s, int l, int r, int u, int v) {
		push(s, l, r);
		if (l > v || r < u) return 0;
		if (l >= u && r <= v) return T[s];
		int mid = (l + r) >> 1;
		return (get(s << 1, l, mid, u, v) + get(s << 1 | 1, mid + 1, r, u, v)) % mod;
	}
} it2;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("task.inp", "r", stdin);
	freopen("task.out", "w", stdout);

	int n, m; cin >> n >> m;

	while (m--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r, a, b; cin >> l >> r >> a >> b;
			it1.up(1, 1, n, l, r, a);
			it2.up(1, 1, n, l, r, (-1LL * a * l % mod + b + mod) % mod);
		}
		else {
			int l, r; cin >> l >> r;
			cout << (it1.get(1, 1, n, l, r) + it2.get(1, 1, n, l, r)) % mod << "\n";
		}
	}
}