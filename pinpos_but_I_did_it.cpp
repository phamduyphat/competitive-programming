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
#define fi 					first
#define se 					second 
#define str					string
#define int             	long long 
#define ll 					long long
#define driver 				int32_t
#define reset(a,b)			memset(a,b,sizeof(a))
#define TOINFINITYANDBEYOND 0x3f3f3f3f
const long long MODULO =	1e9+7;
//variables below this line:
int32_t X[10000][10000], Y[10000][10000], sol = 0;
int32_t n;
double area[10000][2];
//functions:
void Polygon_area(int32_t t);
bool Polygon_area2(int32_t t);
driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//code below this line:
	cin >> n;
	fr(k,n){
		int32_t dem1 = -1, dem2 = -1;
		fr1(i,8){
			if (i % 2 == 1) {dem1 ++;cin >> X[k][dem1];}
			else {dem2 ++;cin >> Y[k][dem2];}
		}
	}
	Polygon_area(4);
	FOR(l,-100,100) {
		FOR(m,-100,100){
			fr(k,n){
				X[k][4] = l;
				Y[k][4] = m;
			}
			if (Polygon_area2(5) == true) sol ++;
		}
	}
	cout << sol << " ";
	cout << area[0][0] << " " << area[1][0];
	return 0;
}
void Polygon_area(int32_t t)
{
	fr(k,n){
		int32_t temp = 0;
		int32_t j = t - 1;
		fr(i,t)
		{
			temp += (X[k][j] + X[k][i]) * (Y[k][j] - Y[k][i]);
			j = i;
		}
		area[k][0] = abs(temp/2.0);
	}
}
bool Polygon_area2(int32_t t)
{
	fr(k,n){
		int32_t temp = 0;
		int32_t j = t - 1;
		fr(i,t)
		{
			temp += (X[k][j] + X[k][i]) * (Y[k][j] - Y[k][i]);
			j = i;
		}
		if(abs(1.0 * temp/2) != area[k][0]) return false;
	}
	return true;
}