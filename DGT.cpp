#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
using namespace std;
const int N = 1e7 + 10;
ll res[N], dd[N], snt[N], mark[N];
int c;
ll mod = 1e9 + 7;
void sang ()
{
	for(int i = 2; i*i <= 1e7; i++)
	{
		if (mark[i]) continue;
		for(int j = i*i; j <= 1e7; j += i) mark[j]++;
		
	}
	forin(i, 2, 1e7) 
	{
		if (mark[i] == 0) snt[++c] = i; 
		res[i]  = 1;
	}
}
int main()
{
	sang();
	int tmp = 0;
	forin(i, 1, c) 
	{
		for(ll j = snt[i]; j <= 1e7 ; j *= snt[i])
		{
			int s = 0;
			for(ll k = j; k <= 1e7; k += j) 
			{
				if (j == snt[i]) dd[k] = 0;
				dd[k]++;
				if (dd[k] % 2 ==0) res[k] *= snt[i];
				res[k] %= mod;
			}
		}
		int s = 0;
		for(ll k = snt[i]; k <= 1e7; k+= snt[i]) 
		{
			s += dd[k]%2;
			if (s == 2) 
			{
				res[k] *= snt[i];
				res[k] %= mod;
				s = 0;	
			}
		}
	}
	res[1] = 1;
	//forin(i, 1, 1e7) if (res[i] > 1e9 + 7) cout << i << " " ;
	forin(i, 3, 1e7) 
	{
		res[i] %= mod;
		res[i] *= res[i-1];
		res[i] %= mod;
		//res[i] *= res[i];
	}
	int x;
	while (true) 
	{
		cin >> x;
		if (x == 0) return 0;
		cout << res[x]*res[x]%mod << "\n";
	}
}