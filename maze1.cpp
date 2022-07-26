#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define fi first
#define se second
using namespace std;
const int N = 110;
int d[2][2][2][2][N][N]; // 1 la b 2 la y 3 l a r 4 la g
char a[N][N];
int r, c;
int m1[5] = {1, -1, 0, 0};
int m2[5] = {0, 0, -1, 1};
void solve()
{
	queue<int> q[5];
	queue<pair<int, int>> qq;
	forin(i, 1, r) 
	{
		string s; cin >> s;
		s = " " + s;
		forin(j, 1, c) 
		{
			a[i][j] = s[j];	
			if (a[i][j] == '*') 
			{
				qq.push(make_pair(i, j));
				d[0][0][0][0][i][j] = 1;
				q[1].push(0), q[2].push(0), q[3].push(0), q[4].push(0);
				a[i][j] = '.';
			}
		}
	}
	bool st = 0;
	while (!qq.empty())
	{
		int x = qq.front().fi, y = qq.front().se;
		int k1 = q[1].front(), k2 = q[2].front(), k3 = q[3].front(), k4 = q[4].front();
		if (a[x][y] == 'X') {
			cout << "Escape possible in " << d[k1][k2][k3][k4][x][y] - 1 << " steps.";
			st = 1;
			break;
				}
				
		qq.pop(), q[1].pop(), q[2].pop(), q[3].pop(), q[4].pop();
		forin(k, 0, 3) 
		{
			int K1 = k1, K2 = k2, K3 = k3, K4 = k4;
			int x1 = x + m1[k], y1 = y + m2[k];
			if (x1 < 1 || x1 > r || y1 < 1 || y1 > c || a[x1][y1] == '#') continue;
			if ((a[x1][y1] == 'B' && !k1) || (a[x1][y1] == 'Y' && !k2) || (a[x1][y1] == 'R' && !k3) || (a[x1][y1] == 'G' && !k4)) continue;	
			else if (a[x1][y1] == 'b') K1 = 1;
			else if (a[x1][y1] == 'y') K2 = 1;
			else if (a[x1][y1] == 'r') K3 = 1;
			else if (a[x1][y1] == 'g') K4 = 1;
			if (!d[k1][k2][k3][k4][x1][y1]) 
			{
				d[K1][K2][K3][K4][x1][y1] = d[k1][k2][k3][k4][x][y] + 1;
				qq.push(make_pair(x1, y1));
				q[1].push(K1), q[2].push(K2), q[3].push(K3), q[4].push(K4);
			}	
		}
	}
	if (!st) cout << "The poor student is trapped!";
  	memset(d, 0, sizeof(d));
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> r >> c;
		if (r == 0 && c == 0) return 0;
		solve();
		cout << "\n";
	}
}