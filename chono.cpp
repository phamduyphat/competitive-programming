#include <stdio.h>
//#include <conio.h>

int main()
{
    //freopen("QBSELECT.in","r",stdin);
    int f[10001][18],a[10001][6],n,max=-100000,KQ=0;
    scanf("%d",&n);
    for(int i = 1;i<=4;i++)
        for(int j = 1;j<=n;j++)
        {
            scanf("%d",&a[j][i]);
            if(max<a[j][i])
                max = a[j][i];
        }
    if(max <=0)
        printf("%d",max);
    else
    {
        for(int i = 0;i<=15;i++)
            f[0][i] = 0;
        int x[5],y[5],u,v,flag,maxx,tong;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 0;j<=15;j++)
            {
                u=j;
                flag = 1;
                maxx = 0;
                tong = 0;
                for(int k = 1;k<=4;k++)
                {
                    x[k] = u%2;
                    u = u/2;
                    if(k > 1 && x[k]*x[k-1]>0)
                    {
                        flag = 0;
                        break;
                    }
                    if(x[k] == 1)
                       tong = tong + a[i][k];
                }
                if(flag ==0)
                    f[i][j] = 0;
                else
                {
                    for(int k = 0;k<=15;k++)
                    {
                        u = k;
                        flag = 1;
                        for(int l = 1;l<=4;l++)
                        {
                            y[l] = u%2;
                            u = u/2;
                            if((l > 1 && y[l]*y[l-1]>0)||(x[l]*y[l]>0))
                            {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag ==1 && f[i-1][k]>maxx)
                             maxx = f[i-1][k];        
                    }
                    f[i][j] = tong + maxx;
                }

            }
        }
        for(int i = 0;i<=15;i++)
        {
            if(f[n][i]>KQ)
                KQ = f[n][i];
        }
        printf("%d",KQ);        
    }
    //getch();
}