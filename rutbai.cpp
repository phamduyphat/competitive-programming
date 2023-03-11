#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
#define maxn 1e16
using namespace std;
typedef long long ll;
const int N=110;
ll a[N],dp[N][N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n; cin >> n;
	forin(i,1,n) cin >> a[i];
	forin(m,2,n-1)// khoang bai can xet
	{
		forin(i,1,n-m)//first point
		{
			int j=i+m;//last point
			dp[i][j]=maxn;
			forin(k,i+1,j-1)//point xet khoang[i,j]
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
			}
		}
	}
	cout << dp[1][n];
} 