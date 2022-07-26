#include <bits/stdc++.h>
#include <chrono>
#define sexually_transferred_diseases std				//Why not
using namespace sexually_transferred_diseases;			//UwU
//array <class T, size_t N> arr;
//vector <class T, class Alloc = allocator<T>> vector;
//deque <class T, class Alloc = allocator<T> > deque;
//priority_queue <class T, class Container = vector<T>,class Compare = less<typename Container::value_type>> priority_queue;
//queue <class T, class Container = deque<T>> queue;
//map <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T>>> map;
#define FOR(i,a,b)      	for(long long i=a;i<=b;i++)
#define fr(i,n)         	for(long long i=0;i<n;i++)
#define fr1(i,n)        	for(long long i=1;i<=n;i++)
#define FORi(i,a,b)      	for(int32_t i=a;i<=b;i++)
#define fri(i,n)         	for(int32_t i=0;i<n;i++)
#define fr1i(i,n)        	for(int32_t i=1;i<=n;i++)
#define forv(a, b) 			for(auto &a : b)
#define sortall(arr)   	 	sort(arr.begin(), arr.end())
#define sortallmax(arr)	 	sort(arr.begin(), arr.end(), greater<int64_t>())
#define elif				else if
#define pb              	push_back
#define pf              	push_front
#define fi 					first
#define se 					second 
#define str					string
#define int             	long long 
#define ll 					long long
#define endline				"\n"
#define driver 				int32_t
#define vi					vector<int32_t>
#define qi					queue<int32_t>
#define reset(a,b)			memset(a,b,sizeof(a))
#define TOINFINITYANDBEYOND 0x3f3f3f3f
#define PI 					3.1415926535897932384626433832795
const long long MODULO =	1e9+7;
const double pi =			acos(-1.0);
const int32_t 				MAX_N = 1e5 + 5;
auto start = 				chrono::steady_clock::now();
void finish(){
	auto end = chrono::steady_clock::now();
	//cout << "Code run time: ";
	cout << chrono::duration<double, std::milli>(end - start).count() << "ms" << endl;
	fclose(stdin);
	fclose(stdout);
	return;
}
/************************* Matrix **************************/
const int64_t length = 2;
struct matrix{
	int64_t m[length][length];
};
matrix operator *(matrix a, matrix b)
{
	matrix c;
	fr(i,length) fr(j,length){
		c.m[i][j] = 0;
		fr(t,length) c.m[i][j] = (c.m[i][j] + (a.m[i][t] * b.m[t][j]) % MODULO) % MODULO;
	}
	return c;
}
matrix operator ^(matrix a, int64_t n)
{
	if (n == 1) return a;
	matrix temp = a ^ (n / 2);
	temp = temp * temp;
	if (n % 2 == 0) return temp;
	else return (temp * a);
}
struct node{
	int64_t val, lazy;
}node1[200000], node2[200000];
/***********************************************************/
//variables below this line:
int64_t n, m, ans = -1;
/***********************************************************/
//functions declarations:
void bruh1(int64_t id)
{
	int64_t t = node1[id].lazy;
	node1[id * 2].lazy += t;
	node1[id * 2 + 1].lazy += t;
	node1[id * 2].val += t;
	node1[id * 2 + 1].val += t;
	node1[id].lazy = 0;
}
void bruh2(int64_t id, int32_t l, int32_t r)
{
	int64_t t = node2[id].lazy;
	if (l != r){
		node2[id * 2].lazy += t;
		node2[id * 2 + 1].lazy += t;
		node2[id * 2].val += t;
		node2[id * 2 + 1].val += t;
	}
	node2[id].lazy = 0;
}
void update1(int32_t id, int32_t l, int32_t r, int32_t pos, int32_t val);
void update2(int32_t id, int32_t l, int32_t r, int32_t u, int32_t v, int32_t val);
int64_t getSum1Util(int32_t l, int32_t r, int32_t u, int32_t v, int32_t id);
int64_t getSum2Util(int32_t l, int32_t r, int32_t u, int32_t v, int32_t id);
int64_t getsum(int64_t l, int64_t r)
{
	return getSum1Util(1, n, l, r, 1) + getSum2Util(1, n, l, r, 1);
}
/***********************************************************/
driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("input.inp","r",stdin);
	freopen ("output.out","w",stdout);
	//code below this line:
    cin >> n;
	cin >> m;
	while (m --)
	{
		int64_t selection; cin >> selection;
		if (selection == 1)
		{
			int32_t l, r, a, b;
			cin >> l >> r >> a >> b;
			FOR(i, l, r)
			{
				update1(1, 1, n, i, i * a);
			}
			update2(1, 1, n, l, r, b - a * l);
		}
		else 
		{
			int32_t l, r;
			cin >> l >> r;
			cout << getsum(l, r) % MODULO << endline;
		}
	}
	finish();
	return 0;
}
//functions content:
void update1(int32_t id, int32_t l, int32_t r, int32_t pos, int32_t val)
{
	if (pos < l || pos > r) return;
	node1[id].val += val;
	if (l != r)
	{
		int32_t mid = (l + r) / 2;
		update1(id * 2, l, mid, pos, val);
		update1(id * 2 + 1, mid + 1, r, pos, val);
	}
}
void update2(int32_t id, int32_t l, int32_t r, int32_t u, int32_t v, int32_t val)
{
	if (v < l || r < u) 
		return;
	if (u <= l || r <= v){node2[id].val += (r - l + 1) * val; node2[id].lazy += (r - l + 1) * val; return;}

	int32_t mid = (l + r) / 2;

	bruh2(id, l, r);

	update2(id * 2, l, mid, u, v, val);
	update2(id * 2 + 1, mid + 1, r, u, v, val);

	node2[id].val = node2[id * 2].val + node2[id * 2 + 1].val;
}
int64_t getSum1Util(int32_t l, int32_t r, int32_t u, int32_t v, int32_t id)
{
	if (l >= u && r <= v) return node1[id].val;
	if (r < u || l > v) return 0;
	int32_t mid = (l + r) / 2;
	return getSum1Util(l, mid, u, v, 2 * id) + getSum1Util(mid + 1, r, u, v, 2 * id + 1);
}
int64_t getSum2Util(int32_t l, int32_t r, int32_t u, int32_t v, int32_t id)
{
	if (v < l || r < u) 
		return 0;
	if (u <= l && r <= v) 
		return node2[id].val;

	int32_t mid = (l + r) / 2;
	bruh2(id, l, r);

	return getSum2Util(l, mid, u, v, id * 2) + getSum2Util(mid + 1, r, u, v, id * 2 + 1);
}