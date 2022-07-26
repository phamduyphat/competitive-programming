#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define fi first
#define se second
using namespace std;
const int N = 110;
int a[N][N], m[10], d[5][N][N];
int d1[5] = {-1, 0, 1, 0};
int d2[5] = {0, 1, 0, -1};
int shit[5] = {8, 4, 2, 1};
int mark[5];
queue<int> q1, q2, q3;
int main()
{
	int m, n, k; cin >> m >> n >> k;
	int x, y, u, v; cin >> x >> y >> u >> v;
	forin(i, 1, m) forin(j, 1, n) cin >> a[i][j];
	d[0][x][y] = 1;
	q1.push(0), q2.push(x), q3.push(y);
	while (!q1.empty())
	{
		int k_2nd = q1.front(), x_2nd = q2.front(), y_2nd = q3.front();
		q1.pop(), q2.pop(), q3.pop();
		if (x_2nd == u && y_2nd == v) 
		{
			cout << d[k_2nd][x_2nd][y_2nd] - 1;
			return 0;
		}
		int temp = a[x_2nd][y_2nd];
		forin(j, 0, 3) 
		{
			int x_3rd = x_2nd + d1[j], y_3rd = y_2nd + d2[j];
			if (x_3rd >= 1 && x_3rd <= m && y_3rd >= 1 && y_3rd <= n){
			bool check = 0;
			int temp = a[x_3rd][y_3rd];
			forin(j_2nd, 0, 3) 
			{
				if (temp >= shit[j_2nd]) 
				{
					if (j_2nd == j) check = 1;
					temp -= shit[j_2nd];
				}
			}
			if (check == 1) 
			{
				if (d[k_2nd + 1][x_3rd][y_3rd] == 0 && k_2nd < k) 
				{
					q1.push(k_2nd + 1), q2.push(x_3rd), q3.push(y_3rd);
					d[k_2nd+1][x_3rd][y_3rd] = d[k_2nd][x_2nd][y_2nd] + 1;
				}
			}
			else 
			{
				if (d[k_2nd][x_3rd][y_3rd] == 0) 
				{
					q1.push(k_2nd), q2.push(x_3rd), q3.push(y_3rd);
					d[k_2nd][x_3rd][y_3rd] = d[k_2nd][x_2nd][y_2nd] + 1;
				}
			}
			}
		}
	}
	cout << -1;
}