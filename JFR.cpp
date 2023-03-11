#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
#define forde(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const long long mod = 1e9 +7;
const long long MODULO = 1e9 +7;

int64_t  mul(int64_t a, int64_t b)
{
    int64_t res = 0;
    a %= MODULO;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % MODULO;
        a = (a * 2) % MODULO;
        b /= 2;
    }
    return res % MODULO;
}
int64_t pow(int64_t a, int64_t b)
{
    int64_t res = 1;
    a %= b;
    if (a == 0) return 0;
    while(b > 0)
    {
        if (b & 1)
            res = mul(res, a);
        b /= 2;
        a = mul(a, a);
    }
    return res;
}
int main(){
	int n,k; 
	cin >> n >> k;
	vector<long long> gt(n + k + 2);
	gt[0]=1;
	for(int i=1;i<gt.size();i++){
		gt[i]=mul(gt[i-1] , i);
	}
	//forin(i,1,gt.size()-1) cout << gt[i] << " ";
	vector<long long> ifact(gt.size());
	//cout << gt.back();
	ifact[gt.size() - 1]=pow(gt[gt.size() - 1],mod-2);
	//cout << ifact.back();
	for(int i = ifact.size() - 2;i>=0;i--){
		ifact[i] = mul(ifact[i+1] ,(i+1));
	}	
	//forde(i,ifact.size()-1,1) cout << ifact[i] << " ";
	for(int32_t i = 0; i < gt.size(); i++)
		cout << mul(gt[i],ifact[i]) << " ";
	//cout << mul(2,5);
	//cout << pow(2,5);
}
