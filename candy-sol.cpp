#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;++i)
#define forde(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N = 2e3 + 10, base = 1e3;
int n, id, it;
int a[N], ans[N];
bitset<2001> dp[1<<20];
void sub12() {
    dp[0][base] = 1;
    forin(mask,1,(1 << n) - 1) {
        forin(i,1,n) if((mask>>(i - 1))&1) {
            int pre = mask ^ (1 << (i - 1));
            bitset<2001> f1 = (dp[pre] << base) >> base;
            bitset<2001> f2 = (dp[pre] >> base + 1) << base + 1;
             f1 = dp[mask] | (f1 << a[i]);
             f2 = dp[mask] | (f2 >> a[i]);
            dp[mask] |= f1 | f2;
        }
    }
    int mask = (1 << n) - 1;
    forin(i,0,2000) if(dp[mask][i]) id = i;
    while(mask) {
        forin(i,1,n) if((mask >> (i - 1)) & 1) {
            int pre = mask ^ (1 << (i - 1));
            if(id - a[i] <= base && id - a[i] >= 0 && dp[pre][id - a[i]]) {
                id -= a[i]; ans[++it] = i;
                mask = pre; break;
            }
            if(id + a[i] > base && id + a[i] <= 2000 && dp[pre][id + a[i]]) {
                id += a[i]; ans[++it] = i;
                mask = pre; break;
            }
        }
    }
    forde(i,it,1) cout<<ans[i]<<" ";
}
void sub3() {
    forin(i,1,n) cout<<i<<" ";
}
int main () {
    cin.tie(0)->sync_with_stdio(0);
    if(fopen("Task.inp","r")) {
        freopen("Task.inp","r",stdin);
        freopen("WA.out","w",stdout);
    }
    if(fopen("Candy.inp","r")) {
        freopen("Candy.inp","r",stdin);
        freopen("Candy.out","w",stdout);
    }
    cin>>n;
    forin(i,1,n) cin>>a[i];
    if(n <= 20) sub12();
    else sub3();
}
