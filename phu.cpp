#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10;
pair<long long, long long> a[N];
bool ss(pair<int, int> A, pair<int, int> B)
{
	if (A.se == B.se) return (A.fi < B.fi);
	return (A.se > B.se);
}
int main()
{
	int n; cin >> n;
	forin(i, 1, n) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	long long tmp  = -1e12, res = 0;
	forin(i, 1, n) 
	{
		if (a[i].fi < tmp) res += max(1ll*0, a[i].fi + a[i].se - tmp);
		else res += a[i].se;
		tmp = max(tmp, a[i].se + a[i].fi);
//		cout << res << " ";
	}
	cout << res;
}