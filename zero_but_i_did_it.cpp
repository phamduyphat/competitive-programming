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
#define driver 				int32_t
long long MODULO=1e9+7;
//variables below this line:
int64_t d[1000010];
//functions:

driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//code below this line:
	int32_t q;
    cin >> q;
    fr1(i,q)
    {
        memset(d, 0, sizeof(d));
        queue<int32_t> q;
        int64_t n; cin >> n;
        q.push(n);
        d[n] = 1;
        while (!q.empty() || n==0)
        {
            if (d[q.front() - 1] == 0 || d[q.front() - 1] > d[q.front()] + 1)
            {
                q.push(q.front() - 1);
                d[q.front() - 1] = d[q.front()] + 1;
            }
            if (q.front() >= 4)
            {
                for (int32_t j = 2; pow(j,2) <= q.front(); ++j)
                {
                    if (q.front() % j == 0)
                    {
                        if (d[q.front()/j] == 0 || d[q.front()/j] > d[q.front()] + 1){
                            q.push(q.front() / j);
                            d[q.front() / j] = d[q.front()] + 1;
                        }
                    }
                }
            }

            q.pop();
            if (d[0]) break;

        }

        cout << d[0] - 1 << endl;

    }
}