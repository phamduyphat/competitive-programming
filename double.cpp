#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;++i)
#define forve(a,b) for(auto &a:b)
#define ll long long
using namespace std;
const int N = 1e5+10;
ll a[N],b[N],pos[N],d[N],s,ans,res;
vector<pair<int,int>>grav[N];
void add(int i,int j,int k)
{
	grav[i].push_back(make_pair(j,k));
	grav[j].push_back(make_pair(i,k));
}
void dfs(int i,int k)
{
	d[i] = 1; s++;
	forve(v,grav[i])if(!d[v.first])
	{
		if(v.second)ans+=1-k, dfs(v.first,1-k);
		else ans+=k, dfs(v.first,k);
	}	
}
int main ()
{
	int n;cin>>n;
	forin(i,1,n)cin>>a[i];
	forin(i,1,n)cin>>b[i];
	forin(i,1,n)
	{
		int ii = pos[a[i]],jj = pos[b[i]];
		if(ii)
		{
			if(a[i]==a[ii])add(i,ii,1);
			else add(i,ii,0);
		}
		if(jj)
		{
			if(b[i]==b[jj])add(i,jj,1);
			else add(i,jj,0);
		}
		pos[a[i]] = i; pos[b[i]] = i;
	}
	forin(i,1,n)if(!d[i])
	{
		s = 0; ans = 0;
		dfs(i,0);
		res += min(s-ans,ans);
	}
	cout<<res;
}