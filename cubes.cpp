#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
const int mod= 111539786;
struct matrix{
	ll m[5][5];
};
matrix operator *(matrix a,matrix b)
{
	matrix c;
	forin(i,1,4)forin(j,1,4)
	{
		c.m[i][j] = 0;
		forin(k,1,4) c.m[i][j] = (c.m[i][j]+(a.m[i][k]*b.m[k][j])%mod)%mod;
	}
	return c;
}
matrix pw(matrix x,ll p)
{
	if(p==1)return x;
	matrix tmp = pw(x,p/2);
	tmp = tmp*tmp;
	if(p%2)return tmp*x;
	return tmp;
}
int main ()
{
	ll n;
	while(cin>>n)
	{
		if(n==0)cout<<1;
		else
		{
			matrix d;
			d.m[1][1] = 1; d.m[1][2] = 4; d.m[1][3] = 0; d.m[1][4] = 0;
			d.m[2][1] = 0; d.m[2][2] = 1; d.m[2][3] = 0; d.m[2][4] = 0;
			d.m[3][1] = 1; d.m[3][2] = 0; d.m[3][3] = 1; d.m[3][4] = 0;
			d.m[4][1] = 1; d.m[4][2] = 0; d.m[4][3] = 2; d.m[4][4] = 1;
			matrix ans = pw(d,n);
			cout<<(4*ans.m[4][1]+ans.m[4][2]+ans.m[4][3]+ans.m[4][4])%mod<<"\n";
		}
	}
}