//BE OK 
#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+10;
int a[4][N],b[4][N],dp[16][N],n,res=-1e6,kq=-1e6;
int ok[16]={1,1,1,0,1,1,0,0,1,1,1,0,0,0,0,0};
int getbit(int j, int x)
{
	return (x >> j) & 1;// lấy bit j của trạng thái x
}
int getsum(int i, int x)
{
	int tmp=0;
	forin(j,0,3)
	{
		if(getbit(j,x)) tmp+=a[j][i];// kiểm tra bit 1 của x 
	}
	return tmp;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	forin(i,1,n)
	{
		forin(j,0,3) 
		{
			cin >>  a[j][i];
			res=max(res,a[j][i]);
		}
	}
	if(res <= 0) 
	{
		cout << res;
		return 0;
	}
	forin(i,1,n)
	{
		forin(x,0,15)
		{
			if(ok[x])
			{
				int s=getsum(i,x);
				dp[x][i]=-1e6;
				forin(y,0,15)
				{
					if(ok[y] && (x&y)==0)
					{
						dp[x][i]=max(dp[x][i],dp[y][i-1]+s);
					}
				}
			}
		}
	}
	forin(x,0,15)
	{
		if(ok[x]) kq=max(kq,dp[x][n]);
	}
	cout << kq;
}