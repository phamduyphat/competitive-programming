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
//functions:
void primefactorization(ll i);
//variables below this line 
ll n,k,a[100100],res=1;
ll check[13]={2,3,5,7,11,13,17,19,23,29,31,37,41};
ll b[100];
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//code below this line
	cin >> n >> k;
	fr1(i,n){
		cin >> a[i];
	}
	fr1(i,n){
		primefactorization(a[i]);
	}
	FOR(i,0,12)
	{	
		if (b[i]>0){ 
			res*=(int)pow(check[i],ceil(b[i]*1.0/k));
		}
	}
	cout << res;
}

void primefactorization(ll i)
{
	FOR(j,0,12)
	{
		ll temp=0;
		while(i%check[j]==0)  {temp++;i/=check[j];}
		b[j]=max(temp,b[j]);
	}
}
