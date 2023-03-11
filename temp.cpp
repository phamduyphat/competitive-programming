#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	double u1 = 1 / 4;
	int n = 10;
	while(n --)
	{
		u1 = u1 * u1 + u1 / 2;
		cout << u1 << endl;
	}
	return 0;
}