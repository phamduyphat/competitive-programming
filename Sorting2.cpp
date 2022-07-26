#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
#define forv(a,b) for(auto & a:b)
using namespace std;
typedef long long ll;
const int N=1e5+1;
vector<int> ke[N];
int n,slt,res,tmp,fr[N],d[N],a[N],s[N],kq=0;
void dfs(int u)
{
    fr[u]=1;
    tmp = min(tmp,a[u]);
    forv(v,ke[u])
	{
		if(fr[v]==0)
    	{
    		fr[v]=1;
        	res+=a[v];
        	slt++;
        	tmp = min(tmp,a[v]);
        	dfs(v);
    	}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	forin(i,1,n)
	{
		cin >> a[i];
		d[i]=a[i];
	}
	sort(d+1,d+n+1);
	forin(i,1,n) s[d[i]]=i;
	forin(i,1,n)
	{
		if(a[i]!=d[i])
		{
			ke[i].push_back(s[a[i]]);
		}
	}
	forin(i,1,n)
	{
		if(fr[i]==0)
		{
			slt=1;
			tmp=1e6+1;
			res=a[i];
			dfs(i);
			kq+=res+min((slt-2)*tmp,(slt+1)*d[1]+tmp);
		}
	}
	cout << kq;
}
