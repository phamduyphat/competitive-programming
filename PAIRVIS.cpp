#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=5e5 +10;
long long h[N];
long long f[N];
long long t[N];
long long x[N];
int main()
{
    stack <long long > s;
    stack<long long> s2,s3;
    int n; cin>>n;
    forin(i,1,n) cin>>h[i];
    long long kq=0;
    forin(i,1,n)
    {

        while (!s.empty()&&h[s.top()]<h[i-1]) s.pop();
        if (i>1) s.push(i-1);
        if (!s.empty()) f[i]=s.size();
        while (!s2.empty()&&h[s2.top()]<=h[i]) s2.pop();
        //if (!s2.empty()) t[i]=s2.size();
        if (!s2.empty()) x[i]=s2.top();
        s2.push(i);
        while (!s3.empty()&&h[s3.top()]<h[i]) s3.pop();
        if (!s3.empty()) t[i]=s3.size();
        s3.push(i);
    }
    forin(i,1,n)
    {
       // cout <<f[i]<<" "<<t[i]<<" "<<x[i]<<endl;
        kq+=f[i]-t[x[i]];

    }
    cout <<kq;
}
