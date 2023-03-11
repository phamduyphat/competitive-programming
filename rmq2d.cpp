//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 505
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define vi vector<int>
#define vii vector< pii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "rmq2d"
#define hm(x) (1 << (x))

using namespace std;

typedef long long ll;
typedef long double ld;

int m, n, f[9][9][maxn][maxn];

void Init(){
    cin >> m >> n;
    For(i, 1, m)
        For(j , 1, n) cin >> f[0][0][i][j];
//---------tinh F[0][j]
    For(j, 1, 8)
        For(u, 1, m)
            For(v, 1, n - hm(j) + 1)
                f[0][j][u][v] = min(f[0][j-1][u][v], f[0][j-1][u][v+hm(j-1)]);
//---- Tinh f[i][j]
    For(i, 1, 8) For(j, 0, 8)
        For(u, 1, m - hm(i) + 1)
            For(v, 1, n - hm(j) + 1)
        f[i][j][u][v] = min(f[i-1][j][u][v], f[i-1][j][u+ hm(i-1)][v]);


}

int Getmin(int u, int v, int p, int q){
    int k = log2(p-u+1);
    int l = log2(q-v+1);
    int r = p - hm(k) + 1;
    int s = q - hm(l) + 1;
    int m1 = min(f[k][l][u][v], f[k][l][u][s]);
    int m2 = min(f[k][l][r][v], f[k][l][r][s]);
    //cout << m1 << " " << m2 << "\n";
    return min(m1, m2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    Init();
    int qu; cin >> qu;
    while (qu--){
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        cout << Getmin(u, v, p, q) << "\n";
    }
    return 0;
}

