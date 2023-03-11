//Be OK
#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define bit(i,x) ((x >> i) & 1)
using namespace std;
const int N = 16;
long long dp[N][1 << N],kq=0,n,k;
int main() {
	 cin >> n >> k;
	for(int q = 1; q < (1 << n); q ++) 
	{
		int x = __builtin_popcount(q);
		for(int i = 0; i < n; i++) 
		{ 
			if (bit(i,q))
			{
				if (x == 1) dp[i][q] = 1;
				else 
				{
				for(int j = 0; j < n; j++) 
					{
						if(i==j || bit(j,q)==0 || abs(j-i) > k) continue;
							dp[i][q] += dp[j][q ^ (1 << i)];
					
					}
				}
			}
			
		}
	}
	for(int i = 0; i < n; i++) kq += dp[i][(1 << n) - 1];
	cout << kq;
}