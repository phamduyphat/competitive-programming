//0(2^3 * logn)
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 5;
const ll MODULO = 1e9 + 7;
const ll INF = 1e9;

template<int _MODULO> struct Modular {
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    Modular() { v = 0; }
    Modular(ll _v) { v = int((-_MODULO < _v && _v < _MODULO) ? _v : _v % _MODULO); if (v < 0) v += _MODULO; }
    friend std::ostream& operator<<(std::ostream& out, const Modular& n) { return out << int(n); }
    friend std::istream& operator>>(std::istream& in, Modular& n) { ll v_; in >> v_; n = Modular(v_); return in; }

    friend bool operator==(const Modular& a, const Modular& b) { return a.v == b.v; }
    friend bool operator!=(const Modular& a, const Modular& b) { return a.v != b.v; }
    friend bool operator<(const Modular& a, const Modular& b) { return a.v < b.v; }

    Modular& operator+=(const Modular& m) { if ((v += m.v) >= _MODULO) v -= _MODULO; return *this; }
    Modular& operator-=(const Modular& m) { if ((v -= m.v) < 0) v += _MODULO; return *this; }
    Modular& operator*=(const Modular& m) { v = int((ll)v*m.v%_MODULO); return *this; }
    Modular& operator/=(const Modular& m) { return (*this) *= inv(m); }
    Modular operator-() const { return Modular(-v); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    friend Modular pow(Modular a, ll p) {
        Modular ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; 
    }
    friend Modular inv(const Modular& a) { assert(a.v != 0); return pow(a,_MODULO-2); }

    friend Modular operator+(Modular a, const Modular& b) { return a += b; }
    friend Modular operator-(Modular a, const Modular& b) { return a -= b; }
    friend Modular operator*(Modular a, const Modular& b) { return a *= b; }
    friend Modular operator/(Modular a, const Modular& b) { return a /= b; }
    friend Modular operator++(Modular& a, int) { Modular r = a; ++a; return r; }friend Modular operator--(Modular& a, int) { Modular r = a; --a; return r; }
};

template <class T> struct matrix {
    vector<vector<T>> m;
    int c, r;
    matrix() : c(), r() {}
    matrix(int c, int r, T x) : c(c), r(r), m(c, vector<T>(r, x)) {}
    matrix(int n) : matrix(n, n, 0) { // identity matrix
        for (int i = 0; i < n; i++) m[i][i] = 1;
    }
    matrix operator* (matrix<T> b) {
        matrix<T> a = *this;
        assert(a.c == b.r);
        matrix<T> o(a.r, b.c, 0);
        for (int i = 0; i < a.r; i++)
            for (int j = 0; j < b.c; j++)
                for (int k = 0; k < a.c; k++)
                    o.m[i][j] = o.m[i][j] + a.m[i][k] * b.m[k][j];
        return o;
    }
    matrix operator^ (ll b) {
        matrix<T> a = *this;
        assert(a.r == a.c);
        matrix<T> o(a.r);
        while (b) {
            if (b % 2) o = o * a;
            a = a * a;
            b /= 2;
        }
        return o;
    }
    void print() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << m[i][j] << " ";
            cout << "\n";
        }
    }
};

using mint = Modular<MODULO>;

void solve() {
    ll n; cin >> n;
    matrix<mint> A(2,1,  0); 
    A.m[0][0] = 0; A.m[1][0] = 1;
    matrix<mint> B(2, 2, 0);
    B.m[0][0] = 0; B.m[0][1] = 1;
    B.m[1][0] = 1; B.m[1][1] = 1;
    A = A * (B ^ n);
    cout << A.m[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}