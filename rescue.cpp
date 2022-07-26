#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;++i)
#define forve(a,b) for(auto &a:b)
using namespace std;
const int N = 1e4+10;
vector<int>adj[N];
int d[N],f[N];
int main ()
{
	int n,m,k,ok = 0,res = 0;cin>>n>>m>>k;
	forin(i,1,m)
	{
		int x,y;cin>>x>>y; d[x]++; d[y]++;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	while(true)
	{
		ok = 0;
		forin(i,1,n)if(!f[i] & d[i]<k)
		{
			ok = 1;
			f[i] = 1;
			forve(v,adj[i])d[v]--;
		}	
		if(!ok)break;
	}
	forin(i,1,n)if(d[i]>=k)res++;
	cout<<res;
}