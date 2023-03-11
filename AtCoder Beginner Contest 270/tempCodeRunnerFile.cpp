#include <bits/stdc++.h>
using namespace std;
 
// An utility function to add an edge in the tree
void addEdge(vector<vector<int32_t>> &adj, int x,
             int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
 
// running dfs to find level and parent of every node
void dfs(vector<vector<int32_t>> &adj, int node, int l,
            int p, vector<int32_t> &lvl, vector<int> &par)
{
   lvl[node] = l;
   par[node] = p;
   
   for(int child : adj[node])
   {
      if(child != p)
        dfs(adj, child, l+1, node, lvl, par);
   }
}
 
int LCA(int a, int b, vector<int32_t> &par, vector<int> &lvl)
{ 
   // if node a is at deeper level than
   // node b
   if(lvl[a] > lvl[b])
    swap(a, b);
    
   // finding the difference in levels
   // of node a and b
   int diff = lvl[b] - lvl[a];
    
   // moving b to the level of a
   while(diff != 0)
   {
      b = par[b];
      diff--;
   }
    
   // means we have found the LCA
   if(a == b)
    return a;
    
   // finding the LCA
   while(a != b)
    a=par[a], b=par[b];
 
   return a;
}
 
void printPath(vector<vector<int32_t>> &adj, int a, int b, int n)
{
    // stores level of every node
    vector<int> lvl(n + 1), par(n + 1);
   
   
    // running dfs to find parent and level
    // of every node in the tree
    dfs(adj, 1, 0, -1, lvl, par);
     
    // finding the lowest common ancestor
    // of the nodes a and b
    int lca = LCA(a, b, par, lvl);
   
    // stores path between nodes a and b
    vector<int> path;
     
    // traversing the path from a to lca
    while(a != lca)
      path.push_back(a), a = par[a];
 
    path.push_back(a);
 
    vector<int> temp;
     
    // traversing the path from b to lca
    while(b != lca)
      temp.push_back(b), b=par[b];
     
    // reversing the path to get actual path
    reverse(temp.begin(), temp.end());
   
    for(int x : temp)
      path.push_back(x);
   
    // printing the path
    for(int i = 0; i < path.size() - 1; i++)
      cout << path[i] << " ";
   
    cout << path[path.size() - 1] << endl;
}
 
// Driver Code
int main()
{  
  /*                          1
  
                        /            \
 
                     2                7
 
               /             \
 
             3                6
 
    /        |        \
 
  4          8          5
   
 */
	(void)!freopen ("input.inp","r",stdin);
	(void)!freopen ("output.out","w",stdout);
    // number of nodes in the tree
    int n, x, y;
     
    // adjacency list representation of the tree
	cin >> n >> x >> y;
    vector<vector<int>> adj(n + 1);
	for(int32_t i = 1; i <= n; i ++)
	{
		int32_t a, b;
		cin >> a >> b;
		addEdge(adj, a, b);
	}
    printPath(adj, x, y, n);
    
    return 0;
}