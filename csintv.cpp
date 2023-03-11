#include <bits/stdc++.h>
using namespace std;
#define task "csintv"
const int maxn = 1e6+5;

struct dt{
	int l,r;
	bool operator <(const dt&T){
		if(r == T.r) return l > T.l;
		return r < T.r;
	}
} a[maxn];

int st[4*maxn];
int n;
int dp[maxn]; 
int back[maxn];

int merge(int a,int b){
	if(dp[a] < dp[b]) return b;
	return a;
}

void upd(int l,int r,int i,int val,int id){
	if(l > i || r < i) return;
	if(l == r && l == i){
		if(dp[st[id]] < dp[val]){
			st[id] = val;
		}
		//cout << l << ' ' << r << ' ' << id << ' ' << i <<  ' ' << st[id] << endl;
		return;
	}
	int m = (l+r)/2;
	upd(l,m,i,val,id*2);
	upd(m+1,r,i,val,id*2+1);
	st[id] = merge(st[id*2],st[id*2+1]);
}

int get(int l,int r,int ql,int qr,int id){
	if(l > qr || r < ql) return 0;
	if(ql <= l && r <= qr){
		return st[id];
	}
	int m = (l+r)/2;
	int res1 = get(l,m,ql,qr,id*2);
	int res2 = get(m+1,r,ql,qr,id*2+1);
	return merge(res1,res2);
}

void sub1(){
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i].l <= a[j].l){
				if(dp[i] < dp[j]+1){
					dp[i] = dp[j]+1;
					back[i] = j;
				}
			}
		}
		if(dp[ans] < dp[i]) ans = i;
	}
	cout << dp[ans]+1 << endl;
	while(back[ans]){
		cout << a[ans].l << ' ' << a[ans].r << '\n';
		ans = back[ans];
	}
	cout << a[ans].l << ' ' << a[ans].r;
}

int mx = 0;
vector<int> bruh;

void sub2(){
	int ans = 0;
	for(int i=1;i<=n;i++){
		int lmao = lower_bound(bruh.begin(),bruh.end(),a[i].l)-bruh.begin()+1;
		int f = get(1,mx,lmao,mx,1);
		dp[i] = max(dp[i],dp[f]+1);
		back[i] = f;
		upd(1,mx,lmao,i,1);
		if(dp[ans] < dp[i]) ans = i;
	}
	cout << dp[ans] << endl;
	while(back[ans]){
		cout << a[ans].l << ' ' << a[ans].r << '\n';
		ans = back[ans];
	}
	cout << a[ans].l << ' ' << a[ans].r;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].l  >> a[i].r;
		bruh.push_back(a[i].l);
		bruh.push_back(a[i].r);
		mx = max(mx,a[i].r);
	}
	sort(bruh.begin(),bruh.end());
	bruh.resize(unique(bruh.begin(),bruh.end())-bruh.begin());
	mx = lower_bound(bruh.begin(),bruh.end(),mx)-bruh.begin()+1;
	sort(a+1,a+n+1);
	sub2();
}