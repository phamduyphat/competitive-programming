//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "rewrite"
#define maxn 100002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

string s1, s2;
int s[maxn];


int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    s1 = "*" + s1;
    s2 = "_" + s2;
    s[0] = 0;
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + s1[i] - 48;
    int minright = m;
    for (int r = n; minright && s2[minright] == s1[r]; minright --, r-- );
    for (int i = 1; i <= m; i++)
    {
        int num = 0;
        int r = (s2[i] == 48) ? i : min(m, i+6);
        for (int k = i; k <= r; k++)
        {
            num = num * 10 + s2[k] - 48;
            if (k >= minright && num == s[n - (m-k)] - s[i-1])
            {
                cout << i << " " << n - (m-k);
                return 0;
            }
        }
    }

    return 0;
}
