#include <bits/stdc++.h>
#include <chrono>
#define sexually_transferred_diseases std			
using namespace sexually_transferred_diseases;			

#define FOR(i,a,b)      	for(int64_t i=a;i<=b;i++)
#define fr(i,n)         	for(int64_t i=0;i<n;i++)
#define fr1(i,n)        	for(int64_t i=1;i<=n;i++)

#define int					long long 
#define endline				"\n"
#define spaceuk				" "
#define driver				int32_t
const long long MODULO =	1e9+7;
const double pi =			acos(-1.0);
auto start =				chrono::steady_clock::now();
void finish(){
    auto end = chrono::steady_clock::now();
    //cout << "Code run time: ";
    cout << chrono::duration<double, std::milli>(end - start).count() << "ms" << endl;
    fclose(stdin);
    fclose(stdout);
    return;
}
int64_t Modular_multiplication(int64_t a, int64_t b)
{
    int64_t res = 0;
    a %= MODULO;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % MODULO;
        a = (a * 2) % MODULO;
        b /= 2;
    }
    return res % MODULO;
}

int64_t task1(int64_t a, int64_t n)
{
    int64_t res = Modular_multiplication(a, Modular_multiplication(n, n + 1) / 2);
    return res;
}
int64_t task2(int64_t a, int64_t n)
{
    int64_t count = 0;
    int64_t sum = 0;
    for(int64_t i = 1, j = 3; count <= n; i ++, j += 2)
    {
        if (count + j <= n)
            sum += Modular_multiplication(i, j);
        else 
            sum += Modular_multiplication(i, n - count);
        count += j;
    }
    return Modular_multiplication(a, sum);
}
/***********************************************************/
driver main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen ("input.inp","r",stdin);
    freopen ("output.out","w",stdout);
    //Local variables below this line:
    int64_t n, a, b;
    //code below this line:
    cin >> n >> a >> b;
    cout << (task1(a, n) + task2(b, n)) % MODULO << endline;
    cout << task1(a, n) % MODULO;
    //finish();
    return 0;
}
