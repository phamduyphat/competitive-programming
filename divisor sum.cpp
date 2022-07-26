#include <bits/stdc++.h>
using namespace std;
int divisorSum(int n)
{
    int sum = 0;
 
    for(int i = 1; i <= n; ++i)
    {
         
        // Find all divisors of i and add them
        for(int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                if (i / j == j)
                    sum += j;
                else
                    sum += j + i / j;
            }
        }
    }
    return sum;
}
 
// Driver code
int main()
{
    long long n; cin >> n;
    cout << divisorSum(n);
     
    return 0;
}