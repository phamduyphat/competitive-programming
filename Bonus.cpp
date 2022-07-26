#include<bits/stdc++.h>
#define ll long long
#define forin(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=1e3+10;
ll a[N][N],f[N][N],ma;
int main ()
{
    int n,k;cin>>n>>k;
    forin(i,1,n)forin(j,1,n)
    {
        cin>>a[i][j];
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
    } 
    forin(i,1,n)forin(j,1,n)ma=max(ma,f[i][j]+f[max(0,i-k)][max(0,j-k)]-f[i][max(0,j-k)]-f[max(0,i-k)][j]);
    cout<<ma;
}
