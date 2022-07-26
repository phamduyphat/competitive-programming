#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define forv(a, b) for(auto & a : b)
using namespace std;
int st[5], e[5], ss, ee;
struct matrix {
	long long m[25][25];
};
int mod;
string edge[25] = {"  ", "AB", "AD", "AE", "BA", "BC", "BF", "CB", "CD", "CG", "DA", "DC", "DH", "EA", "EF", "EH", "FB", "FE", "FG", "GC", "GF", "GH", "HD", "HE", "HG"};
matrix operator * (matrix a, matrix b) {
	matrix c;
	forin(i, 1, 24) {
		forin(j, 1, 24) {
			c.m[i][j] = 0;
			forin(k, 1, 24) {
				c.m[i][j] += a.m[i][k] * b.m[k][j] % mod, c.m[i][j] %= mod;
			}
		}
	}
	return c;
}
matrix pw (matrix x, long long p) {
	if (p == 1) return x;
	matrix tmp = pw(x, p / 2);
	tmp = tmp * tmp;
	if (p % 2 == 0) return tmp;
	return (tmp * x);
}
int main() {
	matrix z;
	forin(i, 1, 24) {
		forin(j, 1, 24) {
			z.m[i][j] = 0;
			if (i == j) {
				z.m[i][j] = 0;
				continue;
			}
			string x = edge[i], y = edge[j];
			if (x[0] == y[1] && x[1] == y[0]) z.m[i][j] = 0;
			else if (x[1] == y[0])  z.m[i][j] = 1;
		}
	}		
	char u, v; cin >> u >> v;
	long long res = 0;
	bool ok = 0;
	forin(i, 1, 24) {
		string s = edge[i];
		if (s[0] == u) st[++ss] = i;
		if (s[1] == v) e[++ee] = i;
		if (s[0] == u && s[1] == v) ok = 1;
	}
	long long k; cin >> k >> mod;
	if (k == 1) {
		cout << ok;
		return 0;
	}
	matrix ans = pw(z, k - 1);
	forin(i, 1, 3) forin(j, 1, 3) {
//		if (ans.m[st[i]][e[j]]) cout << st[i] << " " << e[j] << endl;
		res += ans.m[st[i]][e[j]], res %= mod;
	}
//	forin(i, 1, 24) {
//		forin(j, 1, 24) cout << ans.m[i][j] <<" ";
//		cout << endl;
//	}
	cout << res;
}