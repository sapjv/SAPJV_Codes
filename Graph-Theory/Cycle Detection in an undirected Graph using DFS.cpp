/*


	#### Detect cycle in an undirected graph using DFS ####
	
We can use DFS to detect cycle in an undirected graph in O(V+E) time. We do a DFS traversal of the given 
graph. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is 
not parent of v, then there is a cycle in graph. If we don’t find such an adjacent for any vertex, we say
that there is no cycle. 

---------------------

Note : The assumption of this approach is that there are no parallel edges between any two vertices.

---------------------

Useful Video Links :

1.  https://www.youtube.com/watch?v=n_t0a_8H8VY
2.  https://www.youtube.com/watch?v=6ZRhq2oFCuo

---------------------

Time Complexity : The program does a simple DFS Traversal of graph and graph is represented using adjacency 
				 list. So the time complexity is O(V+E)

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define M 100001
#define ep emplace_back

vector<int> adjList[M];
vector<bool> visited;

// Returns true if the graph contains a cycle, else false. 
bool dfs(int source,int parent)
{
	visited[source] = true;
	for(int i:adjList[source])
	{
		// If an adjacent is not visited, then recur for that adjacent 
		if(!visited[i])
		{
			if(dfs(i,source))
				return true;
		}
		
		// If an adjacent is visited and not parent of current vertex, then there is a cycle. 
		else if(i!=parent)
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
 	freopen("input.txt", "rt", stdin);
	
    int nodes,edges;
    cin>>nodes>>edges;
    
    for(int i=0;i<edges;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	adjList[u].ep(v);
    	adjList[v].ep(u);
	}
	
	visited.assign(M,false);
	
	int flag = 0;
	for(int i=0;i<=nodes;i++)
	{
		// Don't recur for node i if it is already visited
		if(!visited[i])
		{
			// Calling the dfs() recursive function to detect cycle in different DFS trees
			if(dfs(i,-1))
			{
				flag = 1;
				cout<<"Cycle Detected\n";
				break;
			}
		}
	}
	
	if(flag==0)
	cout<<"No Cycle Detected\n";
}    
