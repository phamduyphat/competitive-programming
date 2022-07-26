#include<bits/stdc++.h>
#define forin(i, a ,b) for(int i = a; i <= b; i++)
#define forde(i, a, b )for(int i = a; i >= b; i--)
using namespace std;
const int N = 1010;
int a[N][N], dp[N][N], d[N];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	forin(i, 1, n) forin(j, 1, n) dp[i][j] = 1e8;
	forin(i, 1, n) forin(j, 1, n) cin >> a[i][j];
	long long res = 0;
	forin(i, 2, n - 1) forin(j, 2, n - 1)
	{
		bool ok = 1, ok2 = 1;
		if (a[i][j] == a[i][j + 1]) 
		{
			d[j] = 1;
			continue;
		}
		forde(k, j, 2)
		{
			if (d[j] == 1) dp[k][j] = 1e6;
			if (a[i][k] == a[i + 1][k]) ok = 0;
			if (a[i][k] == a[i - 1][k]) ok2 = 0;
			if (a[i][k] == a[i][k - 1]) dp[k][j] = 1e6;
			else
			{
				if (ok2) dp[k][j] = min(dp[k][j], i);
				if (ok) res = max(res, 1ll*(j - k + 1)*(i - dp[k][j] + 1));
			}
		}
		d[j] = 0;
	}
	cout << res;
}
