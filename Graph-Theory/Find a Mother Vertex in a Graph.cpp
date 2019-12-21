/*

		###  Find a Mother Vertex in a Graph  ###

Question : What is a Mother Vertex ?
Answer : A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be 
	 reached by a path from v.

Example : https://media.geeksforgeeks.org/wp-content/cdn-uploads/mother1.png

Note that : There can be more than one mother vertices in a graph. We need to output anyone of them.

--------------

Useful Link : https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

--------------

How to find mother vertex?

Case 1:- Undirected Connected Graph : In this case, all the vertices are mother vertices as we can 
	 reach to all the other nodes in the graph.
		 
Case 2:- Undirected/Directed Disconnected Graph : In this case, there is no mother vertices as we 
	 cannot reach to all the other nodes in the graph.

Case 3:- Directed Connected Graph : In this case, we have to find a vertex -v in the graph such that 
	 we can reach to all the other nodes in the graph through a directed path.

A Naive approach : A trivial approach will be to perform a DFS/BFS on all the vertices and find whether 
		   we can reach all the vertices from that vertex. This approach takes O(V(E+V)) time, 
		   which is very inefficient for large graphs.


Question : Can we do better ?
Answer :  We can find a mother vertex in O(V+E) time. The idea is based on Kosaraju’s Strongly Connected 
	  Component Algorithm. In a graph of strongly connected components, mother vertices are always 
	  vertices of source component in component graph. The idea is based on below fact.

If there exist mother vertex (or vertices), then one of the mother vertices is the last finished vertex 
in DFS. (Or a mother vertex has the maximum finish time in DFS traversal).

A vertex is said to be finished in DFS if a recursive call for its DFS is over, i.e., all descendants of 
the vertex have been visited.

Question : How does the above idea work ?
Answer :  Let the last finished vertex be v. Basically, we need to prove that there cannot be an edge from 
	  another vertex u to v if u is not another mother vertex (Or there cannot exist a non-mother vertex 
	  u such that u-?v is an edge). There can be two possibilities.

Recursive DFS call is made for u before v. If an edge u-?v exists, then v must have finished before u because 
v is reachable through u and a vertex finishes after all its descendants. Recursive DFS call is made for v 
before u. In this case also, if an edge u-?v exists, then either v must finish before u (which contradicts 
our assumption that v is finished at the end) OR u should be reachable from v (which means u is another mother 
vertex).


Algorithm :

Step-1 : Do DFS traversal of the given graph. While doing traversal keep track of last finished vertex ‘v’. This 
	 step takes O(V+E) time.
Step-2 : If there exist mother vertex (or vetices), then v must be one (or one of them). Check if v is a mother 
	 vertex by doing DFS/BFS from v. This step also takes O(V+E) time.

------------

Time Complexity : O(V + E)

------------

Below is implementation of above algorithm.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10005
#define ep emplace_back

int n,m;
vector<bool> visited(M,false);
vector<int> adjList[M];

void dfs(int source)
{
	visited[source] = true;
	for(int i:adjList[source])
	{
		if(!visited[i])
			dfs(i);
	}
}

int findMotherVertex()
{	
	// To store last finished vertex (or mother vertex)
	int lastFinishedNode = 0;
	
	// Do a DFS traversal and find the last finished vertex   
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs(i);
			
			// If there exist mother vertex (or vetices) in given graph, then lastFinishedNode must be one of them. 
			lastFinishedNode = i;
		}
	}
	
   	// Reset all values in visited[] as false 
	visited.assign(n,false);
  
  	// doing DFS beginning from lastFinishedNode to check if all vertices are reachable from it or not.
	dfs(lastFinishedNode);
	
    	// Now check if lastFinishedNode is actually a mother vertex (or graph has a mother vertex).  We basically check 
	// if every vertex is reachable from lastFinishedNode or not.
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			return -1;				// if no mother vertex found
	}
	
	return lastFinishedNode;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "rt", stdin);
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);		// Directed ( Connected ) Graph
	}
	
	int ans = findMotherVertex();
	
	if(ans == -1)
		cout<<"No Mother vertex found !";
	else
		cout<<"Mother vertex is : "<<ans<<"\n";
}


/*

Input :
6 8
0 2
0 4
5 0
1 4
1 5
2 3
2 4
4 5

Output:
Mother vertex is : 1

-----------

Input :
6 8
0 2
0 4
0 5
1 4
1 5
2 3
2 4
4 5

Output:
No Mother vertex found !

-----------

Input :
7 8
0 1
0 2
1 3
4 1
6 4
5 6
5 2
6 0

Output :
Mother vertex is : 5

*/
