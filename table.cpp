#include <bits/stdc++.h>
#include <chrono>
#define sexually_transferred_diseases std			
using namespace sexually_transferred_diseases;			

#define FOR(i,a,b)      	for(int64_t i=a;i<=b;i++)
#define fr(i,n)         	for(int64_t i=0;i<n;i++)
#define fr1(i,n)        	for(int64_t i=1;i<=n;i++)
#define forv(v, a)			for(auto &v : a)
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
#define MID (ll + (rr - ll) / 2)
#define Lcon id * 2 + 1, ll, MID
#define Rcon id * 2 + 2, MID + 1, rr
class typeQ{
	public:
		int32_t x, y, u, v, k, w, ans = 0;
};
struct segment{
	int64_t val = 0;
	int64_t pos;
};
segment *st;
int64_t *pos;
/*void lazy(int32_t id)
{
	st[id * 2].lazy = st[id].lazy;
	st[id * 2].val += st[id * 2].lazy;

	st[id * 2 + 1].lazy = st[id].lazy;
	st[id * 2 + 1].val += st[id * 2 + 1].lazy;
	
	st[id].lazy = 0;
	return;
}*/
void update(int32_t id, int32_t ll, int32_t rr, int32_t l, int32_t r, int32_t val)
{
	FOR(i, l, r)
	{
		id = pos[i];
		st[id].val += val;
		while(id > 0)
		{
			id /= 2;
			st[id].val = st[id * 2 + 1].val + st[id * 2 + 2].val;
		}
	}
	return;
}
int64_t Query(int32_t id, int32_t ll, int32_t rr, int32_t l, int32_t r)
{
	if (l > rr || r < ll) return 0;
	if (ll >= l && rr <= r)
		return st[id].val;

	return Query(Lcon, l, r) + Query(Rcon, l, r);
}
void build(int32_t id, int32_t ll, int32_t rr, vector<int64_t> a)
{
	if (ll == rr) {
		st[id].val = a[ll];
		pos[rr] = id;
		return;
	}
	build(Lcon, a);
	build(Rcon, a);
	st[id].val = st[id * 2 + 2].val + st[id * 2 + 1].val;
}
/***********************************************************/
driver main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen ("input.inp","r",stdin);
    freopen ("output.out","w",stdout);
    //Local variables below this line:
	int64_t m, n, T;
	cin >> m >> n >> T;
	vector<vector<int64_t>> a(m, vector<int64_t> (n));
	vector<typeQ> query;
    //code below this line:
    
	fr(i, m) fr(j, n) cin >> a[i][j];
	
	fr(i, T)
	{
		typeQ temp;
		cin >> temp.k;
		if (temp.k == 1) {cin >> temp.x >> temp.y >> temp.u >> temp.v >> temp.w;}
		else {cin >> temp.x >> temp.y >> temp.u >> temp.v; temp.w = 0;}
		query.push_back(temp);
	}
	fr1(i, m)
	{
		
		st = new segment[4 * n];
		pos = new int64_t[n];
		build(0, 0, n - 1, a[i - 1]);
		forv(v, query)
		{
			if (v.k == 1) 
				if(v.x <= i && v.u >= i)
					update(0, 0, n - 1, v.y - 1, v.v - 1, v.w);
			if (v.k == 2) 
				if(v.x <= i && v.u >= i)
					v.ans += Query(0, 0, n - 1, v.y - 1, v.v - 1);
		}
		delete [] st;
		delete [] pos;
	}
	forv(v, query) if (v.k == 2) cout << v.ans << endline;
    finish();
    return 0;
}
