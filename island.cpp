#include<bits/stdc++.h>
using namespace std;
#define maxn 1002
#define INF 0x3f3f3f3f
int n,m,a[maxn][maxn],dx[4]={0,-1,0,1},dy[4]={-1,0,1,0},ma=-1,mi=INF,sizee;
void dfs(int u,int v)
{
    sizee++;
    a[u][v]=0;
    for(int k=0; k<4; k++)
    {
        int x1=u+dx[k], y1=v+dy[k];
        if(a[x1][y1]==1 && x1>=1&&x1<=n && y1<=m&&y1>=1) dfs(x1,y1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin >> a[i][j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]!=0)
            {
                sizee=0;
                dfs(i,j);
                ma=max(ma,sizee);
                mi=min(mi,sizee);
            }
        }
    }
    if(ma==-1) cout << ma;
    else cout << fixed << setprecision(5) << 1.0*ma/mi;
    return 0;
}
