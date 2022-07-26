#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define fi first
#define se second
using namespace std;
const int N = 110;
int b[N], a[N];
bool ss(pair<int, int> A, pair<int, int> B)
{
	return (A.se < B.se);
}
int main()
{
	int n; cin >> n;
	forin(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	forin(i, 1, n) cin >> b[i];
	sort(b + 1, b + n + 1);
	int i = 1, j = 1, tmp = -1e9, res = 0;
	while (i <= n && j <= n) 
	{
		while (a[i] <= tmp && i < n) i++;
		while (b[j] <= tmp && j < n) j++;
		if (a[i] > tmp && b[j] > tmp) res++;
		tmp = max(tmp, a[i]);
		tmp = max(tmp, b[j]);
		i++, j++;
	}
	cout << res;
}