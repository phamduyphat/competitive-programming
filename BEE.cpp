#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200;
const int mod=1e9;
typedef long long ll;
ll dp[N][N][N],n;
int dx[7]={0,0,1,1,-1,-1};
int dy[7]={1,-1,-1,0,0,1};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	dp[0][51][51]=1;
	forin(i,1,n)
	{
		forin(u,1,101)
		{
			forin(v,1,101)
			{
				forin(k,0,5)
				{
					dp[i][u][v]+=(dp[i-1][u+dx[k]][v+dy[k]])%mod;
				}
			}
		}
	}
	cout << dp[n][51][51]%mod;
}