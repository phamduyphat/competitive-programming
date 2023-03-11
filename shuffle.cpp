#include <bits/stdc++.h>
#include <chrono>
#define sexually_transferred_diseases std	   // Why not
using namespace sexually_transferred_diseases; // UwU
// array <class T, size_t N> arr;
// vector <class T, class Alloc = allocator<T>> vector;
// deque <class T, class Alloc = allocator<T> > deque;
// priority_queue <class T, class Container = vector<T>,class Compare = less<typename Container::value_type>> priority_queue;
// queue <class T, class Container = deque<T>> queue;
// map <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T>>> map;
#define FOR(i, a, b) for (int64_t i = a; i <= b; i++)
#define fr(i, n) for (int64_t i = 0; i < n; i++)
#define fr1(i, n) for (int64_t i = 1; i <= n; i++)
#define FORi(i, a, b) for (int32_t i = a; i <= b; i++)
#define fri(i, n) for (int32_t i = 0; i < n; i++)
#define fr1i(i, n) for (int32_t i = 1; i <= n; i++)
#define forv(a, b) for (auto &a : b)
#define sortall(arr) sort(arr.begin(), arr.end())
#define sortallmax(arr) sort(arr.begin(), arr.end(), greater<int64_t>())
#define elif else if
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define str string
#define int long long
#define ll long long
#define endline "\n"
#define driver int32_t
#define vi vector<int32_t>
#define qi queue<int32_t>
#define reset(a, b) memset(a, b, sizeof(a))
#define TOINFINITYANDBEYOND 0x3f3f3f3f
#define PI 3.1415926535897932384626433832795
const long long MODULO = 1e9 + 7;
const double pi = acos(-1.0);
const int32_t MAX_N = 1e5 + 5;
auto start = chrono::steady_clock::now();
void finish()
{
	auto end = chrono::steady_clock::now();
	// cout << "Code run time: ";
	cout << chrono::duration<double, std::milli>(end - start).count() << "ms" << endl;
	fclose(stdin);
	fclose(stdout);
	return;
}
/************************* Matrix **************************/
const int64_t length = 2;
struct matrix
{
	int64_t m[length][length];
};
matrix operator*(matrix a, matrix b)
{
	matrix c;
	fr(i, length) fr(j, length)
	{
		c.m[i][j] = 0;
		fr(t, length) c.m[i][j] = (c.m[i][j] + (a.m[i][t] * b.m[t][j]) % MODULO) % MODULO;
	}
	return c;
}
matrix operator^(matrix a, int64_t n)
{
	if (n == 1)
		return a;
	matrix temp = a ^ (n / 2);
	temp = temp * temp;
	if (n % 2 == 0)
		return temp;
	else
		return (temp * a);
}
/***********************************************************/
// variables below this line:
const int64_t N = 1e5 + 5;
int64_t n, x, l, a[N], k, t[N];
/***********************************************************/
// functions declarations:
typedef struct Node
{
	Node *P, *L, *R;
	int64_t sz, val;
};
typedef Node *PNode;

PNode root, nil;

void Update(PNode x)
{
	x->sz = x->L->sz + x->R->sz + 1;
}

void SetL(PNode x, PNode y)
{
	x->L = y;
	y->P = x;
}

void SetR(PNode x, PNode y)
{
	x->R = y;
	y->P = x;
}

PNode NodeAt(PNode x, int64_t i)
{
	for (;;)
	{
		int64_t p = x->L->sz + 1;
		if (i == p)
			break;
		if (i < p)
			x = x->L;
		else
			x = x->R, i -= p;
	}
	return x;
}

void UpTree(PNode x)
{
	PNode y = x->P, z = y->P;
	if (y->L == x)
		SetL(y, x->R), SetR(x, y);
	else
		SetR(y, x->L), SetL(x, y);
	if (z->L == y)
		SetL(z, x);
	else
		SetR(z, x);
	Update(y);
	Update(x);
}

void Splay(PNode x)
{
	for (;;)
	{
		PNode y = x->P, z = y->P;
		if (y == nil)
			return;
		if (z != nil)
			if ((z->L == y) == (y->L == x))
				UpTree(y);
			else
				UpTree(x);
		UpTree(x);
	}
}

void Split(PNode T, int64_t i, PNode &T1, PNode &T2)
{
	if (i == 0)
	{
		T1 = nil;
		T2 = T;
		return;
	}
	T1 = NodeAt(T, i);
	Splay(T1);
	T2 = T1->R;
	T1->R = nil;
	T2->P = nil;
	Update(T1);
}

PNode Join(PNode T1, PNode T2)
{
	if (T1 == nil)
		return T2;
	T1 = NodeAt(T1, T1->sz);
	Splay(T1);
	SetR(T1, T2);
	Update(T1);
	return T1;
}

void Init()
{
	nil = new Node();
	nil->sz = nil->val = 0;
	nil->P = nil->L = nil->R = nil;
	root = nil;
}

PNode build(int64_t l, int64_t r)
{
	if (l > r)
		return nil;
	int64_t m = (l + r) >> 1;
	PNode x = new Node();
	x->val = m;
	x->P = nil;
	SetL(x, build(l, m - 1));
	SetR(x, build(m + 1, r));
	Update(x);
	return x;
}

void S(int64_t i, int64_t m, int64_t j)
{
	PNode T1, T2, T3;
	Split(root, i - 1, T1, T2);
	Split(T2, m, T2, T3);
	root = Join(T1, T3);
	Split(root, j - 1, T1, T3);
	root = Join(Join(T1, T2), T3);
}

void dfs(PNode x)
{
	if (x == nil)
		return;
	dfs(x->L);
	a[++a[0]] = x->val;
	dfs(x->R);
}

void tree(){
    Init();

	root = build(1, n);
}
/***********************************************************/
driver main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("shuffle.inp", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	// code below this line:
	cin >> n >> l >> x;

	tree();

	fr1(z, x)
	{
		int64_t i, m, j;
		cin >> i >> m >> j;
		S(i, m, j);
	}
	dfs(root);
	fr1(i, l) cout << a[i] << " ";
	//cout << endl;
	//finish();
	return 0;
}
// functions content:

/*
M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,N,N,N,N,N,N,N,N,N,N,N,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,C,–,;,;,.,.,.,;,:,>,7,>,>,7,7,7,>,!,!,!,>,7,?,O,N,M,M,M,M,M,M,M,M,M,M,M,M,M,M,
,M,M,M,M,M,M,M,M,M,M,7,.,.,.,.,.,;,>,?,!,;,.,.,.,.,.,;,;,:,!,>,7,7,>,>,>,?,?,O,H,M,M,M,M,M,M,M,M,M,M,
,M,M,M,M,M,M,M,M,M,?,.,.,.,.,.,!,?,:,;,:,>,7,>,>,>,7,7,!,–,;,;,.,.,;,;,–,:,!,!,:,>,H,M,M,M,M,M,M,M,M,
,M,M,M,M,M,M,M,M,Q,.,.,.,.,;,7,!,;,>,7,:,;,.,.,.,.,.,.,;,:,!,>,>,>,>,>,!,:,–,;,!,–,;,C,M,M,M,M,M,M,M,
,M,M,M,M,M,M,M,M,:,.,.,.,–,7,;,>,7,–,>,7,7,>,>,>,7,–,.,.,.,.,.,.,.,;,;,–,:,:,;,.,.,.,.,>,M,M,M,M,M,M,
,M,M,M,M,M,M,M,$,.,.,.,:,!,;,7,:,7,7,–,.,.,.,.,.,:,!,.,.,.,.,.,;,7,7,>,!,:,!,?,:,.,.,.,.,>,M,M,M,M,M,
,M,M,M,M,M,M,M,:,.,.,;,:,;,?,–,?,–,.,.,.,.,.,.,.,.,7,.,.,.,.,.,.,;,–,.,.,.,.,.,7,:,.,.,.,.,N,M,M,M,M,
,M,M,M,M,M,M,Q,.,.,.,.,.,>,–,?,;,.,.,.,.,.,.,.,.,.,:,.,.,.,.,.,.,!,–,.,.,.,.,.,.,7,.,.,.,.,Q,M,M,M,M,
,M,M,M,M,M,M,7,.,.,.,.,.,;,–,–,.,–,7,O,$,$,$,?,–,.,;,.,.,.,.,.,.,!,.,.,.,.,.,.,.,–,.,.,.,.,O,M,M,M,M,
,M,M,M,M,M,N,;,.,.,.,.,.,.,.,.,?,M,M,M,M,M,Q,N,M,7,.,.,.,.,.,.,.,–,.,.,–,:,:,:,;,.,.,.,.,.,>,M,M,M,M,
,M,M,M,M,M,7,;,.,.,.,.,.,.,.,?,M,H,M,M,M,M,–,;,?,M,O,;,.,.,.,.,.,.,:,Q,M,M,M,M,Q,;,.,.,.,.,;,H,M,M,M,
,M,M,M,M,H,O,?,!,;,.,;,C,>,–,M,Q,N,M,M,M,M,$,>,;,!,M,?,.,.,.,.,;,7,M,M,M,M,N,M,M,?,>,7,>,!,:,–,N,M,M,
,M,M,M,O,7,:,–,–,–,;,.,–,!,–,O,H,O,7,>,7,C,H,M,Q,7,N,C,.,.,.,C,N,M,M,M,M,H,Q,O,7,;,;,;,;,;,!,>,:,M,M,
,M,M,$,7,.,–,$,M,M,M,Q,>,;,.,.,.,.,.,C,$,.,.,!,Q,M,H,–,.,.,.,–,Q,M,Q,!,;,.,.,.,.,.,.,.,.,;,>,!,7,C,M,
,M,N,7,–,;,Q,H,7,!,!,Q,M,Q,>,;,;,:,$,M,!,.,.,.,;,>,;,.,.,.,.,.,–,M,;,.,.,.,.,.,.,.,:,?,?,>,:,?,!,7,M,
,M,7,>,.,7,N,–,.,–,>,.,>,Q,M,M,N,M,N,!,.,.,.,.,.,.,.,.,.,.,.,.,;,M,–,.,.,.,–,:,;,?,M,H,H,M,C,>,.,?,M,
,M,;,!,.,Q,?,.,.,?,N,–,.,.,–,!,>,!,;,.,.,.,.,.,.,.,.,.,.,.,.,.,;,M,7,.,.,.,7,M,H,M,C,;,.,:,7,!,;,>,M,
,N,.,!,;,M,–,.,;,H,M,N,7,;,.,.,.,.,.,.,.,.,.,–,;,!,:,.,.,.,.,.,.,?,M,?,.,.,;,7,O,O,–,?,;,.,.,!,;,7,M,
,N,.,!,;,M,;,7,N,M,?,$,M,Q,!,.,.,.,.,;,–,–,!,7,H,M,Q,;,.,.,.,.,.,.,7,M,O,;,.,.,.,.,.,H,!,.,.,?,;,C,M,
,M,;,!,;,N,!,O,Q,M,7,.,!,H,M,$,!,.,.,>,>,!,–,:,N,–,;,–,;,.,.,.,.,.,.,N,M,O,.,.,.,.,;,M,$,.,:,!,!,$,M,
,M,>,>,;,$,?,.,.,O,Q,.,.,;,C,M,M,Q,7,;,.,.,.,:,N,;,O,M,M,$,;,.,.,.,!,M,N,O,?,!,.,.,!,M,M,;,.,!,?,H,M,
,M,Q,:,!,!,O,.,.,C,M,C,;,.,;,N,O,H,M,N,O,!,;,;,N,?,7,!,:,–,.,;,;,–,N,C,;,.,.,!,–,;,H,N,M,:,>,!,!,M,M,
,M,M,>,7,>,;,.,.,:,M,M,H,!,.,H,>,.,:,C,N,M,H,C,!,–,.,.,.,.,.,C,H,N,$,;,.,.,.,.,:,H,M,M,M,>,.,.,$,M,M,
,M,M,N,!,:,:,.,.,.,?,M,N,M,$,N,H,;,.,.,;,!,Q,M,M,H,C,>,–,;,.,–,?,C,;,.,.,;,!,O,M,M,O,M,M,7,.,;,M,M,M,
,M,M,M,M,7,.,.,.,.,;,N,C,7,N,M,M,O,–,.,.,.,?,H,7,O,H,M,M,N,Q,O,C,C,C,C,$,N,M,M,?,$,C,$,M,?,.,:,M,M,M,
,M,M,M,M,O,.,.,.,.,.,>,M,–,–,M,M,M,M,$,!,.,O,C,.,.,.,–,C,M,$,$,H,M,M,N,$,C,H,O,.,?,O,?,M,?,.,:,M,M,M,
,M,M,M,M,M,:,.,.,.,.,.,Q,$,.,$,Q,Q,M,M,M,Q,N,7,.,.,.,.,–,M,–,.,.,?,Q,;,.,.,7,Q,.,O,N,H,M,?,.,!,M,M,M,
,M,M,M,M,M,$,.,.,.,.,.,–,M,7,Q,7,;,>,H,M,M,M,M,$,7,:,;,–,M,:,;,;,7,H,;,;,:,C,N,?,M,M,M,M,?,.,!,M,M,M,
,M,M,M,M,M,M,:,.,.,.,.,.,7,M,M,–,.,.,;,!,Q,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,7,.,!,M,M,M,
,M,M,M,M,M,M,O,.,.,.,.,.,.,O,M,:,.,.,.,.,7,H,7,Q,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,>,.,!,M,M,M,
,M,M,M,M,M,M,M,–,.,.,.,.,.,;,O,M,!,.,.,.,O,$,.,.,:,C,N,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,N,M,!,.,!,M,M,M,
,M,M,M,M,M,M,M,Q,;,.,.,.,.,.,.,C,M,?,.,;,N,7,.,.,.,.,–,M,?,O,Q,H,M,M,M,M,M,M,N,M,Q,M,$,M,;,.,!,M,M,M,
,M,M,M,M,M,M,M,M,C,.,.,.,.,.,.,.,?,M,$,?,M,;,.,.,.,.,–,M,;,.,.,;,N,C,:,7,M,>,>,M,!,M,$,$,.,.,!,M,M,M,
,M,M,M,M,M,M,M,M,M,?,;,:,.,;,:,.,.,!,N,M,N,–,.,.,.,.,–,M,;,.,.,;,M,–,.,>,N,;,$,O,–,H,M,:,.,.,:,M,M,M,
,M,M,M,M,M,M,M,M,M,M,7,:,?,–,:,7,–,.,;,C,N,M,$,7,–,;,:,M,;,.,.,:,M,;,.,Q,O,;,N,O,$,M,?,.,.,.,:,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,C,;,7,>,;,>,7,;,.,;,7,$,M,M,N,N,M,C,7,7,$,M,?,O,M,N,N,M,M,Q,!,.,.,.,.,:,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,H,:,–,?,:,;,7,7,;,.,.,;,:,7,C,O,$,Q,Q,H,H,Q,Q,$,C,7,!,;,.,.,.,.,.,.,–,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,C,;,!,?,:,–,7,7,;,.,.,.,.,.,.,.,.,;,;,.,.,.,.,.,.,.,.,!,–,.,;,.,–,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,H,>,;,!,7,:,–,7,7,:,.,.,.,.,;,–,–,:,–,;,.,.,.,.,.,>,>,.,.,:,.,;,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,H,!,.,:,>,7,!,!,7,7,>,>,>,!,!,:,–,–,;,;,–,>,?,:,.,.,–,7,.,;,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,$,:,.,.,:,7,7,7,!,–,;,–,:,:,!,!,!,!,:,;,.,.,.,!,?,;,.,;,N,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,C,;,.,.,.,;,–,>,>,>,>,>,!,!,:,:,–,–,–,!,?,>,.,.,.,;,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,N,7,;,.,.,.,.,.,.,.,;,;,;,–,–,–,:,:,–,;,.,.,.,.,?,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,H,7,–,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,–,N,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,H,C,!,;,.,.,.,.,.,.,.,.,.,.,.,.,.,–,H,M,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,N,$,>,–,.,.,.,.,.,.,.,.,;,>,N,M,M,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,H,$,O,C,C,?,C,O,N,M,M,M,M,M,M,M,
,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,

*/
/*
⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄ ⡋
⣡⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥ ⣇
⠻⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿
⣿⣷⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄
⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣌⣛⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵
⣿⣿⣿⣿⣿⣿⣿⠄⣴⣿⣶⣄⠄⣴⣶⠄⢀⣾⣿⣿⣿⣿⣿⣿
⠻⣿⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⠄⣿⣿⡀⣾⣿⣿⣿⣿⣛⠛⠁
⠄⠈⠛⢿⣿⣿⣿⠁⠞⢿⣿⣿⡄⢿⣿⡇⣸⣿⣿⠿⠛⠁⠄⠄
⠄⠄⠄⠄⠉⠻⣿⣿⣾⣦⡙⠻⣷⣾⣿⠃⠿⠋⠁⠄⠄⠄⠄⠄
⣶⣶⣮⣥⣒⠲⢮⣝⡿⣿⣿⡆⣿⡿⠃⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⢉⢉⠉⠉⠻⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⠟⠠⡰⣕⣗⣷⣧⣀⣅⠘⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⠃⣠⣳⣟⣿⣿⣷⣿⡿⣜⠄⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⠁⠄⣳⢷⣿⣿⣿⣿⡿⣝⠖⠄⣿⣿⣿⣿⣿
⣿⣿⣿⣿⠃⠄⢢⡹⣿⢷⣯⢿⢷⡫⣗⠍⢰⣿⣿⣿⣿⣿
⣿⣿⣿⡏⢀⢄⠤⣁⠋⠿⣗⣟⡯⡏⢎⠁⢸⣿⣿⣿⣿⣿
⣿⣿⣿⠄⢔⢕⣯⣿⣿⡲⡤⡄⡤⠄⡀⢠⣿⣿⣿⣿⣿⣿
⣿⣿⠇⠠⡳⣯⣿⣿⣾⢵⣫⢎⢎⠆⢀⣿⣿⣿⣿⣿⣿⣿
⣿⣿⠄⢨⣫⣿⣿⡿⣿⣻⢎⡗⡕⡅⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⠄⢜⢾⣾⣿⣿⣟⣗⢯⡪⡳⡀⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⠄⢸⢽⣿⣷⣿⣻⡮⡧⡳⡱⡁⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⡄⢨⣻⣽⣿⣟⣿⣞⣗⡽⡸⡐⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⡇⢀⢗⣿⣿⣿⣿⡿⣞⡵⡣⣊⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⡀⡣⣗⣿⣿⣿⣿⣯⡯⡺⣼⠎⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣧⠐⡵⣻⣟⣯⣿⣷⣟⣝⢞⡿⢹⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡆⢘⡺⣽⢿⣻⣿⣗⡷⣹⢩⢃⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣷⠄⠪⣯⣟⣿⢯⣿⣻⣜⢎⢆⠜⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡆⠄⢣⣻⣽⣿⣿⣟⣾⡮⡺⡸⠸⣿⣿⣿⣿
⣿⣿⡿⠛⠉⠁⠄⢕⡳⣽⡾⣿⢽⣯⡿⣮⢚⣅⠹⣿⣿⣿
⡿⠋⠄⠄⠄⠄⢀⠒⠝⣞⢿⡿⣿⣽⢿⡽⣧⣳⡅⠌⠻⣿
⠁⠄⠄⠄⠄⠄⠐⡐⠱⡱⣻⡻⣝⣮⣟
*/