#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
#define forde(i,a,b) for(int i=a;i>=b;i--)
#define forv(a,b) for(auto & a: ke[b])
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+10;
vector<pii> ke[N];
int t,slt,kq=0,n;
int a[N],b[N],s[N];
bool fr[N];
void add(int u, int v, int k) {
	ke[u].push_back(make_pair(v, k));
	ke[v].push_back(make_pair(u, k));
}
void nhap(int n)
{
	forin(i,1,n) cin >> a[i];
	forin(i,1,n) cin >> b[i];
	forin(i,1,n)
	{
		int x=s[a[i]];
		int y=s[b[i]];
		if(x!=0)
		{
			if(a[x]==a[i]) add(i,x,1);
			else if (a[x] == b[i]) add(i,x,0);
		}
		if(y!=0)
		{
			if(b[y]==b[i]) add(i,y,1);
			else if (b[y] == a[i]) add(i,y,0);
		}
		s[a[i]]=i;
		s[b[i]]=i;
	}
}
void dfs(int u, int tmp)
{
	slt++;
	fr[u] = true;
	forv(v, u) {
		if (fr[v.fi]) continue;
		if (v.se==0)
		{
			t+=tmp;
			dfs(v.fi, tmp);
		} 
		else
		{
			t += 1 - tmp;
		 	dfs(v.fi, 1 - tmp);
		}
	}
}
int main()
{
	cin >> n;
	nhap(n);
	memset(fr,false,sizeof(fr));
	forin(i,1,n)
	{
		if(!fr[i])
		{
			//fr[i]=true;
			slt=0;
			t=0;
			dfs(i,0);
			kq+=min(t,slt-t);
		}
	}
	cout << kq;
}