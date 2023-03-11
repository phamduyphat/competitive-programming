#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<= b;i++)
#define ll long long
using namespace std;
const int N = 1e3+10;
int n, m, k, ans;
ll t;
ll a[N][N], s[N][N];
bool intersect(int ii, int jj, int i, int j, int oo, int kk, int o, int k) {
    if(i >= oo && j >= kk && o >= ii && k >= jj) return 0;
    return 1;
}
void sub12() {
    forin(i,1,m) forin(j,1,n) {
        int f = 1, l = min(i, j);
        while(f <= l) {
            int mid = (f + l)>>1;
            ll sum = s[i][j] - s[i - mid][j] - s[i][j - mid] + s[i - mid][j - mid];
            if(t >= sum) {
                ans = max(ans, mid);
                f = mid + 1;
            }
            else l = mid - 1;
        }
    }
    cout<<ans * ans;
    return;
}
void sub3() {
    forin(i,1,m) forin(j,1,n) forin(p,1,min(i, j)) {
        forin(o,1,m) forin(k,1,n) forin(q,1,min(o, k)) {
            int ii = i - p + 1, jj = j - p + 1;
            int oo = o - q + 1, kk = k - q + 1;
            if(intersect(ii, jj, i, j, oo, kk, o, k)) {
                ll sum1 = s[i][j] - s[ii - 1][j] - s[i][jj - 1] + s[ii - 1][jj - 1];
                ll sum2 = s[o][k] - s[oo - 1][k] - s[o][kk - 1] + s[oo - 1][kk - 1];
                if(sum1 + sum2 <= t) ans = max(ans, p * p + q * q);
            }
        }
    }
    cout<<ans;
    return;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin>>m>>n>>k>>t;
    forin(i,1,m) forin(j,1,n) {
        cin>>a[i][j];
        s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
    }
    if(k == 1) {sub12(); return 0;}
    sub3();
    return 0;
}