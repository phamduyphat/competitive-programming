/* input
5 4
1 2 3 4 5
1 1 3 2
2 2 4 4
3 4 5 2
4 1 5
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10, mod = 1e9 + 7;
int a[N], T[4 * N], mul[4 * N], inc[4 * N], assign[4 * N];

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int sum(int x, int y) {
	int ret = x + y;
	return (ret < mod) ? ret : ret - mod;
}

#define mid (l+r)/2
void build(int s, int l, int r) {
	mul[s] = 1;
	if (l == r) {
		T[s] = a[l];
		return;
	}
	build(2 * s, l, mid); build(2 * s + 1, mid + 1, r);
	T[s] = sum(T[2 * s], T[2 * s + 1]);
}

void push(int s, int l, int r) {
	if (assign[s]) {
		T[s] = 1LL * (r - l + 1) * assign[s] % mod;
		if (l != r) {
			assign[2 * s] = assign[2 * s + 1] = assign[s];
			mul[2 * s] = mul[2 * s + 1] = 1;
			inc[2 * s] = inc[2 * s + 1] = 0;
		}
		assign[s] = 0;
	}

	if (mul[s] > 1) {
		T[s] = 1LL * T[s] * mul[s] % mod;
		if (l != r) {
			mul[2 * s] = 1LL * mul[2 * s] * mul[s] % mod;
			inc[2 * s] = 1LL * inc[2 * s] * mul[s] % mod;
			mul[2 * s + 1] = 1LL * mul[2 * s + 1] * mul[s] % mod;
			inc[2 * s + 1] = 1LL * inc[2 * s + 1] * mul[s] % mod;
		}
		mul[s] = 1;
	}

	if (inc[s]) {
		add(T[s], 1LL * (r - l + 1) * inc[s] % mod);
		if (l != r) {
			add(inc[2 * s], inc[s]);
			add(inc[2 * s + 1], inc[s]);
		}
		inc[s] = 0;
	}
}

void increase(int s, int l, int r, int u, int v, int val) {
	push(s, l, r);
	if (l > v || r < u) return;
	if (l >= u && r <= v) {
		add(T[s], 1LL * (r - l + 1) * val % mod);
		if (l != r) {
			add(inc[2 * s], val);
			add(inc[2 * s + 1], val);
		}
		return;
	}
	increase(2 * s, l, mid, u, v, val);
	increase(2 * s + 1, mid + 1, r, u, v, val);
	T[s] = sum(T[2 * s], T[2 * s + 1]);
}

void multiply(int s, int l, int r, int u, int v, int val) {
	push(s, l, r);
	if (l > v || r < u) return;
	if (l >= u && r <= v) {
		T[s] = 1LL * T[s] * val % mod;
		if (l != r) {
			mul[2 * s] = 1LL * mul[2 * s] * val % mod;
			inc[2 * s] = 1LL * inc[2 * s] * val % mod;
			mul[2 * s + 1] = 1LL * mul[2 * s + 1] * val % mod;
			inc[2 * s + 1] = 1LL * inc[2 * s + 1] * val % mod;
		}
		return;
	}
	multiply(2 * s, l, mid, u, v, val);
	multiply(2 * s + 1, mid + 1, r, u, v, val);
	T[s] = sum(T[2 * s], T[2 * s + 1]);
}

void setval(int s, int l, int r, int u, int v, int val) {
	push(s, l, r);
	if (l > v || r < u) return;
	if (l >= u && r <= v) {
		T[s] = 1LL * (r - l + 1) * val % mod;
		if (l != r) {
			assign[2 * s] = assign[2 * s + 1] = val;
			mul[2 * s] = mul[2 * s + 1] = 1;
			inc[2 * s] = inc[2 * s + 1] = 0;
		}
		return;
	}
	setval(2 * s, l, mid, u, v, val);
	setval(2 * s + 1, mid + 1, r, u, v, val);
	T[s] = sum(T[2 * s], T[2 * s + 1]);
}

int query(int s, int l, int r, int u, int v) {
	push(s, l, r);
	if (l > v || r < u) return 0;
	if (l >= u && r <= v) return T[s];
	return sum(query(2 * s, l, mid, u, v), query(2 * s + 1, mid + 1, r, u, v));
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("task.inp", "r", stdin);
	freopen("task.out", "w", stdout);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(1, 1, n);

	while (m--) {
		int type, l, r, val; cin >> type >> l >> r;
		if (type < 4) cin >> val;
		if (type == 1) increase(1, 1, n, l, r, val);
		else if (type == 2) multiply(1, 1, n, l, r, val);
		else if (type == 3) setval(1, 1, n, l, r, val);
		else cout << query(1, 1, n, l, r) << "\n";
	}
}
