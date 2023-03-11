//Anh OK
#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
#define forv(a,b) for(int a : b)
#define pb push_back
using namespace std;
const int N=2e6+10;
const int P=101;
typedef long long ll;
const ll mod=1e9+7;
const ll mm = 1LL * mod * mod;
ll pw[N],hb[N];
int gethash(int u, int v){
    return (hb[v] - hb[u-1] * pw[v-u+1] +mm) % mod;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	ll m= s.length();
	s = " " + s;
    if(m%2==0) 
	{
		cout << "NOT POSSIBLE";
		return 0;
	}
	else
	{
		hb[0] = 0;
    	pw[0] = 1; 
    	forin(i,1,m) hb[i] = ((hb[i-1] * P) + s[i]) % mod;
    	forin(i,1,m) pw[i] = (pw[i-1] * P) % mod;
    	int ts1=0,ts2=0,ts3=0;
    	ll mid= m/2 + 1;
    	if(gethash(2,mid) == gethash(mid+1,m)) ts2=1;
    	if(gethash(1,mid-1) == gethash(mid+1,m)) ts3=1;
    	if(gethash(1,mid) == gethash(mid+1,m-1)) ts1=1;
    	forin(i, 2, mid - 1) 
		{
		if (gethash(1, i - 1) == gethash(mid + 1, mid + i - 1) && gethash(i + 1, mid) == gethash(mid + i, m)) ts2 = 1;
		}
		forin(i, mid + 1, m) 
		{
		if (gethash(mid, i - 1) == gethash(1, i - mid) && gethash(i + 1, m) == gethash(i - mid + 1, mid - 1)) ts1 = 1;
		}
	if (ts1 + ts2 + ts3 == 0) cout << "NOT POSSIBLE";
	else if (ts1 && ts2) 
		{
		if (s.substr(1, mid - 1) == s.substr(mid + 1, m)) cout << s.substr(1, mid - 1);
		else cout << "NOT UNIQUE";
		}
	else if (ts1 == 1) cout << s.substr(1, mid - 1);
	else if (ts2 == 1 || ts3 == 1) cout << s.substr(mid + 1, m);
    	
	}
	 
}