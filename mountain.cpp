//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "mountain"
#define maxn 30005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n;
long long ans;
bool prime[maxn];
long long suml[maxn], sumr[maxn];
int b[maxn];
long long l[maxn], r[maxn];

inline long long left(int u, int v) //(u,v]
{
    return suml[v+1] - l[u-1] * (v-u+2) - suml[u-1];
}

inline long long right(int u, int v) //[u,v)
{
    return sumr[u-1] - r[v+1] * (v-u+2) - sumr[v+1];
}

void prepare()
{
	memset(prime, 1, sizeof(prime));
    for (int i = 2; i < maxn; i++)
        if (prime[i])
            for (int j = i+i; j < maxn; j += i) prime[j] = 0;
	l[0] = r[n+1] = suml[0] = sumr[n+1] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		l[i] = l[i-1] + b[i];
		suml[i] = suml[i-1] + l[i-1];
	}
	for (int i = n; i; i--)
	{
		r[i] = r[i+1] + b[i];
		sumr[i] = sumr[i+1] + r[i+1];
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

	cin >> n;    
	prepare();
    
	ans = 1000000000000000ll;
	for (int i = 1; i <= n; i++) MIN(ans, suml[i] + sumr[i]);
	for (int p = 2; p < n; p++)
		if (prime[p])
			for (int i = 1; i <= n - p; i++)
			{
				int j = i + p;
				int mid = i + p/2;
				//right(i+1, i+p/2) + left(i+ p/2 + 1, i + p - 1);
				long long temp = sumr[i] - sumr[mid+1] - r[mid+1] * (mid+1-i);	
				temp += suml[j] - suml[mid] - l[mid] * (j - mid);//chi phi doan giua
				MIN(ans, temp + suml[i] + sumr[i+p]);
				if (!prime[p+2]) continue;
				if (i > 2) MIN(ans, temp + suml[i-2] + b[i-1] + sumr[i+p]);
				if (i <= n - p - 2) MIN(ans, temp + suml[i] + b[i+p+1] + sumr[i+p+2]);
				if (prime[p+4] && i > 2 && i <= n-p-2) MIN(ans, temp + suml[i-2] + b[i-1] + b[i+p+1] + sumr[i+p+2]);
			}
	cout << ans;    

    return 0;
}
