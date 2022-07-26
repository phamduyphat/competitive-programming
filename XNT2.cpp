#include <bits/stdc++.h>
#define forin(i,a,b) for(long long i=a;i<=b;i++)
#define ll long long
using namespace std;
ll n;
bool fr[1000060];
vector <ll> p;
void sang ( ll n)
{
	memset(fr,true,sizeof(fr));
	for(ll i = 2; i * i <= n + 1000; i ++)
	{
		if(fr[i])
		{
			for (ll j = i * 2; j <= n; j += i)
			{
				fr[j] = false;
			}
		}
	}
	forin(k, 2, n + 50)
	{
		if(fr[k]) p.push_back(k);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll ans = 0;
    cin >> n;
	sang(n);
	p.push_back(n);
	ll tmp;
	for (ll i = 100; p[i] < n; i++)
	{
		if (p[i] - p[i - 1] - 21 > 0)
		ans += p[i] - p[i - 1] - 21;
		tmp = i;
	}
	forin(i,p[tmp] + 1,n)
	{
		if (i - p[tmp] > 10 && p[tmp + 1] - i > 10) ans ++;
	}
	cout << ans;
}
