#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=10;
int res=1e9;
int a[N][N];//w la 0 b la 1
void thaydoi(int i,int j)
{
    if (a[i][j]) a[i][j]=0;
    else a[i][j]=1;
}
void lat(int i,int j)
{
    thaydoi(i,j);
    thaydoi(i-1,j);
    thaydoi(i,j-1);
    thaydoi(i+1,j);
    thaydoi(i,j+1);
}
bool kt1()
{
    forin(i,1,4)
    {
        forin(j,1,4)
        {
            if (a[i][j]==0) return false;
        }
    }
    return true;
}
bool kt2()
{
    forin(i,1,4)
    {
        forin(j,1,4)
        {
            if (a[i][j]==1) return false;
        }
    }
    return true;
}
void backtrack(int i,int j,int doi)// i la hang j la cot
{
        if (i>4)
        {
            if (kt1()) res=min(res,doi);
            if (kt2()) res=min(res,doi);
        }
        else
        {
            int i2=i;
            int j2=j;
            j2++;
            if (j2==5)
            {
                j2=1;
                i2++;
            }
            backtrack(i2,j2,doi);
            lat(i,j);
             backtrack(i2,j2,doi+1);
             lat(i,j);
        }
}
int main()
{
    forin(i,1,4)
    {
        forin(j,1,4)
        {
            char b;
            cin>>b;
            if (b=='w') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    backtrack(1,1,0);
    if (res==1e9) cout <<-1;
    else cout <<res;
}
