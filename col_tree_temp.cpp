#include <bits/stdc++.h>
#define forin(i,a,b) for(int i = a;i <= b;i ++)
#define forde(i,a,b) for(int i = a;i >= b;i --)
#define re(i,a) for(int i = 0; i < a; i ++)
#define forv(a,b) for(auto & a : b)
#define fi first
#define pii pair<int,int>
#define se second
using namespace std;
const int N = 1e5 + 10;
vector<int> ke[N];
int color[N],ans[N];
int n,m,root;
set<int> s[N];
void dfs(int u, int pre){
	s[u].insert(color[u]);
	forv(v,ke[u]){
		if(v==pre) continue;
		dfs(v,u);
		if(s[v].size() > s[u].size()) swap(s[v],s[u]);
		forv(k,s[v]) s[u].insert(k);
		s[v].clear();
	}
	ans[u] = s[u].size();
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("COLTREE.INP","r",stdin);
	freopen("COLTREE.OUT","w",stdout);
	cin >> n >> m >> root;
	forin(i,1,n-1){
		int u,v; cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	forin(i,1,n) cin >> color[i];
	dfs(root,root);
	while(m--){
		int u; cin >> u;
		cout << ans[u] << "\n";
	}
	return 0;
}
/*
4 2 1
1 2
2 4
2 3
10 
20 
20 
30
1
2
*/