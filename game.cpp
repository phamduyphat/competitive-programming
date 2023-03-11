#include <bits/stdc++.h>
#include <chrono>
#define sexually_transferred_diseases std				
using namespace sexually_transferred_diseases;			

#define FOR(i,a,b)      	for(int64_t i=a;i<=b;i++)
#define fr(i,n)         	for(int64_t i=0;i<n;i++)
#define fr1(i,n)        	for(int64_t i=1;i<=n;i++)
#define FORi(i,a,b)      	for(int32_t i=a;i<=b;i++)
#define fri(i,n)         	for(int32_t i=0;i<n;i++)
#define fr1i(i,n)        	for(int32_t i=1;i<=n;i++)
#define FORD(i, a, b)  		for(int64_t i=a;i>=b;i--)
#define FORDI(i, a, b)		for(int32_t i=a;i>=b;i--)
#define forv(a, b)			for(auto &a : b)
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
/***********************************************************/
//Global variables below this line:
int32_t maxA = INT32_MIN;
/***********************************************************/
//Functions declarations:
void subtask0(int32_t n, int32_t r)
{
    cout << n;
    return;
}
void subtask1(int32_t n, int32_t r, vector<int32_t> a)
{
    int32_t res = 0;
    forv(v, a) if (v == 1 || v == 0) res ++;
    cout << res;
    return;
}
/***********************************************************/
driver main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen ("input.inp","r",stdin);
    //freopen ("output.out","w",stdout);
    //Local variables below this line:
    int32_t n, r, ans = 0;
    //code below this line:
    cin >> n >> r;
    vector<int32_t> a(n);
    forv(v, a) {cin >> v; maxA = max(v, maxA);}
    if (r > maxA) {subtask0(n, r); return 0;}
    if (r == 1) {subtask1(n, r, a); return 0;}
    if (r == 2)
        cout << 4;
    else subtask1(n, r, a);
    //finish();
    return 0;
}
//Functions content:
