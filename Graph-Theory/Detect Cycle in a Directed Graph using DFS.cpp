/*

		### Detect Cycle in a Directed Graph using DFS ###
		
Task : Given a directed graph, check whether the graph contains a cycle or not. Your function should 
return true if the given graph contains at least one cycle, else return false.

Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. 
There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that 
is from a node to itself (self-loop) or one of its ancestor in the tree produced by DFS.

For a disconnected graph, we get the DFS forest as output. To detect cycle, we can check for a cycle in 
individual trees by checking back edges.

To detect a back edge, we can keep track of vertices currently in recursion stack of function for DFS 
traversal. If we reach a vertex that is already in the recursion stack, then there is a cycle in the 
tree. The edge that connects current vertex to the vertex in the recursion stack is a back edge. We 
have used recStack[] array to keep track of vertices in the recursion stack.

Time Complexity : Time Complexity of below method is same as time complexity of DFS traversal which is O(V+E).

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 100001
#define ep emplace_back

vector<int> adjList[M];
vector<bool> visited;
vector<bool> recStack;
	
// Returns true if the graph contains a cycle, else false. 
bool isCycle(int source)			// using DFS
{
	if(visited[source] == false)
	{
		// Marking the current node as visited and part of recursion stack 
		visited[source] = true;
		recStack[source] = true;
		
		// Recurring for all the vertices adjacent to current vertex 
		for(int i:adjList[source])
		{
			if(!visited[i])
			{
				if(isCycle(i))			// calling like recursive DFS 
				return true;
			}
			else if(recStack[i])
			return true;
		}
	}
	
	// removing the current vertex from recursion stack 
	recStack[source] = false;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	int nodes,edges;
	cin>>nodes>>edges;
	
	// Marking all the vertices as not visited and not part of recursion stack 
	recStack.assign(nodes,false);
	visited.assign(nodes,false);
	
	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
	}
	
	int flag = 0;
	for(int i=0;i<nodes;i++)
	{
		// Calling the recursive isCycle() to detect cycle in different DFS trees 
		if(isCycle(i))
		{
			flag = 1;
			cout<<"Cycle Detected\n";			// Remember, there might be self loops too in the graph 
			break;
		}
	}
	
	if(flag==0)
	cout<<"No Cycle Detected\n";
	
}
