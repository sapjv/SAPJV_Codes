/*


Transitive Closure of a Graph : Given a directed graph, find out if a vertex v is 
reachable from another vertex u for all vertex pairs (u, v) in the given graph. 
Here reachable mean that there is a path from vertex u to v. The reach-ability 
matrix is called transitive closure of a graph.

Time Complexity : Usually O(V2) , But it might increase ( Often times ) to O(V3) for 
				  more dense graph.  ( where V = number of vertices )

Below are abstract steps of algorithm.

Step 1 : Create a matrix result[V][V] that would finally have transitive closure of 
given graph. Initialize all entries of result[][] as 0.

Step 2 : Call DFS for every node of graph to mark reachable vertices in result[][]. In
recursive calls to DFS, we don’t call DFS for an adjacent vertex if it is already
marked as reachable in result[][].

-----------------

Note : In an undirected graph, reachability between all pairs of vertices can be 
determined by identifying the connected components of the graph. Any pair of vertices
in such a graph can reach each other if and only if they belong to the same connected
component. The connected components of an undirected graph can be identified in 
linear time. In this program, we'll determine pairwise reachability in a directed graph.


-----------------
*/ 


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define ep emplace_back

vector<int> adjList[10000];
int result[10000][10000];		// To store transitive closure of the directed graph ( Do not use vector here, to avoid Run time Error )

int nodes,edges;

// A recursive DFS traversal function that finds all reachable vertices for source
void dfs(int source,int v)
{
	result[source][v] = true;			// Mark reachability of source with v as true.
	for(int i : adjList[v])					// Or we can write it as :  for(auto it = adj[v].begin(); it != adj[v].end(); it++) 
	{
		// Finding all the vertices reachable through v 
		if(result[source][i] == false)
		dfs(source,i);
	}
}

void transitiveClosure()			// The function to find transitive closure.
{
	for(int i=0;i<nodes;i++)			// Call the dfs() to get DFS traversal starting from all vertices one by one 
	dfs(i,i);			// Every vertex is reachable from self. 
	
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		cout<<result[i][j]<<" ";			// printing the required result ( transitive closure )
		cout<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
 	freopen("input.txt", "rt", stdin);
 	
 	cin>>nodes>>edges;
 	
 	for(int i=0;i<edges;i++)
 	{
 		int u,v;
 		cin>>u>>v;
 		adjList[u].ep(v);			// Directed Graph
	}
	
	transitiveClosure();
	
} 


/*

Input : 
4 6
0 1
0 2
1 2
2 0
2 3
3 3

Output :
1 1 1 1
1 1 1 1
1 1 1 1
0 0 0 1


----------------

Input : 
6 8
0 2
0 5
5 4
4 5
3 2
3 4
2 1
1 0

Output : 
1 1 1 0 1 1
1 1 1 0 1 1
1 1 1 0 1 1
1 1 1 1 1 1
0 0 0 0 1 1
0 0 0 0 1 1


*/
