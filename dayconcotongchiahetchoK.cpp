#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
#define forde(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1100;
const int N1=60;
typedef long long ll;
ll a[N],dp[N][N1],trace[N][N1],test[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k; cin >> n >> k;
	forin(i,1,n)
	{
		cin >> a[i];
		a[i]%=k;
	}
	memset(dp,-127,sizeof(dp));
	dp[0][0]=0;
	forin(i,1,n)
	{
		forin(j,0,k-1)
		{
			if(dp[i][j] < dp[i-1][j])
			{
				dp[i][j]=dp[i-1][j];//dpi,j la so phan tu toi thieu lay tu a1 -> ai sao cho tong chia k du j
				trace[i][j]=0;
			}
			int u = (j-a[i]+k)%k;
			if(dp[i][j] < dp[i-1][u] + 1)
			{
				dp[i][j]= dp[i-1][u] + 1;
				trace[i][j]=1;
			}
		}
	}
	cout << dp[n][0] << "\n";
	int mod=0;
	forde(i,n,1)
	{
		test[i]= trace[i][mod];
		if(test[i]) mod=(mod-a[i] + k)%k;
	}
	forin(i,1,n)
	{
		if(test[i]) cout << i << " ";
	}
}
