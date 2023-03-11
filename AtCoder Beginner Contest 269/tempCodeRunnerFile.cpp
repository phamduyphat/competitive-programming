#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define inf 1e18
#define N 100005
#define ls k<<1
#define rs k<<1|1
#define mid ((l+r)>>1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define il inline
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
il int read(){
    int w=0,h=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')h=-h;ch=getchar();}
    while(ch>='0'&&ch<='9'){w=w*10+ch-'0';ch=getchar();}
    return w*h;
}
signed main(){
	int n;cin>>n;
	int A=1,B=n,C=1,D=n,d=0;
	for(int i=1;i<=10;i++){
		int Mid=(A+B)>>1,num=Mid-A+1,sum;
		printf("? %d %d %d %d\n",A,Mid,1,n);
		cin>>sum;if(sum<num)B=Mid;else A=Mid+1;
		fflush(stdout);
	}
	for(int i=1;i<=10;i++){
		int Mid=(C+D)>>1,num=Mid-C+1,sum;
		printf("? %d %d %d %d\n",1,n,C,Mid);
		cin>>sum;if(sum<num)D=Mid;else C=Mid+1;
		fflush(stdout);
	}
	printf("! %d %d",A,C);
    return 0;
}
