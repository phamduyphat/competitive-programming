//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "queue"
#define maxn 22
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define bit(i, x)((x >> i) & 1)
 
using namespace std;
 
int n, a[maxn][maxn];
long long dp[1<<maxn];
 
void Nhap()
{
    cin >> n;
    for (int i = 0; i < n; i++) // nguoi 0->n-1
        for (int j = 1; j <= n; j++) cin >> a[i][j];
}
 
void QHD()
{
    dp[0] = 0;
    for (int x = 0; x < (1<<n); x++){
        int k = __builtin_popcount(x);// so bit 1 của x
        // sử dụng dp[x] để tối ưu dp[u] phía sau
        for (int i = 0; i < n; i++)
            if (bit(i,x) == 0) // nguoi i chua co trong hang
            {
                int u = x + (1<<i); // cho nguoi i vao hang
                dp[u] = max(dp[u], dp[x] + a[i][k+1]);
            }
    }
    cout << dp[(1 << n) - 1];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    Nhap();
    QHD();
 
    return 0;
}
 