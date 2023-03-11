#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
const int mod = 1e9+7, N = 1e5+10;
ll dp[N];
struct Trie {
	Trie* child[26];
	int cnt;
	Trie() {
		forin(i,0,25) child[i] = 0;
		cnt = 0;
	}
};
Trie* root = new Trie();
void insert(string s) {
	Trie* p = root;
	forin(i,0,s.size()-1) {
		int nxt = s[i] - 'a';
		if(p->child[nxt]==0) p->child[nxt] = new Trie();
		p = p->child[nxt];
	}
	p->cnt++;
}
void dynamic(string s,int i) {
	Trie* p = root;
	forin(j,0,s.size()-1) {
		int nxt = s[j] - 'a';
		if(p->child[nxt]==0) return;
		p = p->child[nxt];
		if(p->cnt>0) {
			dp[i+j+1] += dp[i];
			dp[i+j+1] %= mod;
		}
	}
}
int main () {
	cin.tie(0)->sync_with_stdio(0);
	if(fopen("Task.inp","r")) {
		freopen("Task.inp","r",stdin);
		freopen("WA.out","w",stdout);
	}
	int t; cin>>t;
	while(t--) {
		string s; cin>>s;
		insert(s);
	}
	string a; cin>>a;
	int n = a.size()-1;
	Trie* pp = root;
	forin(i,0,n) {
		int nxt = a[i] - 'a';
		if(pp->child[nxt]==0) break;
		pp = pp->child[nxt];
		if(pp->cnt) dp[i] = 1;
	}
	forin(i,0,n) dynamic(a.substr(i+1,a.size()-i), i);
	cout<<dp[n];
}