#include<bits/stdc++.h>
using namespace std;
  #define ll long long
#define forin(i,a,b) for(int i=a;i<=b;++i)
long long a[1001][1001];
long long b[3000][3000];
long long f[3000][3000];
ll h=0;
int main ()
{
    long long n,k;
    long long ma;
    cin >> n >> k;
    ll h=0;
    k=2*k+1;
    for (int i=1; i<=n;i++)
    {
        for (int j=1;j<=n;j++) cin >> a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
       for (int j=1;j<=n;j++)
            {
                b[i-j+n][i+j-1]=a[i][j];

            }
    }
    for (int i=1; i<=2*n-1;i++)
    {
        for (int j=1;j<=2*n-1;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+b[i][j];
        }
    }
    forin(i,1,n)forin(j,1,n)ma=max(ma,f[i][j]+f[max(h,i-k)][max(h,j-k)]-f[i][max(h,j-k)]-f[max(h,i-k)][j]);
    cout<<ma;
}
