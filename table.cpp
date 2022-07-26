#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
using namespace std;
const int mod = 12345678;
struct matrix 
{
	long long t[4][4];
};
matrix operator* (matrix a, matrix b) 
{
	matrix c;
	forin(i, 1, 3) forin(j, 1, 3) 
	{
		c.t[i][j] = 0;
		forin(k2, 1, 3) c.t[i][j] = (c.t[i][j] + (a.t[i][k2] * b.t[k2][j]) % mod ) % mod;
	}
	return c;
}
matrix mu(matrix a, long long p) 
{
	if (p == 1) return a;
	matrix tmp = mu(a, p / 2);
	tmp = tmp * tmp;
	if (p % 2 == 0) return tmp;
	else return (tmp*a);
}
int main()
{
	matrix x;
	x.t[1][1] = 1; x.t[1][2] = 1; x.t[1][3] = 1;
	x.t[2][1] = 1; x.t[2][2] = 0; x.t[2][3] = 1;
	x.t[3][1] = 1; x.t[3][2] = 1; x.t[3][3] = 0;
	long long n; cin >> n;
	if (n == 1) cout << 2;
	else 
	{
		matrix z = mu(x, n - 1);
		long long s = 0;
		forin(i, 1, 3) forin(j, 1, 3) s += z.t[i][j], s %= mod;
		cout << (s - 1 + mod) % mod;
	}
    
}