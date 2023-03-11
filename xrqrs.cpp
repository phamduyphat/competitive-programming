#include <bits/stdc++.h>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ls(x) (((x) << 1) + 1)
#define rs(x) ((ls(x)) + 1)
#define md(a,b) (((a) + (b)) >> 1)
#define INF (1LL << 60LL)
 
int t, u, v, k, m, c, d, f, e, l, r, q;
int n = 0;
const int M = 1009995;
const int N = M;
struct Node {
	int cnt;
	Node * r;
	Node * l;
	Node () {
		this -> cnt = 0;
		this -> r = this;
		this -> l = this;
	}
	Node (int cnt, Node * l, Node * r) : cnt(cnt), l(l), r(r) {
	}
	Node * get (int s, int e, int val);
};
Node * Head[N];
Node * nul1;
struct node {
	int cnt;
	node * l;
	node * r;
	node () {
		this -> cnt = 0;
		this -> l = this;
		this -> r = this;
	}
	node (int cnt, node * l, node * r) : cnt(cnt), l(l), r(r) {
	}
	node * get (int depth, int val);
};
node * head[N];
node * nul2;
Node * Node::get (int s, int e, int val) {
	if (s == e) {
		return new Node(this -> cnt + 1, nul1, nul1);
	}
	else {
		if (val <= md(s, e)) {
			return new Node(this -> cnt + 1, this -> l -> get(s, md(s, e), val), this -> r);
		}
		else {
			return new Node(this -> cnt + 1, this -> l, this -> r -> get(md(s, e) + 1, e, val));
		}
	}
}
node * node::get (int depth, int val) {
	if (depth == 31) {
		return new node(this -> cnt + 1, nul2, nul2);
	}
	else {
		if (val & (1 << (31 - depth - 1))) {
			return new node(this -> cnt + 1, this -> l,  this -> r -> get(depth + 1, val));
		}
		else return new node(this -> cnt + 1, this -> l -> get(depth + 1, val), this -> r);
	}
}
int q4(Node * v, Node * c, int l, int r, int k) {
	while (true) {
		if (l == r) return l;
		int count = c -> l -> cnt - v -> l -> cnt;
		if (count >= k) {
			c = c -> l;
			v = v -> l;
			r = md(r, l);
		}
		else {
			k = k - count;
			v = v -> r;
			c = c -> r;
			l = md(r, l) + 1;
		}
	}
}
int q3(Node * v, Node * c, int l, int r, int k) {
	int ans = 0;
	while (true) {
		if (l == r) {
			ans += c -> cnt - v -> cnt;
			return ans;
		}
		if (k <= md(l, r)) {
			r = md(l, r);
			v = v -> l;
			c = c -> l;
		}
		else {
			ans += c -> l -> cnt - v -> l -> cnt;
			l = md(r, l) + 1;
			v = v -> r;
			c = c -> r;
		}
	}
}
int q1(node * v, node * c, int val) {
	int depth = 30;
	int ans = 0;
	while (depth >= 0) {
		if ((1 << depth) & val) {
			if (c -> l -> cnt - v -> l -> cnt != 0) {
				c = c -> l;
				v = v -> l;
				depth--;
				continue;
			}
			ans |= (1 << depth);
			c = c -> r;
			v = v -> r;
			depth--;
		}
		else {
			if (c -> r -> cnt - v -> r -> cnt != 0) {
				ans |= (1 << depth);
				c = c -> r;
				v = v -> r;
				depth--;
				continue;
			}
			c = c -> l;
			v = v -> l;
			depth--;
		}
	}
	return ans;
}
int main () {
    csl; 
	cin >> m;
	head[0] = new node();
	Head[0] = new Node();
	nul1 = new Node();
	nul2 = new node();
	while (m--) {
		cin >> t;
		if (t == 0) {
			cin >> v;
			++n;
			Head[n] = Head[n - 1] -> get(0, M - 1, v);
			head[n] = head[n - 1] -> get(0, v);
		}
		if (t == 1) {
			cin >> u >> v >> c;
			cout << q1(head[u - 1], head[v], c) << '\n';
		}
		if (t == 2) {
			cin >> v;
			n = n - v;
		}
		if (t == 3) {
			cin >> u >> v >> c;
			cout << q3(Head[u - 1], Head[v], 0, M - 1, c) << '\n';;
		}
		if (t == 4) {
			cin >> u >> v >> c;
			cout << q4(Head[u - 1], Head[v], 0, M - 1, c) << '\n';
		}
	}
    return 0;
}