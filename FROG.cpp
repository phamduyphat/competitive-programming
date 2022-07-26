#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define forv(a, b) for(auto & a : b)
using namespace std;
const int N = 1e5 + 10;
int col[N], row[N];
struct a {
	int x, y, v;
} a[N];
bool ss(struct a &A, struct a &B) {
	if (A.x == B.x) return (A.y < B.y);
	return (A.x < B.x);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	forin(i, 1, n) {
		cin >> a[i].x >> a[i].y >> a[i].v;
	}
	int bx = a[1].x, by = a[1].y;
	int cx = a[n].x, cy = a[n].y;
	sort(a + 1, a + n + 1, ss);
	int res = 0;
	forin(i, 1, n) {
		if (a[i].x < bx || a[i].y < by) continue;
		int k = max(row[a[i].x], col[a[i].y]) + a[i].v;
		row[a[i].x] = max(row[a[i].x], k);
		col[a[i].y] = max(col[a[i].y], k);
		if (a[i].x == cx && a[i].y == cy) res = max(res, k);
	}
	cout << res;
}