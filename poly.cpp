#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
const int e = 12345678;
long long n;
struct matrix
{
	long long m[4][4];
};
matrix operator* (matrix a, matrix b)
{
	matrix c;
	forin(i,1,2) forin(j,1,2)
	{
		c.m[i][j] = 0;
		forin(t,1,2) c.m[i][j] = (c.m[i][j] + (a.m[i][t]*b.m[t][j])%e)%e;
	}
	return c;
}
matrix pw(matrix a, long long p)
{
	if (p == 1) return a;
	matrix tmp = pw(a,p/2);
	tmp = (tmp * tmp);
	if (p%2 == 0) return tmp;
	else return (tmp*a);
}
int main()
{
    
	
	
		matrix x,y,z;
		x.m[1][1] = 1; x.m[1][2] = 1;
		x.m[2][1] = 1; x.m[2][2] = 2;
		y.m[1][1] = 0; y.m[2][1] = 1;
		y.m[1][2] = 0; y.m[2][2] = 0;
        z.m[1][1] = 0; z.m[1][2] = 0;
		z.m[2][1] = 0; z.m[2][2] = 0;
		int32_t a = 4;
		z = x;
		for (; a <= 100 ; a ++)
		{
		z = z * x;
		matrix k = z * y;
		cout << a << ": " <<  k.m[2][1]%e << endl;
		}
	
}
