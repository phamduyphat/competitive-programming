#include <bits/stdc++.h>
#include <chrono>
#define sexually_transferred_diseases std				//Why not
using namespace sexually_transferred_diseases;
#define ll long long 
#define ar array 
const int mxN = 1e5;
int n, m;
vector<ar<ll, 2>> adj[mxN];
ll d[mxN];
int main()
{
    cin >> n >> m;
    for (int i = 0;  i < m ; ++ i)
    {
        int a, b, c;
        cin >> a >> b >> c, -- a, --b; 
        adj[a].push_back({c, b});
    }
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>> , greater <ar< ll, 2>>> pq;
    pq.push({0, 0}); 
    memset(d, 63, sizeof(d));
    d[0] = 0;
    while (pq.size())
    {
        ar<ll ,2> u = pq.top();
        pq.pop();
        if (u[0] > d[u[1]])
        {
            continue;
        }
        for(ar<ll, 2> v: adj[u[1]])
        {
            if(d[v[1]] > u[0] + v[0])
            {
                    d[v[1]] = u[0] + v[0];
                    pq.push({d[v[1]], v[1]});
            }
        }
    }
    for(int i = 0;i < n; ++i)
    {
        cout << d[i] << " ";
    }
}