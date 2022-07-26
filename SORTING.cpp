#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define forv(a, b) for(auto & a : b)
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10;
long long a[N], d[N];
pair<long long, long long> b[N];
int main() {
	int n; cin >> n;
	forin(i, 1, n) {
		cin >> a[i];
		b[i].fi = a[i];
		b[i].se = i;
	}
	sort(b + 1, b + n + 1);
	long long res = 0;
	forin(i, 1, n) {
		if (d[i]) continue;
		long long k = i, tmp = 1e9, slt = 0;
		long long s = 0;
		while (d[k] == 0) {
			d[k] = 1;
			s += a[k];
			slt ++;
			tmp = min(tmp, a[k]);
			k = b[k].se;
		}
		res += s + min((slt - 2) * tmp, (slt + 1) * b[1].fi + tmp);
	}
	cout << res;
	                                                       
}