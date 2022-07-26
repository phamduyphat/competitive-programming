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

//variables below this line:
const long long limit=1e6+10;
ll t, n, high[limit], a[limit];
bool sieve[limit];
//functions:
void SieveOfAtkin(long long limit);
void primefactorization(long long i);
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//code below this line:
	SieveOfAtkin(1e6);
	cin >> t;
	while(t--)
		{
			cin >> n;
			fr1(i,n) cin >> a[i];
			fr1(i,n) primefactorization(a[i]);
			long long tmp=0;
			fr(i,limit+1) tmp+=high[i];
			cout << tmp << "\n";
			memset(a, 0, sizeof(a));
		}

}
void SieveOfAtkin(int limit)
{
	for (int i = 0; i < limit; i++)
		sieve[i] = false;
	sieve[2]=true; sieve[3] = true;
	/* Mark sieve[n] is true if one
	of the following is true:
	a) n = (4*x*x)+(y*y) has odd number of
	solutions, i.e., there exist
	odd number of distinct pairs (x, y)
	that satisfy the equation and
		n % 12 = 1 or n % 12 = 5.
	b) n = (3*x*x)+(y*y) has odd number of
	solutions and n % 12 = 7
	c) n = (3*x*x)-(y*y) has odd number of
	solutions, x > y and n % 12 = 11 */
	for (int x = 1; x * x < limit; x++) {
		for (int y = 1; y * y < limit; y++) {
			
			// Main part of Sieve of Atkin
			int n = (4 * x * x) + (y * y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5))
				sieve[n] ^= true;

			n = (3 * x * x) + (y * y);
			if (n <= limit && n % 12 == 7)
				sieve[n] ^= true;

			n = (3 * x * x) - (y * y);
			if (x > y && n <= limit && n % 12 == 11)
				sieve[n] ^= true;
		}
	}

	// Mark all multiples of squares as non-prime
	for (int r = 5; r * r < limit; r++) {
		if (sieve[r]) {
			for (int i = r * r; i < limit; i += r * r)
				sieve[i] = false;
		}
	}

	
}
void primefactorization(long long i)
{	
	if (i!=1){
	if (sieve[i]) high[i] = high[i] > 1 ? high[i] : 1;
	else 
	FOR(j,1,limit) {
		ll temp=0;
		if (i==1) continue;
		if (sieve[j] == false) continue;
		while (i%sieve[j] == 0) {temp++; i/=sieve[j];}
		high[i] = max(high[i],temp);
	}
	}
}