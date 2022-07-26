#include<bits/stdc++.h>
#define ll long long
#define forin(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=1e6+10;
int a[N],f[N];
int main ()
{
    int t;cin>>t;
    while(t--)
    {
        stack<int>x;
        int n;cin>>n;
        forin(i,1,n)cin>>a[i];
        forin(i,1,n)
        {
            f[i]=1;
            while(!x.empty()&&a[x.top()]<=a[i])x.pop();
            if(!x.empty())f[i]=i-x.top();
            x.push(i);
        }
        forin(i,1,n)cout<<f[i]<<" ";
        forin(i,1,n){a[i]=0;f[i]=0;}
    }
}
