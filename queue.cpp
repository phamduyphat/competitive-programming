#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a; i<=b; i++)
#define forde(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
const int e = 1e9+7;
long long mul(long long a, long long b)
{
    long long res = 0;
    a %= e;
    while (b)
    {
        if (b%2==1) res = (res + a) % e;
        a = (2*a) % e;
        b/=2;
    }
    return res;
}
long long pw(int a, int b)
{
    if(b==1) return a;
    long long tmp = pw(a,b/2);
    tmp = mul(tmp,tmp);
    if(b%2==0) return tmp;
    else return mul(tmp,a);
}
int main()
{
    long long n,p,q;
    cin >> n >> p >> q;
    forin(i,1,n)
    {
        int a;
        cin >> a;
    }

    long long ans;
    vector<long long> fact(n+1);
    fact[0]=1;
    forin(i,1,fact.size()-1) fact[i]=mul(fact[i-1],i);
    vector<long long> ifact(fact.size());
    ifact.back()=pw(fact.back(),e-2);
    forde(i,ifact.size()-2,0) ifact[i] = mul(ifact[i+1],(i+1));
    ans=mul(mul(mul(fact[n-1],ifact[n-p-q+1]),ifact[p-1]),ifact[q-1]);
    cout << ans-1;
}
