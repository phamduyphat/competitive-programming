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
/***********************************************************/
//variables below this line:
int32_t n, f[10000];
/***********************************************************/
//functions declarations:
void compress(vector<int32_t> &a) {
    set<int32_t> s(a.begin(), a.end());
    vector<int32_t> b(s.begin(), s.end());
    for (int32_t &x: a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    }
}
int32_t getMid(int32_t x, int32_t y){return x + (y - x) / 2;}
int32_t get(int32_t s, int32_t l, int32_t r, int32_t u, int32_t v)
{
	if (l > v || r < u) return -1e9;
	if (u <= l && r <= v) return t[s];
	int32_t mid = getMid(l, r);
	return max(get(s * 2, l, mid, u, v), get(s * 2 + 1, mid + 1, r, u, v));
}
/***********************************************************/
driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("input.inp","r",stdin);
	freopen ("output.out","w",stdout);
	//code below this line:
	cin >> n;
	vector <int32_t> a;
	fr1(i, n) {int32_t temp; cin >> temp;a.pb(temp);}
	compress(a);
	int32_t ans = 1;
	fr1(i, n)
	{
		f[i] = 0;
		fr(j, i) if (a[j] < a[i]) f[i] = max (f[i], f[j] + 1);
		ans = max (ans, f[i]);
	}
	cout << ans << endline;
	finish();
	return 0;
}
//functions content:
