#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;++i)
#define forde(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
struct Trie {
	Trie* child[2];
	int cnt;
	Trie() {
		forin(i,0,1) child[i] = 0;
		cnt = 0;
	}
};
Trie* root = new Trie();
void insert(string s) {
	Trie* p = root;
	forin(i,0,s.size()-1) {
		int nxt = s[i] - '0';
		if(p->child[nxt]==0) p->child[nxt] = new Trie();
		p = p->child[nxt];
		p->cnt++;
	}
}
int search(int k) {
	Trie* p = root;
	int ans = 0;
	forde(i,31,0) {
		if(p->child[0]!=0 && k <= p->child[0]->cnt) {
			p = p->child[0];
		}
		else if(p->child[1]!=0) {
			if(p->child[0]!=0) k -= p->child[0]->cnt;
			p = p->child[1];
			ans |= (1<<i);
		}
	}
	return ans;
}
int main () {
	cin.tie(0)->sync_with_stdio(0);
	if(fopen("Task.inp","r")) {
		freopen("Task.inp","r",stdin);
		freopen("WA.out","w",stdout);
	}
	int t; cin>>t;
	while(t--) {
		int tp; cin>>tp;
		if(tp==1) {
			int a; cin>>a;
			string s;
			forde(i,31,0) {
				if((a>>i)&1) s.push_back('1');
				else s.push_back('0');
			}
			insert(s);
		}
		else {
			int a; cin>>a;
			cout<<search(a)<<"\n";
		}
	}
}