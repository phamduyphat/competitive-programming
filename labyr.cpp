#include<bits/stdc++.h>
#include<chrono>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define fi first
#define se second
using namespace std;
const int N = 1010;
int a[N][N] ,d[N][N];
int m1[5] = {1, -1, 0, 0};
int m2[5] = {0, 0, 1, -1};
queue<pair<int, int>> q;
auto start = chrono::steady_clock::now();
int main()
{
	freopen ("input.inp","r",stdin);
	freopen ("output.out","w",stdout);
	int res = 0;
	int m, n; cin >> m >> n;
	forin(i, 1, m)
	{
		string s; cin >> s;
		s = " " + s;
		forin(j, 1, n) if (s[j] == '.') a[i][j] = 1;
	}
	forin(i, 1, m) forin(j, 1, n) 
	{
		if (a[i][j] && !d[i][j]) 
		{
			int t1 = 0, t2 = 0;
			d[i][j] = 1;
			t1 = i;
			t2 = j;
			q.push(make_pair(i, j));
			while (!q.empty()) 
			{
				int x = q.front().fi;
				int y = q.front().se;
				q.pop();
				forin(k, 0, 3) 
				{
					int x1 = x + m1[k];
					int y1 = y + m2[k];
					if (x1 <= 0 || x1 > m || y1 <= 0 || y1 > n) continue;
					if (a[x1][y1] && !d[x1][y1]) 
					{
						d[x1][y1] = d[x][y] + 1;
						if (d[t1][t2] < d[x1][y1]) 
						{
							t1 = x1;
							t2 = y1;
						}
						q.push(make_pair(x1, y1));
					}
				}
			}
			memset(d, 0, sizeof(d));
	d[t1][t2] = 1;
	q.push(make_pair(t1, t2));
	while (!q.empty()) 
		{
			int x = q.front().fi;
			int y = q.front().se;
			q.pop();
			forin(k, 0, 3) 
			{
				int x1 = x + m1[k];
				int y1 = y + m2[k];
				if (a[x1][y1] && !d[x1][y1]) 
				{
					d[x1][y1] = d[x][y] + 1;
					res = max(res, d[x1][y1]);
					q.push(make_pair(x1, y1));
				}
			}
		}
		}
	}
	cout << --res << endl ;	
	auto end = chrono::steady_clock::now();
	cout << chrono::duration<double, milli>(end - start).count() << " ms" << endl;
	fclose(stdin);
	fclose(stdout);
}