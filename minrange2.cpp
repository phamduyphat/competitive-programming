#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "minrange3"
#define maxn 100001
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
 
using namespace std;
 
int n, m, a[maxn];
int tree[4*maxn], val[maxn*4];
 
void Init(int node, int l, int r)
{
    if (l == r){
        tree[node] = a[l];
        return;
    }
    int g = (l+r)>>1;
    Init(node*2, l, g);
    Init(node*2 + 1, g+1, r);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
void Push(int node){ // đẩy xuống nút con
    tree[node*2] += (val[node*2] = val[node]);
    tree[node*2+1] += (val[node*2+1] = val[node]);
    val[node] = 0;
}
 
int Getmin(int node, int l, int r, int u, int v)
{
    if (u > r || l > v) return MOD;
    if (l >= u && r <= v) return tree[node];
    int g = (l+r)>>1;
    if (val[node]) Push(node);
 
    int Trai = Getmin(2*node, l, g, u,v);
    int Phai = Getmin(2*node+1, g+1, r, u,v);
    return min(Trai, Phai);
}
 
void Update(int node, int l, int r, int u, int v, int w)
{
	// update đoạn u->v nhận giá trị w; cập nhật phần giao [u,v] và [l,r]
    if (u > r || l > v) return; // không giao
    if (l >= u && r <= v){ // [u,v] chứa [l,r]
        val[node] = w;
        tree[node] += w;
        // giá trị nhỏ nhất = giá trị được gán cả đoạn
        return;
    }
 
    if (val[node] != 0) Push(node);
	//đẩy thông tin update cũ xuống nút con
 
 
    int g = (l+r)/2;
    Update(2*node, l , g, u, v, w);
    Update(2*node+1, g+1 , r, u, v, w);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
    freopen ("input.inp","r",stdin);
    freopen ("output.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    Init(1,1,n);
    for (int i = 1; i <= m; i ++)
    {
        int type, u, v, w;
        cin >> type >> u >> v;
        if (type == 1) {
            cin >> w;
            Update(1, 1, n, u, v, w);}
            else cout << Getmin(1,1,n,u,v) << "\n";
    }
    return 0;
}