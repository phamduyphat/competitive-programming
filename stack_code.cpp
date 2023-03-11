#include <bits/stdc++.h>
#define forin(i,a,b) for(int i=a; i<=b; i++)
#define forde(i,a,b) for(int i=a; i>=b; i--)
#define forv(a,b) for(auto&a:b)
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 2510;
ii a[N];
int w[N], c[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen ("stack.inp", "r"))
    {
        freopen ("stack.inp", "r", stdin);
        freopen ("stack.out", "w", stdout);
    }
    int n;
    cin >> n;
    int ans=0;
    forin(i,1,n) cin >> w[i];
    forin(i,1,n) cin >> c[i];
    forin(i,1,n)
    {
        a[i].fi = w[i] + c[i];
        a[i].se = i;
    }
    sort(a+1,a+n+1);
    priority_queue<int> pq;
    int t = 0, res = 0;
    forin(i,1,n)
    {
        ii x = a[i];
        if(c[x.se] >= t)
        {
            res++;
            t += w[x.se];
            pq.push(w[x.se]);
        }
        else
        {
            int b = pq.top() - w[x.se];
            if(b > 0 && c[x.se] >= t - pq.top())
            {
                t -= b;
                pq.pop();
                pq.push(w[x.se]);
            }
        }
        ans=max(ans, res);
    }
    cout << ans;
    return 0;
}
