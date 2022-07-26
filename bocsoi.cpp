#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define fi first 
#define se second
using namespace std;
int d[5010][5010];
int main()
{
	int A, B, C; cin >> A >> B >> C;
	int s = A + B + C;
	if (s % 2) {
		cout << -1; 
		return 0;
	}
	d[A][B] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(A, B));
	while (!q.empty()) 
	{
		int a = q.front().fi;
		int b = q.front().se;
		q.pop();
		int c = s - a - b;
		if (!d[max(a,b) - min(a,b)][2*min(a,b)])
		{
			d[max(a,b) - min(a,b)][2*min(a,b)] = d[a][b] + 1;
			q.push(make_pair(max(a,b) - min(a,b),2*min(a,b)));
		}
		if (!d[max(c,b) - min(c,b)][2*min(c,b)]) 
		{
			d[max(c,b) - min(c,b)][2*min(c,b)] = d[a][b] + 1;
			q.push(make_pair(max(c,b) - min(c,b),2*min(c,b)));
		}
		if (!d[max(a,c) - min(a,c)][2*min(a,c)]) 
		{
			d[max(a,c) - min(a,c)][2*min(a,c)] = d[a][b] + 1;
			q.push(make_pair(max(a,c) - min(a,c),2*min(a,c)));
		}
	}
	int res = INT_MAX;
	if (d[s/2][s/2]) res = min(res, d[s/2][s/2]);
	if (d[0][s/2]) res = min(res, d[0][s/2]);
	if (d[s/2][0]) res = min(res, d[s/2][0]);
	if (res == INT_MAX) cout << -1;
	else cout << res;
}