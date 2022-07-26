#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef pair<long, long> ii;

int n;
ii a, b, c, d;
long long xmax, ymax, xmin, ymin, x = -1e18, xx = 1e18, y = -1e18, yy = 1e18, q;
ii calc(ii a) { return ii(a.fi - a.se, a.fi + a.se); }
int main() {
    // freopen("pinpos.inp","r",stdin);
    // freopen("pinpos.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se >> d.fi >> d.se;
        a = calc(a);
        b = calc(b);
        c = calc(c);
        d = calc(d);
        xmax = max(max(a.fi, b.fi), max(c.fi, d.fi));
        ymax = max(max(a.se, b.se), max(c.se, d.se));
        xmin = min(min(a.fi, b.fi), min(c.fi, d.fi));
        ymin = min(min(a.se, b.se), min(c.se, d.se));
        x = max(x, xmin);
        y = max(y, ymin);
        xx = min(xx, xmax);
        yy = min(yy, ymax);
    }
    q = (xx - x - 1) * (yy - y - 1);
    if (q <= 0) {
        cout << 0;
        return 0;
    }
    if ((x + y) % 2 == 0)
        cout << (q + 1) / 2;
    else
        cout << q / 2;
}