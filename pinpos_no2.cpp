#include <bits/stdc++.h>
using namespace std;

#define forr(_a, _b, _c) for (_a = _b; _a <= _c; ++_a)
#define file "pinpos"
typedef long long ll;
const double inf = 1e15 + 1;
int n, i;
ll dt, a, b, aa, bb, xx, yy, ma[100001][2], mi[100001][2];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen(file".inp","r",stdin); freopen(file".out","w",stdout);

    cin >> n;
    a = b = inf;
    aa = bb = -inf;
    forr(i, 1, n) {
        mi[i][0] = mi[i][1] = inf;
        ma[i][0] = ma[i][1] = -inf;
        cin >> xx >> yy;
        mi[i][0] = min(mi[i][0], xx - yy);
        mi[i][1] = min(mi[i][1], xx + yy);
        ma[i][0] = max(ma[i][0], xx - yy);
        ma[i][1] = max(ma[i][1], xx + yy);
        cin >> xx >> yy;
        mi[i][0] = min(mi[i][0], xx - yy);
        mi[i][1] = min(mi[i][1], xx + yy);
        ma[i][0] = max(ma[i][0], xx - yy);
        ma[i][1] = max(ma[i][1], xx + yy);
        cin >> xx >> yy;
        mi[i][0] = min(mi[i][0], xx - yy);
        mi[i][1] = min(mi[i][1], xx + yy);
        ma[i][0] = max(ma[i][0], xx - yy);
        ma[i][1] = max(ma[i][1], xx + yy);
        cin >> xx >> yy;
        mi[i][0] = min(mi[i][0], xx - yy);
        mi[i][1] = min(mi[i][1], xx + yy);
        ma[i][0] = max(ma[i][0], xx - yy);
        ma[i][1] = max(ma[i][1], xx + yy);
        a = min(a, ma[i][0]);
        b = min(b, ma[i][1]);
        aa = max(aa, mi[i][0]);
        bb = max(bb, mi[i][1]);
    }
    dt = (a - aa - 1) * (b - bb - 1);
    if (a - aa - 1 <= 0 || b - bb - 1 <= 0)
        cout << 0;
    else if ((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0))
        cout << (dt + 1) / 2;
    else
        cout << dt / 2;

    return 0;
}