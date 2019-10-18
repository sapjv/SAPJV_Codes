/*

		### Detect Cycle in a directed graph using three colors ###
		
Task : Given a directed graph, check whether the graph contains a cycle or not. Your function should 
return true if the given graph contains at least one cycle, else return false.

Useful Video Link : 

1.  https://www.youtube.com/watch?v=rKQaZuoUR4M ( Must watch )
2.  https://www.youtube.com/watch?v=wQqFQeucFDc

-------------------------------------

The solution is from CLRS book. The idea is to do DFS of given graph and while doing traversal, assign 
one of the below three colors to every vertex :

	1. WHITE : Vertex is not processed yet.  Initially all vertices are WHITE.
	
	2. GRAY : Vertex is being processed (DFS for this vertex has started, but not finished which means
	    	  that all descendants (ind DFS tree) of this vertex are not processed yet (or this vertex 
		   	  is in function call stack).
	
	3. BLACK : Vertex and all its descendants are processed.

While doing DFS, if we encounter an edge from current vertex to a GRAY vertex, then this edge is back 
edge and hence there is a cycle.

--------------------------------------

Time Complexity : Time complexity of above solution is O(V + E) where V is number of vertices and E is 
				  number of edges in the graph.

*/


#include<bits/stdc++.h>
using namespace std;

int color[M];
vector<int> adjList[M];

int nodes;

enum threeColors{ WHITE , GRAY , BLACK };

// Recursive function to find if there is back edge in DFS subtree tree rooted with 'source' 
bool isCycle(int source)			// using DFS()
{
	/*
		GRAY :  This vertex is being processed (DFS for this vertex has started, but not 
	    ended (or this vertex is in function call stack) 
	*/
	color[source] = GRAY;
	for(int i:adjList[source])			// Iterating through all adjacent vertices 
	{
		if(color[i] == GRAY)
			return true;
		
		// If i is not processed and there is a back edge in subtree rooted with i
		if(color[i] == WHITE && isCycle(i))
			return true;
	}
	
	// Marking current vertex as processed 
	color[source] = BLACK;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	int edges;
	cin>>nodes>>edges;
	
	// Initializing color of all vertices as WHITE 
	for(int i=0;i<nodes;i++)
	color[i] = WHITE;
	
	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
	}
	
	int flag = 0;
	
	// Doing a DFS traversal beginning with all vertices 
	for(int i=0;i<nodes;i++)
	{
		if(color[i]==WHITE)
		{
			if(isCycle(i) == true)
			{
				flag = 1;
				cout<<"Cycle Detected\n";
				break;
			}
		}
	}
	
	if(flag == 0)
		cout<<"No Cycle Detected\n";
	
}
