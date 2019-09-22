/*

	#####  Topological Sort for Directed Acyclic Graph #####

Note : Acyclic means no cycle in the graph

Introduction : A topological sort or topological ordering of a directed graph is a linear 
ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u 
comes before v in the ordering. For instance, the vertices of the graph may represent tasks 
to be performed, and the edges may represent constraints that one task must be performed 
before another; in this application, a topological ordering is just a valid sequence for 
the tasks. A topological ordering is possible if and only if the graph has no directed 
cycles, that is, if it is a directed acyclic graph (DAG). Any DAG has at least one 
topological ordering


Note 1 : There can be more than one topological sorting for a graph. The first vertex in 
topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).


Topological Sorting vs Depth First Traversal (DFS): In DFS, we print a vertex and then recursively 
call DFS for its adjacent vertices. In topological sorting, we need to print a vertex before its 
adjacent vertices.

Applications: Topological Sorting is mainly used for scheduling jobs from the given dependencies 
among jobs. In computer science, applications of this type arise in instruction scheduling, 
ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic 
synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, 
and resolving symbol dependencies in linkers.


Time Complexity: The above algorithm is simply DFS with an extra stack. So time complexity is the 
				 same as DFS which is O(V+E).
	
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define ep emplace_back

vector<int> adjList[1000];
vector<bool> visited;

stack<int> st;	
int nodes,edges;


void topoUtil(int source)			// same as dfs
{
	visited[source] = true;			// Mark the current node as visited.
	for(int i:adjList[source])		// Recurring for all the vertices adjacent to source vertex 
	{
		if(!visited[i])
		topoUtil(i);
	}
	st.push(source);			// Push current vertex to stack which stores result ( line number for this step is different from DFS )
}

// This function finds Topological Sorting order for the DAG. It uses recursive topoUtil() 
void topologicalSort()
{
	// Call the recursive helper function to store Topological Sort starting from all vertices one by one 
	for(int i=0;i<nodes;i++)
	{
		if(!visited[i])
		topoUtil(i);
	}
	
	cout<<" Topological Sorting order : ";
	while(!st.empty())
	{
		cout<<st.top()<<" ";			// Printing contents of stack and this will be the resultant Topological Sorted order 
		st.pop();
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
 		adjList[u].ep(v);				// Topological sort is applicable only on DAG ( Directed Acyclic Graph )
	}
	
	visited.assign(nodes,false);		// Marking all the vertices as not visited initially 
	
	topologicalSort();
 	
}



/*

Input-1 :
6 6
5 2
5 0
4 0
4 1
2 3
3 1

Output-1 :
Topological Sorting order : 5 4 2 3 1 0

--------------

Input-2 :
6 6
0 1
1 2
2 3
2 4
0 3
3 4

Output-2 :
Topological Sorting order : 0 1 5 2 3 4 / 5 0 1 2 3 4

--------------------

Note : Here, we can also use vector instead of stack. If the vector is used then print the 
elements in reverse order to get the topological sorting. We can modify DFS to find 
Topological Sorting of a graph. In DFS, we start from a vertex, we first print it and then 
recursively call DFS for its adjacent vertices. In topological sorting, we use a temporary 
stack. We don’t print the vertex immediately, we first recursively call topological sorting 
for all its adjacent vertices, then push it to a stack. Finally, print contents of stack. 
Note that a vertex is pushed to stack only when all of its adjacent vertices (and their 
adjacent vertices and so on) are already in stack.

*/
