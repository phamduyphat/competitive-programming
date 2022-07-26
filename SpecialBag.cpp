#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=1e4+10;
int a[N],n,q,x,j=1,ans;
stack<int>st;
int main ()
{
    cin>>n;
    forin(i,1,n)cin>>a[i];
    cin>>q>>x;
    while(q--)
    {
        string s;cin>>s;
        if(s[0]=='H')
        {
            st.push(a[j]);
            ans+=a[j];
            j++;
        }
        else
        {
            ans-=st.top();
            st.pop();
        }
        if(ans==x)
        {
            cout<<st.size();
            return 0;
        }
    }
}
