#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxMN = 1000;
const int maxH = 1e6;

int m, n;
struct TCell
{
    int x, y;
};
vector<TCell> L[maxH + 1]; //L[i] = danh sÃ¡ch cÃ¡c Ã´ cÃ³ Ä‘á»™ cao i
int lab[maxMN * maxMN];
int IslandCount; //Sá»‘ Ä‘áº£o
int Result;

void ReadInput()
{
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            int h;
            cin >> h;
            L[h].push_back({i, j});
        }
}

inline int Encode(int x, int y)
{
    return x * n + y;
}

void Init()
{
    fill(lab, lab + m * n, -2); //lab = -2: chÃ¬m, lab = -1: gá»‘c cÃ¢y, lab >= 0: cha
    Result = IslandCount = 0;
}

int FindSet(int u)
{
    return lab[u] < 0 ? u : lab[u] = FindSet(lab[u]);
}

int dx[4] {0, 0, -1, 1};
int dy[4] {-1, 1, 0, 0};

void Solve()
{
    for (int h = maxH; h > 0; --h)
    {
        for (const TCell& u: L[h]) //XÃ©t cÃ¡c Ã´ cÃ³ Ä‘á»™ cao h
        {
            int codeu = Encode(u.x, u.y);
            lab[codeu] = -1; //MakeSet(codeu); Ã´ u ná»•i lÃªn
            ++IslandCount;  //sá»‘ Ä‘áº£o ++
        }
        for (const TCell& u: L[h])
        {
            int codeu = Encode(u.x, u.y);
            for (int k = 0; k < 4; ++k)
            {
                TCell v = {u.x + dx[k], u.y + dy[k]};
                if (v.x < 0 || v.x >= m || v.y < 0 || v.y >= n) continue;
                int codev = Encode(v.x, v.y);
                if (lab[codev] == -2) continue;
                int r = FindSet(codeu);
                int s = FindSet(codev);
                if (r != s)
                {
                    lab[r] = s; //Unite(r, s); //há»£p nháº¥t Ä‘áº£o
                    --IslandCount; //sá»‘ Ä‘áº£o--
                }
            }
        }
        if (Result < IslandCount)
            Result = IslandCount;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ISLANDS.inp", "r", stdin);
    freopen("ISLANDS.out", "w", stdout);
    ReadInput();
    Init();
    Solve();
    cout << Result;
}