#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 1e7;

int n, m, k;
int a[maxN + 2]; //DÃ£y chá»¯ sá»‘
int Next[maxN + 2];
struct TCommand
{
    int i, j, c;
};
vector<TCommand> Q;

void ReadInput()
{
    cin >> n >> m >> k;
    fill(a, a + n + 2, -1);
    for (int i = 0; i <= n; ++i)
        Next[i] = i + 1;
    Q.resize(m);
    for (TCommand& cmd: Q)
        cin >> cmd.i >> cmd.j >> cmd.c;
    reverse(Q.begin(), Q.end());
    Q.push_back({1, n, 0});
}

/*
int FindNext(int i) //TÃ¬m tháº±ng cÃ²n sá»‘ng Ä‘á»©ng sau vá»‹ trÃ­ i
{
    return a[Next[i]] == -1 ? Next[i] : Next[i] = FindNext(Next[i]);
}
*/

int FindNext(int i) //Khá»­ Ä‘á»‡ quy, trÃ¡nh lá»—i trÃ n bá»™ nhá»› stack
{
    int j = i, res;
    while (true)
    {
        j = Next[j];
        if (a[j] == -1)
        {
            res = j;
            break;
        }
    }
    while (true)
    {
        if (i == res) break;
        j = Next[i];
        Next[i] = res;
        i = j;
    }
    return res;
}

void DoFill(int i, int j, int c)
{
    for (int k = FindNext(i - 1); k <= j; k = FindNext(k))
        a[k] = c;
}

void Solve()
{
    for (const TCommand& cmd: Q)
        DoFill(cmd.i, cmd.j, cmd.c);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res * 10LL + a[i]) % k;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("FILLNUM.inp", "r", stdin);
    freopen("FILLNUM.out", "w", stdout);
    ReadInput();
    Solve();
}