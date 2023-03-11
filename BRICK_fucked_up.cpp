#include <bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define fi first
#define se second
using namespace std;
int a[100][100], dd[5], d[100][100];
queue<pair<int, int>> q;
int n;
void loang()
{
	while (!q.empty())
	{
		int x = q.front().fi;
		int y = q.front().se;
		q.pop();
		if (x > 1 && d[x-1][y] == 0)
		{
			if (a[x][y] == 0 || a[x][y] == 2) if (a[x - 1][y] == 1 || a[x-1][y] == 3)
			{
				dd[a[x-1][y]]++;
				d[x-1][y] = 1;
				q.push(make_pair(x-1, y));
			}
		}
		if (y > 1 && d[x][y-1] == 0)
		{
			if (a[x][y] == 1 || a[x][y] == 2) if (a[x][y-1] == 0 || a[x][y-1] == 3)
			{
				dd[a[x][y-1]]++;
				d[x][y-1] = 1;
				q.push(make_pair(x, y-1));
			}
		}
		if (x < n && d[x+1][y] == 0)
		{
			if (a[x][y] == 1 || a[x][y] == 3) if (a[x + 1][y] == 0 || a[x+1][y] == 2)
			{
				dd[a[x+1][y]]++;
				d[x+1][y] = 1;
				q.push(make_pair(x+1, y));
			}
		}
		if (y < n && d[x][y+1] == 0)
		{
			if (a[x][y] == 0 || a[x][y] == 3) if (a[x][y+1] == 1 || a[x][y+1] == 2)
			{
				dd[a[x][y+1]]++;
				d[x][y+1] = 1;
				q.push(make_pair(x, y+1));
			}
		}
	}
}
int main()
 {
    cin >> n;
    int hinh = 0, tamgiac = 0, vuong = 0, binhhanh = 0, thang = 0, khac = 0;
	forin(i, 1, n) forin(j, 1, n) cin >> a[i][j];
	forin(i, 1, n) forin(j, 1, n)
	{
		if (i < n && j < n) if (a[i][j] == 3 && a[i][j+1] == 1 && a[i+1][j] == 0 && a[i+1][j+1] == 2) vuong++;
		if (d[i][j]) continue;
		hinh++;
		memset(dd, 0, sizeof(dd));
		dd[a[i][j]]++;
		d[i][j] = 1;
		q.push(make_pair(i, j));
		loang();
		if (dd[0] + dd[1] + dd[2] + dd[3] == 1) tamgiac++;
		else if (dd[0] + dd[1] + dd[2] + dd[3] == 2)
		{
			if (dd[0] == 1 && dd[1] == 1) binhhanh++;
			else if (dd[2] == 1 && dd[3] == 1) binhhanh++;
			else tamgiac++;
		}
		else if (dd[2] == 0 && dd[3] == 0)
		{
			if (dd[0] == dd[1]) binhhanh++;
			else if (abs(dd[0] - dd[1]) == 1) thang++;
		}
		else if (dd[1] == 0 && dd[0] == 0)
		{
			if (dd[2] == dd[3]) binhhanh++;
			else if (abs(dd[2] - dd[3]) == 1) thang++;
		}
	}
	khac=hinh-tamgiac-vuong-binhhanh-thang;
	cout << hinh << "\n" <<  tamgiac << "\n" << vuong << "\n" << binhhanh << "\n" << thang << "\n" << khac;
 }
