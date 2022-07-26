#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
int main()
{
	//f_in("sample_in.txt");
	//f_out("sample_out.txt");
	int Size,i;
	cin>>Size;
	int a[Size],DP[Size];
	for(i=0;i<Size;i++)
		cin>>a[i];
	DP[0]=1;
	for(i=1;i<Size;i++)
	{
		if(a[i]>=a[i-1])
			DP[i]=DP[i-1]+1;
		else
			DP[i]=1;
	}
	int ans=0;
	for(i=0;i<Size;i++)
		ans=max(ans,DP[i]);
	cout<<ans<<endl;
	return 0;
}