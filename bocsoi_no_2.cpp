#include <bits/stdc++.h>
#define sexually_transferred_disease std
using namespace sexually_transferred_disease;
//array <class T, size_t N> arr;
//vector <class T, class Alloc = allocator<T>> vector;
//deque <class T, class Alloc = allocator<T> > deque;
//priority_queue <class T, class Container = vector<T>,class Compare = less<typename Container::value_type>> priority_queue;
//queue <class T, class Container = deque<T>> queue;
//map <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T>>> map;
#define FOR(i,a,b)      	for(long long i=a;i<=b;i++)
#define fr(i,n)         	for(long long i=0;i<n;i++)
#define fr1(i,n)        	for(long long i=1;i<=n;i++)
#define sortall(arr)   	 	sort(arr.begin(), arr.end())
#define sortallmax(arr)	 	sort(arr.begin(), arr.end(), greater<ll>())
#define pb              	push_back
#define pf              	push_front
#define int             	long long 
#define ll 					long long
#define fi 					first
#define se 					second
#define driver 				int32_t
#define reset(a,b)			memset(a,b,sizeof(a))
#define TOINFINITYANDBEYOND 0x3f3f3f3f
const long long MODULO =	1e9+7;
//variables below this line:
int32_t a, b, c;
queue <pair <int64_t, int64_t>> q;
int64_t d[10000][10000];
//functions:
void Loang();
driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//code below this line:
	cin >> a >> b >> c;
	int64_t sum = a + b + c;
	if (sum % 2 == 1) {cout << -1; return 0;}
	d[a][b] = 1; 
	q.push(make_pair(a, b));
	while(!q.empty())
	{
		a = q.front().fi;
		b = q.front().se;
		c = sum - a - b;
        q.pop();
		Loang();	
	}
	int64_t sol = TOINFINITYANDBEYOND;
	if (d[sum/2][sum/2] != 0) 	
		sol = min (sol, d[sum/2][sum/2]);
	if (d[sum/2][0] != 0) 		
		sol = min (sol, d[sum/2][0]);
	if (d[0][sum/2] != 0)
		sol = min (sol, d[0][sum/2]);
	sol == TOINFINITYANDBEYOND ? cout << -1 : cout << sol;
}
void Loang()
{
	if (d[max(a, b) - min(a, b)][min(a, b) * 2] == 0){
		d[max(a, b) - min(a, b)][min(a, b) * 2] = d[a][b] + 1;
		q.push(make_pair(max(a, b) - min(a, b), min(a, b) * 2));
	}
	if (d[max(b, c) - min(b, c)][min(b, c) * 2] == 0){
		d[max(b, c) - min(b, c)][min(b, c) * 2] = d[a][b] + 1;
		q.push(make_pair(max(b, c) - min(b, c), min(b, c) * 2));
	}
	if (d[max(a, c) - min(a, c)][min(a, c) * 2] == 0){
		d[max(a, c) - min(a, c)][min(a, c) * 2] = d[a][c] + 1;
		q.push(make_pair(max(a, c) - min(a, c), min(a, c) * 2));
	}
}