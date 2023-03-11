#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+10;
typedef long long ll;
int n, p, o[N];
ll a[N],dp[N],trace[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> p;
	forin(i,1,n) cin >> a[i];
	forin(i,1,n) dp[i]=1e9;
	forin(i,1,n)
	{
		forin(j,0,i-1)
		{
			if(dp[j]+(a[i]-a[j]-p)*(a[i]-a[j]-p) < dp[i])
			{
				dp[i]=dp[j]+(a[i]-a[j]-p)*(a[i]-a[j]-p);
				trace[i]=j;
			}
		}
	}
	cout << dp[n] << "\n";
	ll dem = 0;
	ll op = n;
	while(trace[op])
	{
		dem;
		o[dem++] = trace[op];
		op = trace[op];
	}
	cout << dem + 1 << "\n";
	sort(o + 1,o + dem + 1);
	forin(i,1,dem) cout << o[i] << " ";
	cout << n;
}