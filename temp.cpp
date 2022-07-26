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
#define sortallmax(arr)	 	sort(arr.begin(), arr.end(), greater<ll>())
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
int32_t ans = 645, n, x[1000], sum;
int32_t da[35], db[35];
/***********************************************************/
//functions declarations:
void duyet(int32_t i);
void check();
/***********************************************************/
driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("input.inp","r",stdin);
	freopen ("output.out","w",stdout);
	//code below this line:
    cin >> n;
	if (n == 0) {cout << 0; return 0;}
	fr1(i, n)
	{
		cin >> x[i];
		sum += x[i];
	}
	duyet(1);
	cout << ans << endline;
	finish();
	return 0;
}
//functions content:
void duyet(int32_t i)
{

	if (i > n){check();}
	else {
		i ++;
		fr(j, 2)
		{
			da[i] = j;
			db[i] = 1 - j;
			duyet(i);
		}
	}
}
void check()
{
	int32_t s[3];
	reset(s, 0);
	fr1(i, n)
	{
		if (da[i] == 1) s[0] += x[i];
		if (db[i] == 1) s[1] += x[i];
	}
	s[2] = sum - s[1] - s[0];
	sort(s, s + 3);
	ans = min(ans, max(abs(s[2] - s[1]), abs(s[1] - s[0])));
}