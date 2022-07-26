#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll e[N], t[N];
ll s[N];
void sang()
{
	forin(i, 1, 1e6) e[i] = i;
	for(int i = 2; i*i <= 1e6; i++)
	{
		if (e[i] != i) continue;
		for(int j = 2; j*i <= 1e6; j++) e[i*j] = i;
	}
}
void souoc()
{
	s[1] = 1;
	for(int i = 2; i <= 1e6; i++)
	{
		int p = e[i], y = i, k = 0;
		while (y % p == 0) 
		{
			k++;
			y /= p;
		}
		s[i] = (k + 1)*s[y];
	}
	for(int i = 2; i <= 1e6; i++) s[i] += s[i-1];
}
void tonguoc()
{
	t[1] = 1;
	for(int i = 2; i <= 1e6; i++)
	{
		ll p = e[i], sum = 1, y = i;
		while (y % p == 0) 
		{
			sum = sum*p + 1;
			y /= p;
		}
		t[i] = sum*t[y];
	}
	forin(i, 2, 1e6) t[i] += t[i-1];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sang();
	souoc();
	tonguoc();
	int q; cin >> q;
	while (q--)
	{
		int a, b; cin >> a >> b;
		if (a == 0) a++;
		cout << s[b] - s[a-1] << " " << t[b] - t[a-1] << "\n";
	}
	
}