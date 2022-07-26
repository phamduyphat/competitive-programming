#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 1e6 + 10;
int mod = 1e9 + 9;
int e[N], d1[N], d2[N];
long long mu (int a, int n)
{
	if (n == 0) return 1;
	long long t = mu(a, n/2);
	t %= mod;
	t = t*t;
	t %= mod;
	if (n % 2) 
	{
		t *= a;
		t %= mod;
	}
	return t;
}
void sang()
{
	for(int i = 2; i <= 1e6; i++) 
	{
		if (e[i]) continue;
		for(int j = 1; j*i <= 1e6; j++) e[i*j] = i;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sang();
	long long res = 1;
	int m, n, k; cin >> m >> n >> k;
	while (m--) 
	{
		int y; cin >> y;
		while (y > 1) 
		{
			d1[e[y]]++;
			y /= e[y];
		}
	}
	while (n--) 
	{
		int y; cin >> y;
		while (y > 1)
		{
			d2[e[y]]++;
			y /= e[y];
		}
	}
	forin(i, 1, 1e6) 
	{
		if (e[i] != i) continue;
		int t = d2[i] - d1[i] + 1;
		if (t <= 0) 
		{
			cout << 0;
			return 0;
		}
		if (t > 1) 
		{
			long long tmp = (mu(t,k)%mod - 2*mu(t-1,k)%mod + mu(t-2,k) + mod) %mod; 
			res *= tmp;
			res %= mod;
		}
	}
	cout << res;
}