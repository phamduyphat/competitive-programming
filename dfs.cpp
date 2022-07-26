#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a; i<=b; i++)
#define forv(a,b) for(auto&a:b)
using namespace std;
const int N = 1e5 + 10;
vector<int> ke[N];
int f[N];
void dfs(int x) 
{
	f[x] = 1;
	forv(v,ke[x]) if (f[v] == 0) dfs(v);
}
int main() 
{
	int n,m,ans=0; 
	cin >> n >> m;
	forin(i,1,m)  
	{
		int u, v; 
		cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	forin(i,1,n) 
	{
		if (!f[i])
        {
            ans++;
            dfs(i);
        }
	}
	cout << ans;
}