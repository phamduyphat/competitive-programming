#include<bits/stdc++.h>
using namespace std;
//variables below this line
int n;
int64_t finans = 0;
string temp;
vector<vector<int>> pp(9, vector<int>(10,0));
//----------------------------------------

//smol function below this line


//----------------------------------------

//main function
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("bai1.inp", "r" , stdin);
    // freopen("bai1.out", "w" , stdout);

    //code below this line
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        for(int j = temp.length() - 1; j >= 0; j--)
            pp[j][*(temp.end() - 1 - j) - '0']++;
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 10; j++){
            finans += 1LL * (pp[i][j]) * (pp[i][j] - 1) / 2;
        }
    }

    cout << finans << "\n";
    //----------------------------------------
}