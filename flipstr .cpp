#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
long long MODULO=1e9+7;
//variables declaration below this line:
ll x[1000], res=1000, n, m;
string s, s2;
//functions:
void change(ll i);
void check(ll i);
void ktra()
{
	s2=s;ll temp=0;
	fr1(i,n)
	{if (x[i]) {change(i);temp++;}}
	FOR(i,n+1,n+n/m) if (x[i]) {FOR(j,1,(i-n)*m) {change(j);}temp++;}
	check(temp);
}
void duyet(ll i)
{
	if (i > n + n/m) ktra();
	else {
		fr(j,2)
		{
			x[i]=j; 
			duyet(i+1);
		}
	}
}
long long solution(){
    return 0;
}

int32_t main(){
  	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 	ll  d, e, f, g, h, k, l, o, p, q, r, u, v, w, z;
    //code below this line
   	cin >> n >> m;
   	cin >> s;
	s=" "+s;
  	duyet(1);
  	cout << res;
}
void change(ll i)
{
	if (s2[i]=='0') s2.replace(i,1,"1");
	else s2.replace(i,1,"0");
}
void check(ll i)
{
	if (s2.substr(1,n-m)==s2.substr(m+1,n-m)) 
	{
		res=min(res,i);
	}
}