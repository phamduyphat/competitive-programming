#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int res=200;
const int N=20;
int n;
int a[N];
bool kt1()
{
    forin(i,1,n) if (a[i]==0) return false;
    return true;
}
bool kt2()
{
    forin(i,1,n) if (a[i]) return false;
    return true;
}
void thaydoi(int i)
{
    if (a[i]) a[i]=0;
    else a[i]=1;
}
void duyet (int i,int doi)
{
    if (i>n)
    {
        if (kt1()) res=min(res,doi);
        if (kt2()) res=min(res,doi+1);
    }
    else
    {
        duyet(i+1,doi);
        thaydoi(i);
        duyet(i+1,doi+1);
        thaydoi(i+1);
        thaydoi(i-1);
        duyet(i+1,doi+1);
        thaydoi(i);
        thaydoi(i+1);
        thaydoi(i-1);
    }
}
int main()
{
     cin>>n;
     forin(i,1,n) cin>>a[i];
     duyet (1,0);
    cout <<res;
}

