/*

Problem :  https://www.spoj.com/problems/LCA/   ( solved )

Useful Link : 
1.  https://www.geeksforgeeks.org/lca-in-a-tree-using-binary-lifting-technique/
2.  https://cp-algorithms.com/graph/lca_binary_lifting.html
3.  https://iq.opengenus.org/binary-lifting-k-th-ancestor-lowest-common-ancestor/

Useful Videos : 
1.  https://www.youtube.com/watch?v=kOfa6t8WnbI&t=2687s
2.  https://www.youtube.com/watch?v=6Q7OrMi0Vvc

Binary Lifting is a dynamic programming approach where we pre-compute an array 
dp[1, n][1, log(n)] where dp[i][j] contains 2^j-th ancestor of node i. For 
computing the values of dp[][], the following recursion may be used :

	dp[i][j] = parent[i] if j = 0 and
	dp[i][j] = dp[dp[i][j – 1]][j – 1] if j > 0.

We first check whether a node is an ancestor of other or not and if one node is ancestor 
of other then it is the LCA of these two nodes otherwise we find a node which is not the 
common ancestor of both u and v and is highest(i.e. a node x such that x is not the common 
ancestor of u and v but dp[x][0] is) in the tree. After finding such a node (let it be x), 
we print the first ancestor of x i.e. dp[x][0] which will be the required LCA.

Time Complexity: The time taken in pre-processing is O(NlogN) and every query takes O(logN) 
time. So the overall time complexity of the solution is O(NlogN).

*/

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int lli;
typedef pair<lli,lli> P;
 
#define M 100005
#define ep emplace_back
#define mp make_pair

int logg;
int level[M] = {0};
vector<vector<int>> dp;
vector<int> adjList[M];

void dfs(int source,int parent)
{
	dp[source][0] = parent;
	
	// Using recursion formula to calculate the values of dp[][]
	for(int i=1;i<=logg;i++)
		dp[source][i] = dp[dp[source][i-1]][i-1];
	
	for(int v:adjList[source])
	{
		if(v!=parent)
		{
			level[v] = level[source] + 1;
			dfs(v,source);
		}
	}
}

int lca(int u,int v)
{
	// The node which is present farthest from the root node is taken as u 
	// If v is farther from root node then swap the two 
	if(level[u]<level[v])
		swap(u,v);
	
	// Finding the ancestor of u which is at same level as v 
	for(int i=logg;i>=0;i--)
	{
		// here (1<<i) means (int)pow(2,i)
		// please note that using (1<<i) instead of using (int)pow(2,i) will improve the execution time a lot      
		if((level[u]-(1<<i))>=level[v])      
			u = dp[u][i];
	}
	
	// If v is the ancestor of u then v is the LCA of u and v
	if(u == v)
		return u;
	
	// Finding the node closest to the root which is not the common ancestor of u and 
	// v i.e. a node x such that x is not the common ancestor of u and v but dp[x][0] is 
	for(int i=logg;i>=0;i--)
	{
		if(dp[u][i] != dp[v][i])
		{
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	
	// Returning the first ancestor of above found node 
	return dp[u][0];
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	logg = (int)ceil(log2(n));
	dp.assign(n+1,vector<int>(logg+1));
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=logg;j++)
			dp[i][j] = -1;
	}
	
	int root = 1;
	dfs(root,root);
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++)
	{
		int u,v;
		cin>>u>>v;
		int ans = lca(u,v);
		cout<<"LCA of "<<u<<" and "<<v<<" is : "<<ans<<"\n";
	}
}

/*

Input :
9 8
1 2
1 3
1 4
2 5
3 6
7 3
8 3
9 4
7
6 9
5 9
6 8
6 1
2 4
7 8
3 6

Output :
LCA of 6 and 9 is : 1
LCA of 5 and 9 is : 1
LCA of 6 and 8 is : 3
LCA of 6 and 1 is : 1
LCA of 2 and 4 is : 1
LCA of 7 and 8 is : 3
LCA of 3 and 6 is : 3

*/
