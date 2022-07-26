#include <iostream>
using namespace std;
 
int64_t power(int64_t x, int32_t y, int32_t p)
{
    int64_t res = 1;     
 
    x = x % p;
  
    if (x == 0) return 0;
 
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;
 	    y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
// Driver code
int32_t main()
{
    uint64_t x, y, p;
    cin >> x >> y >> p;
    cout << power(x, y, p) * power (y, x, p) % p;
    return 0;
}