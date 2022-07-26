#include<bits/stdc++.h>
#define ll long long
#define forin(i, a, b) for(ll i = a; i <= b; i++)
using namespace std;
int d[1000010];
int main()
{
    int q;
    cin >> q;
    forin(i,1,q)
    {
        memset(d,0,sizeof(d));
        queue <int> q;
        ll n;
        cin >> n;
        q.push(n);
        d[n]=1;
        while(!q.empty() || n==0)
        {
            if(d[q.front()-1]==0||d[q.front()-1]>d[q.front()]+1)
            {
                q.push(q.front()-1);
                d[q.front()-1]=d[q.front()]+1;
            }
            if(q.front()>=4)
            {
                for(int j=2; j*j<=q.front(); j++)
                {
                    if(q.front()%j==0)
                    {
                        if(d[q.front()/j]==0||d[q.front()/j]>d[q.front()]+1)
                        {
                            q.push(q.front()/j);
                            d[q.front()/j]=d[q.front()]+1;
                        }
                    }
                }
            }
            q.pop();
            if (d[0]) break;
        }
        cout << d[0] - 1 << "\n";
    }
}
