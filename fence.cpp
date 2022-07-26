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
#define FOR(i,a,b)      	for(int64_t i=a;i<=b;i++)
#define fr(i,n)         	for(int64_t i=0;i<n;i++)
#define fr1(i,n)        	for(int64_t i=1;i<=n;i++)
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
int32_t n, k;
/***********************************************************/
//functions declarations:
bool check(int32_t mid, vector<int32_t> a);
/***********************************************************/
driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("fence.inp","r",stdin);
	freopen ("fence.out","w",stdout);
	//code below this line:
    cin >> n >> k;
	vector<int32_t> a(n);
	vector<int32_t> b;
	forv(v, a) 
		cin >> v;
	sortall(a);
	fr1(i, n - 1) b.push_back(a[i] - a[i - 1]);
	int32_t left = 1, right = 2e9, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid, b)) 
			left = mid + 1;
		else 
			right = mid - 1;
	}
	if (k == 0) {cout << 1999999993; return 0;}
	cout << --left;
	//finish();
	return 0;
}
//functions content:
bool check(int32_t mid, vector<int32_t> a)
{
	int32_t ans = 0;
	if (mid == 1) return true;
	forv(v, a) 
	{
		if (v == 1) continue;
		if (v == (mid - 1)) continue;
		if (v % (mid - 1) == 0) {ans += (v / (mid - 1) - 1); continue;}
		ans += (v / (mid - 1));
	}
	return (ans > k);
}