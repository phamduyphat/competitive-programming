#include <bits/stdc++.h>
#define forin(i,a,b) for(int i=a; i<=b; i++)
#define forde(i,a,b) for(int i=a; i>=b; i--)
#define forv(a,b) for(auto&a:b)
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 10;
ii x[N],y[N],z[N];
int par[N];
struct planet
{
    int u,v,w;
}edge[N];

bool ss(planet a, planet b)
{
    return a.w < b.w;
}
int root (int x)
{
    return par[x] < 0 ? x : (par[x] = root(par[x]));
}
bool join(int x, int y)
{
    if ((x = root(x)) == (y = root(y))) return 0;
    if (par[y] < par[x]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen ("tunnel.inp", "r"))
    {
        freopen ("tunnel.inp", "r", stdin);
        freopen ("tunnel.out", "w", stdout);
    }
//    if (fopen ("task.inp.txt", "r"))
//    {
//        freopen ("task.inp.txt", "r", stdin);
//        freopen ("WA.out.txt", "w", stdout);
//    }
    int n;
    cin >> n;
    forin(i,1,n) par[i] = -1;
    forin(i,1,n)
    {
        cin >> x[i].fi >> y[i].fi >> z[i].fi;
        x[i].se = y[i].se = z[i].se = i;
    }
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    sort(z+1,z+n+1);
    int cnt=0;
    forin(i,1,n-1)
    {
        int dist = abs(x[i].fi - x[i+1].fi);
        edge[++cnt] = {x[i].se,x[i+1].se,dist};
    }
    forin(i,1,n-1)
    {
        int dist = abs(y[i].fi - y[i+1].fi);
        edge[++cnt] = {y[i].se,y[i+1].se,dist};
    }
    forin(i,1,n-1)
    {
        int dist = abs(z[i].fi - z[i+1].fi);
        edge[++cnt] = {z[i].se,z[i+1].se,dist};
    }
    sort(edge+1,edge+cnt+1,ss);
    int ans=0;
    forin(i,1,cnt)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        if(join(u,v)) ans+=w;
    }
    cout << ans;
}   