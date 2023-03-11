#include <bits/stdc++.h>
#include <vector>
#define forin(i, a, b) for (long long i = a; i <= b; i++)
#define forde(i,a,b) for(long long i=a;i>=b;i--)
#define forv(a, b) for (auto& a : b)
#define fi first
#define se second
using namespace std;
const long long N = 1e3+100;
long long f[N][N],j[N],l[N],m,n;
struct hiv
{
    int x,y;
};
bool in(hiv a)
{
    if(a.x>=1 && a.x<=m && a.y>=1 && a.y<=n)return true;
    else return false;
}
int main()
{
    int k;
    cin >> m >> n >> k;
    forin(i,1,k)
    {
        cin >> j[i] >> l[i];
        f[j[i]][l[i]]=1;
    }
    long long cnt = 0;
    forin(r,1,min(m,n)-1)
       {
           cnt+=r*(m-r)*(n-r);
       }
       long long tong = 0;
    forin(i,1,k)
    {
        hiv a;
        a.x=j[i];
        a.y=l[i];
        forin(r,1,min(m,n)-1)
        {
            forin(h,0,r-1)
            {
                int x = a.x;
                int y = a.y-h;
                hiv b,c,d;
                b.x=x+h;
                b.y=y+r;
                c.x=x+r;
                c.y=y+r-h;
                d.x=x+r-h;
                d.y=y;
                if(in(b) && in(c) && in(d))tong++;
            }
        }
    }
    forin(i,1,k)
    {
        hiv b;
        b.x=j[i];
        b.y=l[i];
        forin(r,1,min(m,n)-1)
        {
            forin(h,0,r-1)
            {
                int x = b.x-h;
                int y = b.y-r;
                hiv a,c,d;
                a.x=x;
                a.y=y+h;
                c.x=x+r;
                c.y=y+r-h;
                d.x=x+r-h;
                d.y=y;
                if(in(a) && in(c) && in(d))if(f[a.x][a.y]==0)tong++;
            }
        }
    }
  forin(i,1,k)
    {
        hiv c;
        c.x=j[i];
        c.y=l[i];
        forin(r,1,min(m,n)-1)
        {
            forin(h,0,r-1)
            {
                int x = c.x-r;
                int y = c.y-r+h;
                hiv a,b,d;
                a.x=x;
                a.y=y+h;
                b.x=x+h;
                b.y=y+r;
                d.x=x+r-h;
                d.y=y;
                if(in(a) && in(b) && in(d))if(f[a.x][a.y]==0 && f[b.x][b.y]==0)tong++;
            }
        }
    }
    forin(i,1,k)
    {
        hiv d;
        d.x=j[i];
        d.y=l[i];
        forin(r,1,min(m,n)-1)
        {
            forin(h,0,r-1)
            {
                int x = d.x-r+h;
                int y = d.y;
                hiv a,b,c;
                a.x=x;
                a.y=y+h;
                b.x=x+h;
                b.y=y+r;
                c.x=x+r;
                c.y=y+r-h;
                if(in(a) && in(b) && in(c))if(f[a.x][a.y]==0 && f[b.x][b.y]==0 && f[c.x][c.y]==0)tong++;
            }
        }
    }
    cout << cnt-tong;
}
