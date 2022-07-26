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
int32_t m, n;
str s;
int32_t a[10000][10000], b[10000][10000];
queue <pair<int32_t, int32_t>> q;
int32_t dx[4]={1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
//functions:

driver main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//code below this line:
	cin >> m >> n;
	fr1(i,m) {
		cin >> s;
		s = " " + s;
		fr1(j,n) if (s[j] == '.') a[i][j] = 1;
	}
	fr1(i,m) fr1(j,n)
	{
		if (a[i][j] != 0 && b[i][j] == 0)
		{
			int32_t temp1 = i, temp2 = j;
			b[i][j] = 1;
			q.push(make_pair(i, j));
			while (!q.empty()){
				int32_t x = q.front().fi;
				int32_t y = q.front().se;
				q.pop();
				fr(e,4){
					int32_t x1 = x + dx[e], y1 = y + dy[e];
					if (a[x1][y1] != 0 && b[x1][y1] == 0 && x1 > 0 && x1 < m && y1 > 0 && y1 < n)
					{
						b[x1][y1] = b[x][y] + 1;
						if (b[temp1][temp2] < b[x1][y1])
						{
							temp1 = x1;
							temp2 = y1;
						}
						q.push(make_pair(x1, y1));
					}
				}
			}
			reset(b, 0);
			
		}
	}
}