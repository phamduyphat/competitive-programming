#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 1e5 + 10;
int t[4 * N], a[N];
pair<int, int> b[N];
int get(int s, int l, int r, int u, int v) {
	if (l > v || r < u) return -1e9;
	if (u <= l && r <= v) return t[s];
	int mid = (l + r)/2;
	return max(get(s * 2, l, mid, u, v), get(s * 2 + 1, mid + 1, r, u, v));
}
void update(int s, int l, int r, int pos, int val) {
	if (l == r) {
		t[s] = max(t[s], val);
		return;
	}
	int mid = (l + r)/2;
	if (pos <= mid) update(s * 2, l, mid, pos, val);
	else update(s * 2 + 1, mid + 1, r, pos, val);
	t[s] = max(t[s * 2], t[s * 2 + 1]);
}
int main() {
	int n; cin >> n;
	forin(i, 1, n) {
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(b + 1, b + n + 1);
	int val = -1e9 - 1, c = 0;
	forin(i, 1, n) {
		if (b[i].first != val) {
			val = b[i].first;	
			c++;
		}
		a[b[i].second] = c;
	}
	forin(i, 1, n) {
		int k = 0;
		if (a[i] > 1) k = get(1, 1, n, 1, a[i] - 1);
		update(1, 1, n, a[i], k + 1);
//		cout << get(1, 1, n, 1, 2) << endl;
	}
	cout << get(1, 1, n, 1, n);
}