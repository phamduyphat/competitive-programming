#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
#define forde(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 210; int n; 
int cc[N],cp[N],col[N],a[N], st; 
void dat(int i, int j, int k) 
{
    cc[n+i-j]+=k; cp[i+j]+=k; col[j]+=k;
}
bool kt(int i, int j ) 
{
    if (cc[n+i-j]) return 0 ; if (cp[i+j] ) return 0 ; if (col[j]) return 0;
    return 1;
}
void duyet(int i) 
{
    if (st) return ;
    if (i>n) 
    {
        forin(j,1,n) cout <<a[j]<<" ";
        st++;
    }
    else 
    {
        int ans = 101 , next = 0;
        forin(j,1,n) 
        {
            if (a[j]) continue;
            int tmp = 0;
            forin(k,1,n) if (kt(j,k)) tmp ++;
            if(tmp < ans ) 
            {
                ans =tmp ;
                next = j; 
            }

        }
        if (next == 0) return ; 
        forin(j,1,n) 
        {
            if (kt(next, j)) 
            {
                dat(next, j, 1); 
                a[next] = j; 
                duyet (i+1); 
                dat(next, j, -1);
                a[next] = 0;
            }
        }
    }
}
int main()
{
    while (cin>>n)
    {
        st = 0;
        int tmp = 0;
        forin(i,1,n) 
        {
            cin>>a[i]; 
            if (a[i]) 
            {
                dat(i,a[i],1);
                tmp++;
            }
        }
        duyet(tmp+1);
        cout <<"\n";
        memset(a,0,sizeof(a));
        memset(cc,0,sizeof(cc));
        memset(cp, 0, sizeof(cp));
        memset(col, 0, sizeof(col));
    }
}