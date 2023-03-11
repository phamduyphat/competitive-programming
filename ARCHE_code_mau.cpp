#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> lab;

    DSU(int n){
        lab.resize(n, -1);
    }

    int root(int x){
        if (lab[x] < 0) return x;
        return lab[x] = root(lab[x]);
    }

    bool Union(int x, int y){
        x = root(x), y = root(y);
        if (x == y) return false;
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }

    bool sameComponent(int x, int y){
        return root(x) == root(y);
    }

};

int32_t main(int32_t argc,char** argv){
    if (argc>2){
        freopen(argv[1],"r",stdin);
        freopen(argv[2],"w",stdout);
    }
    int n, m;
    cin >> n >> m;
    vector< pair< int, pair<int,int> > > S(m);
    #define X second.first
    #define Y second.second
    #define K first
    for (auto &s : S){
        cin >> s.X >> s.Y >> s.K;
        --s.X, --s.Y;
    }
    auto check = [&](int bound){
        DSU dsu(n);
        for (auto &s : S) if (s.K > bound){
            dsu.Union(s.X, s.Y);
        }
        for (auto &s : S) if (s.K == -1){
            if (dsu.sameComponent(s.X, s.Y)) return false;
        }
        return true;
    };
    int ans = -1, L = 0, H = 1e9;
    while (L <= H){
        int M = L + H >> 1;
        if (check(M)){
            ans = M;
            H = M - 1;
        } else L = M + 1;
    }
    cout << ans << endl;
}
