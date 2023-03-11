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
#define Mid  	(ll + (rr - ll >> 1))
#define Lcon 	id << 1, ll, Mid
#define Rcon 	id << 1 | 1, Mid + 1, rr
/***********************************************************/
//variables below this line:
const int32_t maxN = 1e5 + 5;
int32_t tree[4 * maxN][2], cntx[maxN], cnty[maxN];
int32_t n, T, op, p, x, y, xx, yy, sx, sy;
/***********************************************************/
//functions declarations:
int64_t read(){
	char ch; bool neg = false;
    while((ch = getchar()) < '0' || ch > '9')
        if(ch == '-') neg = true;
    int64_t res = ch ^ 48;
    while((ch = getchar()) >= '0' && ch <= '9')
        res = (res << 1) + (res << 3) + (ch ^ 48);
    return ((neg == false) ? res : -res);
}
void update(int32_t id, int32_t ll, int32_t rr, int32_t p, int32_t v, int32_t tp);
int32_t get(int32_t id, int32_t ll, int32_t rr, int32_t l, int32_t r, int32_t tp);
/***********************************************************/
driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen ("input.inp","r",stdin);
	//freopen ("output.out","w",stdout);
	//code below this line:
	n = read();
	T = read();
	while (T --)
	{
		op = read();
		if (op == 1) 
		{
			x = read(); y = read();
			if (!cntx[x]) update(1, 0, n, x, 1, 0);
			if (!cnty[y]) update(1, 0, n, y, 1, 1);
			cntx[x] ++; cnty[y] ++;
		}
		if (op == 2)
		{
			x = read(); y = read();
			cntx[x] --; cnty[y] --;
			if (!cntx[x]) update(1, 0, n, x, 0, 0);
			if (!cnty[y]) update(1, 0, n, y, 0, 1);
		}
		if (op == 3)
		{
			x = read(); y = read();
			xx = read(); yy = read();
			sx = get(1, 0, n, 0, xx, 0) - get(1, 0, n, 1, x - 1, 0);
			sy = get(1, 0, n, 0, yy, 1) - get(1, 0, n, 1, y - 1, 1);

			if (sx >= xx - x + 1 || sy >= yy - y + 1)
			{
				cout << "Yes";
			}
			else cout << "No";
			cout << endl;
		}
	}
	//finish();
	return 0;
}
//functions content:
void update(int32_t id, int32_t ll, int32_t rr, int32_t p, int32_t v, int32_t tp)
{
	if (ll == p && rr == p){
		tree[id][tp] = v;
		return;
	}
	if (p >= ll && p <= Mid) update(Lcon, p, v, tp);
	if (p > Mid && p <= rr) update(Rcon, p, v, tp);
	tree[id][tp] = tree[id << 1][tp] + tree[id << 1 | 1][tp];
}
int32_t get(int32_t id, int32_t ll, int32_t rr, int32_t l, int32_t r, int32_t tp)
{
	if (l <= ll && rr <= r) 
		return tree[id][tp];
	int64_t res = 0;
	if (l <= Mid) res += get(Lcon, l, r, tp);
	if (Mid < r) res += get(Rcon, l, r, tp);
	return res;
}
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