/*

# Strongly Connected Components using KosaRaju's Algorithm for Directed Graph #

Definition of Strongly Connected Components ( SCCs ) : A directed graph is 
strongly connected if there is a path between all pairs of vertices. 

-------------------------------

Before understanding the algorithm properly and effectively, first 
watch these videos : 

Video 1 : https://www.youtube.com/watch?v=ju9Yk7OOEb8 ( Must watch )
Video 2 : https://www.youtube.com/watch?v=RpgcYiky7uw&t=1s ( Must watch )

-------------------------------
 
Following is detailed Kosaraju’s algorithm :

1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS 
   traversal, after calling recursive DFS for adjacent vertices of a
   vertex, push the vertex to stack. 

2) Reverse directions of all the arrows of adjList to obtain the 
   transpose of the given graph in revAdjList.

3) Now, One by one pop a vertex from S while S is not empty. Let the
   popped vertex be ‘v’. Then, Take v as source and do DFS on the revAdjList.
   Then, The DFS starting from v prints strongly connected component of v.

-------------------------------------

Time Complexity : The above algorithm calls DFS, finds reverse of the graph 
and again calls DFS. DFS takes O(V+E) for a graph represented using adjacency
list. Reversing a graph also takes O(V+E) time. For reversing the graph, we 
simple traverse all adjacency lists.

-------------------------------------

Note : The above algorithm is asymptotically best algorithm, but there are other 
algorithms like Tarjan’s algorithm and path-based which have same time complexity
but find SCCs using single DFS.

*/ 


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define ep emplace_back

vector<int> adjList[10000];
vector<int> revAdjList[10000];
vector<bool> visited;
stack<int> st;

int nodes,edges;

void dfs_on_reverse(int source)				// dfs2 on reversed graph
{
	visited[source] = true;
	cout<<source<<" ";
	for(int i:revAdjList[source])
	{
		if(!visited[i])
		dfs_on_reverse(i);
	}
}

void getTranspose()
{
	for(int v=0;v<nodes;v++)
	{
		for(int j:adjList[v])
		revAdjList[j].ep(v);
	}
}

void fill_stack_DFS(int source)				// This is DFS1 ( for filling values in stack )
{
	visited[source] = true;
	for(int i:adjList[source])
	{
		if(!visited[i])
		fill_stack_DFS(i);
	}
	st.push(source);		// All vertices reachable from v are processed by now, push v
}

void printSCCs()
{
	visited.assign(1000,false);
	
	for(int i=0;i<nodes;i++)
	{
		if(visited[i]==false)
		fill_stack_DFS(i);				// Filling vertices in stack according to their finishing times
	}
	
	getTranspose();				// Creating the reversed graph
	
	visited.assign(1000,false);			// Mark all the vertices again as not visited (For second DFS) 
	
	while(!st.empty())			// Now process all vertices in order defined by Stack 
	{
		int top = st.top();			// popping out the topmost vertex from the stack 
		st.pop();
		if(visited[top]==false)			// Print Strongly connected component of the popped vertex 
		{
			dfs_on_reverse(top);				// on revAdjList[]
			cout<<"\n";
		}
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
	
	cout<<"Strongly Connected Components are : \n";
	
	printSCCs();
	
} 




/*

input1 : for input graph, open this link : https://en.wikipedia.org/wiki/Strongly_connected_component#/media/File:Scc.png
8 14
0 1
4 0
1 5
1 4
1 2
2 3
3 2
2 6
5 6
6 5
3 7
7 3
7 6
6 5

Output1 : 
Strongly Connected Components are :
0 4 1
2 3 7
5 6

--------------------

input2 :  
5 5
1 0
0 2
2 1
0 3
3 4

Output2 :
Strongly Connected Components are :
0 4 1
2 3 7
5 6

------------------------

Why this above Algorithm works ?

Answer : The above algorithm is DFS based. It does DFS two times. DFS of a 
graph produces a single tree if all vertices are reachable from the DFS 
starting point. Otherwise DFS produces a forest. So DFS of a graph with 
only one SCC always produces a tree. The important point to note is DFS 
may produce a tree or a forest when there are more than one SCCs depending
upon the chosen starting point. For example, in the input2, if we
start DFS from vertices 0 or 1 or 2, we get a tree as output. And if we
start from 3 or 4, we get a forest. To find and print all SCCs, we would
want to start DFS from vertex 4 (which is a sink vertex), then move to 3
which is sink in the remaining set (set excluding 4) and finally any of 
the remaining vertices (0, 1, 2). So how do we find this sequence of 
picking vertices as starting points of DFS? Unfortunately, there is no 
direct way for getting this sequence. However, if we do a DFS of graph 
and store vertices according to their finish times, we make sure that 
the finish time of a vertex that connects to other SCCs (other that its 
own SCC), will always be greater than finish time of vertices in the other 
SCC (See this for proof). For example, in DFS of above example graph, 
finish time of 0 is always greater than 3 and 4 (irrespective of the 
sequence of vertices considered for DFS). And finish time of 3 is always
greater than 4. DFS doesn’t guarantee about other vertices, for example
finish times of 1 and 2 may be smaller or greater than 3 and 4 depending
upon the sequence of vertices considered for DFS. So to use this property, 
we do DFS traversal of complete graph and push every finished vertex to a
stack. In stack, 3 always appears after 4, and 0 appear after both 3 and 4.

Now, In the next step, we reverse the graph. Consider the graph of SCCs. In
the reversed graph, the edges that connect two components are reversed. So
the SCC {0, 1, 2} becomes sink and the SCC {4} becomes source. As discussed
above, in stack, we always have 0 before 3 and 4. So if we do a DFS of the
reversed graph using sequence of vertices in stack, we process vertices 
from sink to source (in reversed graph). That is what we wanted to achieve 
and that is all needed to print SCCs one by one.

*/
