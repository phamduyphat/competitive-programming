#include <bits/stdc++.h>
#define maxnm 300001
#define mp make_pair
#define ft first
#define sc second
#define tr(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

using namespace std;
typedef long long lint;
typedef pair<lint,int> LI;
typedef pair<int,int> II;
typedef pair<II,int> III;

int n, m;
vector<int> g[maxnm];
III edge[maxnm];
set<LI> q;
int cl[maxnm], prev[maxnm];
lint kc[maxnm];
int xp;
int x[maxnm];

void Dijkstra() {
    fill(cl,cl+n+1,0);
    q.clear();
    cl[xp]=1; kc[xp]=0; prev[xp]=0; q.insert(mp(kc[xp],xp));
    while (!q.empty()) {
        LI node=*q.begin(); q.erase(node);
        int u=node.sc;
        tr(i,g[u]) {
            int k=*i;
            int v=(k>0) ? edge[k].ft.sc : edge[-k].ft.ft;
            int L=edge[abs(k)].sc;
            if (cl[v]==0) {
                kc[v]=kc[u]+L; cl[v]=1; prev[v]=abs(k);
                q.insert(mp(kc[v],v));
            } else if (kc[v]>kc[u]+L) {
                q.erase(mp(kc[v],v));
                kc[v]=kc[u]+L; prev[v]=abs(k);
                q.insert(mp(kc[v],v));
            } if (kc[v]==kc[u]+L) {
                int wt=edge[prev[v]].sc;
                if (wt>L) prev[v]=abs(k);
            }
        }
    }
}


int main() {
    freopen("hroads.inp","r",stdin);
    freopen("hroads.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u, v, w; scanf("%d%d%d",&u,&v,&w);
        edge[i]=mp(mp(u,v),w);
    }
    scanf("%d",&xp);
    for(int i=1;i<=m;i++) {
        int u=edge[i].ft.ft, v=edge[i].ft.sc;
        g[u].push_back(i);
        g[v].push_back(-i);
    }
    Dijkstra();
    lint sum=0;
    int slx=0;
    for(int i=1;i<=n;i++) if (prev[i]!=0) {
        sum+=edge[prev[i]].sc;
        x[++slx]=prev[i];
    }
    printf("%I64d\n",sum);
    for(int i=1;i<=slx;i++) printf("%d ",x[i]);
}
