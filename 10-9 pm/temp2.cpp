#include <bits/stdc++.h>
#define fori(i,a,b) for(int i = a;i <= b;i ++)
#define fore(i,a,b) for(int i = a;i >= b;i --)
using namespace std;
typedef long long ll;
int const N = 1e3 + 10;
int a[N][N],b[N][N],n,m;
void speed()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
int res,dp[N][N];
int check[N * N]; 
int pos[N * N];
int cal(int x,int y,int u,int v)
{
	fori(i,x,u)
	{
		fori(j,y,v)
		{
			if(check[a[i][j]] == 1) return 0;
			check[a[i][j]] = 1;
		}
	}
	return (u - x + 1) * (v - y + 1);
}
void sub1()
{
	int k(0);
	fori(i,1,m) 
	{
		fori(j,1,n)
		{
			if(check[a[i][j]] == 0)
			{
				k ++;
				pos[k] = a[i][j];
			}
			check[a[i][j]] = 1;
		}
	}
	sort(pos + 1,pos + k + 1);
	//cout << cal(1,1,3,2);
	fori(i,1,k) check[pos[i]] = 0;
	fori(i,1,m)
	{
		fori(j,i,m)
		{
			fori(i1,1,n) 
			{
				fori(j1,i1,n) if((j - i + 1) * (j1 - i1 + 1) > res) {
				res = max(res,cal(i,i1,j,j1));fori(l,1,k) check[pos[l]] = 0;}
			}
			
		}
	}
	cout << res;
}
int main()
{
 	 freopen("BOARD.INP","r",stdin);
	freopen("BOARD.OUT","w",stdout);
	speed();
	cin >> m >> n;
	fori(i,1,m) fori(j,1,n) cin >> a[i][j];
	sub1();
	
}