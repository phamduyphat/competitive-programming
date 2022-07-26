#include<bits/stdc++.h>
using namespace std;
int main ()
{
	queue<int>q[5];
	int t;cin>>t;
	while(t--)
	{
		char c;cin>>c;
		if(c=='E')
		{
			int a,b;cin>>a>>b;
			if(q[a].empty())q[0].push(a);
			q[a].push(b);
		}
		else 
		{
			if(!q[0].empty())
			{
				if(!q[q[0].front()].empty())
				{
					cout<<q[0].front()<<" "<<q[q[0].front()].front()<<"\n";
					q[q[0].front()].pop();
					if(q[q[0].front()].empty())q[0].pop();
				}
			}
			else cout<< -1<<"\n";
		}
	}
}