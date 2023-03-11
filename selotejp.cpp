#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)

const int inf = 1e9;

int main() {
	(void)!freopen("input.inp", "r", stdin);
	(void)!freopen("output.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	char mat[n][m + 1];
	REP(i, n) scanf("%s", mat[i]);
	vector <int> dp(1 << m, inf), novi(1 << m);
	dp[0] = 0;
	REP(i, n) {
		REP(j, m) {
			REP(k, 1 << m) {
				if(k & (1 << j)) {
					if(mat[i][j] == '.') novi[k] = inf;
					else novi[k] = min(dp[k], dp[k ^ (1 << j)] + 1);
				}
				else {
					novi[k] = min(dp[k], dp[k ^ (1 << j)]);
					if(mat[i][j] == '#' && (j == 0 || (k & (1 << (j - 1))) || mat[i][j - 1] == '.')) 
						novi[k]++;
				}
			}
			dp = novi;
		}
	}
	printf("%d\n", *min_element(dp.begin(), dp.end()));
	return 0;
}
