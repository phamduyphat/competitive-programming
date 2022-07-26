#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a; i<=b; i++)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10;
int pos[N],a[N],b[N],d[N],f[N];
int tmp,dem;
vector<pair<int, int>> ke1[N];
vector<int> ke2[N];
queue<int> q;
void add1(int u, int v, int k)
{
	ke1[u].push_back(make_pair(v,k));
	ke1[v].push_back(make_pair(u,k));
}
void add2(int u,int v)
{
    ke2[u].push_back(v);
    ke2[v].push_back(u);
}
void bfs(int u)
{
    q.push(u);
    f[u] = 1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        forv(v,ke2[x])
        {
			if (!f[v])
            {
				f[v] = 1;
				q.push(v);
			}
        }
    }
}
void dfs(int u, int k)
{
	dem++;
	d[u] = 1;
	forv(v,ke1[u])
	{
		if (d[v.fi]) continue;
		if (v.se)
		{
		    tmp += 1-k;
		    dfs(v.fi,1-k);
		}
		else
		{
		    tmp += k;
		    dfs(v.fi,k);
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n;
	long long ans1=0;
	long long ans2=1;
	cin >> n;
	forin(i,1,n) cin >> a[i];
	forin(i,1,n) cin >> b[i];
	forin(i,1,n)
	{
		int j1 = pos[a[i]];
		int j2 = pos[b[i]];
		if (j1)
        {
			if (a[i] == a[j1]) add1(i,j1,1);
			else add1(i,j1,0);
		}
		if (j2)
		{
			if (b[i] == b[j2]) add1(i,j2,1);
			else add1(i,j2,0);
		}
		pos[a[i]] = i;
		pos[b[i]] = i;
	}
	forin(i,1,n)
	{
		if (d[i]) continue;
		dem = 0;
		tmp = 0;
		dfs(i,0);
		ans1 += min(dem-tmp,tmp);
	}
    forin(i,1,n-1) forin(j,i+1,n) if (a[i]==a[j] || a[i]==b[j] || b[i]==b[j] || b[i]==a[j]) add2(i,j);
    forin(i,1,n)
    {
        if (!f[i])
        {
            bfs(i);
            ans2*=2;
        }
    }
    forin(i,1,n) if(a[i]==b[i]) ans2/=2;
	cout << ans2 << " " << ans1;
}
