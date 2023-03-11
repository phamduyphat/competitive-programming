#include <bits/stdc++.h>
using namespace std;
long pow(long a, long b, long m){
    if(b == 0){
        return 1;
    }
    long x = pow(a,b/2,m);
    if(b % 2 == 0){
        return x*x % m;
    }
    return x*x % m * a % m;
}
int main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    const int m=1000000007,a=138591887,b=432836689,n1=940286410,n2=59713603;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        cout << ((a*pow(n1,n,m)) % m+(b*pow(n2,n,m)) % m) % m << '\n';
    }
}