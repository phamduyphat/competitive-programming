#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a; i<=b; i+=2)
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 3e5+10;
int b[N],g[N];
ii ans[N];
long long pw(int a, int b)
{
    if (a==1) return 1;
	else
	{
        if (b==1) return a;
        long long tmp=pw(a,b/2);
        tmp=(tmp*tmp);
        if (b%2==0) return tmp;
        else return (tmp*a);
	}
}
int main()
{

        freopen("input.inp","r",stdin);
        freopen("output.out","w",stdout);

    int q;
    cin >> q;
    priority_queue<ii,vector<ii>,greater<ii>>qm1,qf2;
    priority_queue<ii>qf1,qm2;
    int dem=0;
    int m;
    cin >> m;
    forin(i,1,m)
    {
        cin >> b[i];
        if(b[i]>0) qm1.push({b[i],i});
        else if(b[i]<0) qm2.push({b[i],i});
    }
    int f;
    cin >> f;
    forin(i,1,f)
    {
        cin >> g[i];
        if(g[i]<0) qf1.push({g[i],i});
        else if(g[i]>0) qf2.push({g[i],i});
    }
    while(!qm1.empty()&&!qf1.empty())
    {
        if(qm1.top().fi+qf1.top().fi<0)
        {
            dem++;
            ans[dem].fi=qm1.top().se;
            ans[dem].se=qf1.top().se;
            qf1.pop();

        }
        qm1.pop();
    }
    while(!qm2.empty()&&!qf2.empty())
    {
        if(qm2.top().fi+qf2.top().fi<0)
        {
            dem++;
            ans[dem].fi=qm2.top().se;
            ans[dem].se=qf2.top().se;
            qf2.pop();
        }
        qm2.pop();
    }
    cout << dem << "\n";
    while(dem--)
    {
        cout << ans[dem+1].fi << " " << ans[dem+1].se << "\n";
    }

}

