#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e5 + 10;
struct a{
	long long fi, se;
	float val;
}	a[N];
bool ss(struct a &A, struct a &B)
{
	return A.val > B.val;
}
int main()
{
	int n; cin >> n;
	long long s = 0;
	forin(i, 1, n) 
	{
		cin >> a[i].fi >> a[i].se;
		a[i].val = 1.0*a[i].se / a[i].fi;
		s += a[i].se;
	}
	sort(a + 1, a + n + 1,ss);
	long long res = 0;
	forin(i, 1, n) 
	{
		s -= a[i].se;
//		cout << a[i].se << " ";
		res += a[i].fi*2*s;
	}
	cout << res;
}