#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forv(a,b) for(auto & a : b)
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 2;
vector<int> ke[N];
int deg[N], ts[N];
bool fr[N];
int n,x,y,k;
priority_queue<pii, vector<pii>, greater<pii> > q;
int main() {
  	ios_base::sync_with_stdio(0);
   	cin.tie(NULL); 
   	cout.tie(NULL);
	cin >> n >> k;
	int m = n - k - 1;
	forin(i, 1, n - 1) {
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
	forin(i, 1, n) 
	{
		ts[i] = 1;
	}
	forin(i,1,n)
	{
		if (deg[i] == 1) {
			fr[i] = false;
			q.push(make_pair(ts[i], i));
		}
	}
	int kq = 0;
	forin(j,1,m)
	{
		int u = q.top().second;
		q.pop();
		kq += ts[u];
		forv (v, ke[u]) {
			if (!fr[v]) 
			{
				deg[v]--;
				ts[v] += ts[u];
			}
			if (deg[v] == 1) q.push(make_pair(ts[v], v));
		}
	}
	cout << kq;
}