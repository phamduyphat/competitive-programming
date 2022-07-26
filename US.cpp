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
void SieveOfAtkin(int limit);
int divisorSum(ll i,long long n);
void divcount();
//variables below this line 
const ll limit=1e6+2;
ll t,u,v,a[limit];
long long divisor[limit];

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//code below this line
	cin >> t;
    SieveOfAtkin(1000006);
    FOR(i,1,t){
        long long temp=0,tmp=0;
        cin >> u >> v;
        temp=divisor[v] - divisor[u==0 ? u : u-1];
        tmp+=divisorSum(u,v);
        cout << temp << " " << tmp << "\n";
    }
}
void SieveOfAtkin(int limit)
{
	// 2 and 3 are known to be prime
	

	// Initialise the sieve array with false values
	bool sieve[limit];
	for (int i = 0; i < limit; i++)
		sieve[i] = false;

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

	// Print primes using sieve[]
    a[1]=2;a[2]=3;
    long long z=3;
	for (int k = 5; k < limit; k++){
		if (sieve[k])
			a[z]=k;
            z++;
    }
}
int divisorSum(long long i,int n)
{
    int sum = 0;
 
    for(; i <= n; ++i)
    {
         
        // Find all divisors of i and add them
        for(int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                if (i / j == j)
                    sum += j;
                else
                    sum += j + i / j;
            }
        }
    }
    return sum;
}
void divcount(){
    divisor[1] = 1;
	for(int i = 2; i <= 1e6; i++)
	{
		int p = a[i], y = i, k = 0;
		while (y % p == 0) 
		{
			k++;
			y /= p;
		}
		divisor[i] = (k + 1)*divisor[y];
	}
	for(int i = 2; i <= 1e6; i++) divisor[i] += divisor[i-1];
}