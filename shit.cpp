#include<bits/stdc++.h>
#define forin(i,a,b) for(long long i=a;i<=b;i++)
using namespace std;
long long f[100],a[10010],b[14]={0,2,3,5,7,11,13,17,19,23,29,31,37,41};
void fact(long long m)
{
    forin(i,1,13)
    {
        long long dem = 0;
        while(m % b[i] == 0)
            {
            dem++;
            m/=b[i];
            }
        f[b[i]]=max(f[b[i]],dem);
    }
}
int main()
{
    long long res=1;
    long long n,k;
    cin >> n >> k;
    forin(i,1,n)
    {
        cin >> a[i];
        fact(a[i]);
    }
    forin(i,1,13)
    {
        if(f[b[i]])
        {
            if(f[b[i]]%k==0) f[b[i]]/=k;
            else
            {
                f[b[i]]/=k;
                f[b[i]]++;
            }
        }
    }
    forin(i,1,13)if(f[b[i]])forin(j,1,f[b[i]]) res*=b[i];
    cout << res;
}
