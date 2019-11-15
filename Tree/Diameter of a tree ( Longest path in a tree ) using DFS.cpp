/*
			
			###  Diameter of a tree ( Longest path in a tree ) using DFS  ###
		
Question Link :  https://www.spoj.com/problems/PT07Z/  ( check my solution )

Useful Link :  https://www.quora.com/How-does-following-algorithm-for-finding-longest-path-in-tree-work
		
Definition : The Diameter of a tree ( Longest path in a tree ) is the length of the longest path (from one node to 
			 another) in the tree. The length of a path is the number of edges we traverse from source to destination.
				OR
			 The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between 
			 two leaves in the tree.
			 
			 
Solution :  We'll discuss a DFS based solution. As we know that the longest path will always occur between two leaf 
			nodes. So, We start DFS from any random node and then find which node is farthest from it using DFS. Let 
			the node farthest be X. It is clear that X will always be a leaf node and a corner of DFS. Now if we start 
			DFS from X and check the farthest node from it, we will get the diameter of the tree.	
			

Algorithm :  There is a standard algorithm for finding longest path in undirected trees using two depth-first searches:

			 Step 1 :  Start DFS from a random vertex v and find the farthest vertex from it; say it is v'.
			 Step 2 :  Now start a DFS from v' to find the vertex farthest from it. This path is the longest path in 
			 		   the graph.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10001
#define ep emplace_back

vector<int> adjList[M];
vector<bool> visited;

int x;			// it will track farthest node. 

// Sets maxCount as maximum distance from node. 
void dfs(int source,int count,int &maxCount)
{
	visited[source] = true;
	count++;
	for(int i:adjList[source])
	{
		if(!visited[i])
		{
			if(count>=maxCount)
			{
				maxCount = count;
				x = i;
			}
			dfs(i,count,maxCount);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	freopen("input.txt","rt",stdin);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	int maxCount = INT_MIN;			// maxCount will have diameter of tree 
	
	int count = 0;
	visited.assign(n+1,false);			// Marking all the vertices as not visited 
	
	// Incrementing count by 1 for visited node
	dfs(1,count+1,maxCount);			// DFS from a random node and then see farthest node x from it
	
	visited.assign(n+1,false);			// Again Marking all the vertices as not visited for 2nd-DFS
	
	// Incrementing count by 1 for visited node 
	dfs(x,count+1,maxCount);		// DFS from x and check the farthest node from it using DFS
	
	int ans = maxCount-1;
	cout<<ans<<"\n";
}
