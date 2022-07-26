#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a; i<=b; i++)
#define forv(a,b) for(auto&a:b)
using namespace std;
const int N = 1e3 + 10;
vector<int> ke[N];
int deg[N];
int main()
{
    int n,m;
    cin >> n >> m;
    deg[1]=1;
    forin(i,1,m)
    {
        int p;
        cin >> p;
        if(p==2)
        {
            int u,v; cin >> u >> v;
            ke[u].push_back(v);
            if ((!deg[v] || deg[v]-1>deg[u]) && deg[u])
            {
                queue<int> q;
                deg[v] = deg[u] + 1;
                q.push(v);
                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    forv(y,ke[x])
                    {
                        if (!deg[y] || deg[y]-1>deg[x])
                        {
                            deg[y] = deg[x] + 1;
                            q.push(y);
                        }
                    }
                }
            }
        }
        else
        {
            int x;
            cin >> x;
            cout << deg[x]-1 << "\n";
        }
    }
}
