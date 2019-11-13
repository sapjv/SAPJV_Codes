/*
		###  Bridges in a Graph  ###

Useful Video :  https://www.youtube.com/watch?v=8Xv03VytWLM

Question :  https://www.spoj.com/problems/EC_P/  ( check my solution )
		
-----------------
		
Wikipedia :  https://en.wikipedia.org/wiki/Bridge_(graph_theory)
		
In graph theory, a bridge, isthmus, cut-edge, or cut arc is an edge of a graph whose deletion increases its number of 
connected components. Equivalently, an edge is a bridge if and only if it is not contained in any cycle. A graph is 
said to be bridgeless or isthmus-free if it contains no bridges.

A graph with n nodes can contain at most n-1 bridges, since adding additional edges must create a cycle. The graphs 
with exactly n-1 bridges are exactly the trees, and the graphs in which every edge is a bridge are exactly the forests.

Bridges are closely related to the concept of articulation vertices, vertices that belong to every path between some pair 
of other vertices. The two endpoints of a bridge are articulation vertices unless they have a degree of 1, although it may 
also be possible for a non-bridge edge to have two articulation vertices as endpoints. Analogously to bridgeless graphs 
being 2-edge-connected, graphs without articulation vertices are 2-vertex-connected.

In a cubic graph, every cut vertex is an endpoint of at least one bridge.


Tarjan's bridge-finding algorithm : The first linear time algorithm for finding the bridges in a graph was described by Robert 
									Tarjan in 1974. It performs the following steps :

Step 1 : Find a spanning forest of G
Step 2 : Create a rooted forest F from the spanning tree
Step 3 : Traverse the forest F in preorder and number the nodes. Parent nodes in the forest now have lower numbers than child nodes.
Step 4 : For each node v in preorder (denoting each node using its preorder number), do:
		(a) Compute the number of forest descendants ND(v) for this node, by adding one to the sum of its children's descendants.
		(b) Compute L(v), the lowest preorder label reachable from v by a path for which all but the last edge stays within the 
			subtree rooted at v. This is the minimum of the set consisting of the preorder label of v, of the values of L(w) at 
			child nodes of v and of the preorder labels of nodes reachable from v by edges that do not belong to F.
		(d) Similarly, compute H(v), the highest preorder label reachable by a path for which all but the last edge stays within 
			the subtree rooted at v. This is the maximum of the set consisting of the preorder label of v, of the values of H(w) 
			at child nodes of v and of the preorder labels of nodes reachable from v by edges that do not belong to F.
		(e) For each node w with parent node v, if L(w)=w and H(w)<w+ND(w) then the edge from v to w is a bridge.

-----------------------

GeeksforGeeks : https://www.geeksforgeeks.org/bridge-in-a-graph/

An edge in an undirected connected graph is a bridge iff removing it disconnects the graph. For a disconnected undirected graph, 
definition is similar, a bridge is an edge removing which increases number of disconnected components.

Like Articulation Points, bridges represent vulnerabilities in a connected network and are useful for designing reliable networks. 
For example, in a wired computer network, an articulation point indicates the critical computers and a bridge indicates the 
critical wires or connections.

A O(V+E) algorithm to find all Bridges : The idea is similar to O(V+E) algorithm for Articulation Points. We do DFS traversal 
of the given graph. In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does not exist any other 
alternative to reach u or an ancestor of u from subtree rooted with v. As discussed in the Articulation Point, the value low[v] 
indicates earliest visited vertex reachable from subtree rooted with v. The condition for an edge (u, v) to be a bridge 
is, “low[v] > disc[u]”.

Time Complexity: The Time complexity is same as DFS which is O(V+E) for adjacency list representation of graph.

-----------------------

A cut edge e = uv is an edge whose removal disconnects u from v. Clearly such edges can be found in O(m^2) ( where m is number 
of edges in the graph ) time by trying to remove all edges in the graph. 

We can get to O(m) based on the following two observations:

Step 1 : All cut edges must belong to the DFS tree.
Step 2 : A tree edge uv with u as v’s parent is a cut edge if and only if there are no edges in v’s subtree that goes to u or higher.

Strategy : We need compute for each subtree, the lowest node in the DFS tree that a back edge can reach. This value can either be 
the depth of the other end point, or the discovery time. 

Complexity : if V is number of vertices in the graph , E is the number of edges in the graph

Worst case time complexity: T(V+E)
Average case time complexity: T(V+E)
Best case time complexity: T(V+E)
Space complexity: T(V)

Applications of bridges in the graph : 

1. Cut edge denotes a critical edge that when removed, splits the graph into two components. It has real-world applications in the 
relation that cut edges may denote roads that need regular maintainence to ensure smooth traffic flow within an area.

2. Cut edges can, also, be seen as edges that needs to be removed to end up with strongly connected components.

-----------------------

Important Note : This below code is exactly similar to the complete code of Articulation Point in my Github. The only change in both
				the codes is this : there is no AP[] array in below code. And one extra if() condition is added for finding the bridges 
				in the graph. Also extra lines of the code of Articulation Point is removed. ( for more clearance, you can compare 
				both the codes ).


*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10005
#define ep emplace_back

vector<int> adjList[M];

bool visited[M];				// there is no need of AP[] array for finding the bridges in the graph
int low[M],discovered[M];		

vector<pair<int,int> > bridge;	

int n,m,current_time;

void dfs(int source,int parent)
{
	visited[source] = true;
	discovered[source] = low[source] = current_time + 1;
	int child = 0;
	for(int v:adjList[source])
	{
		if(v==parent)
			continue;
		if(!visited[v])
		{
			child++;
			current_time++;
			dfs(v,source);	
			low[source] = min(low[source],low[v]);
			if(low[v]>discovered[source])			// this is the extra condition required to check for finding the bridges in a graph
				cout<<source<<" "<<v<<"\n";
			// some extra lines from here has been removed from the code of Articulation Point ( you can check that by comparing )
		}
		else
			low[source] = min(low[source],discovered[v]);		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	cin>>n>>m;
	
	// in main(), everything is exactly same as in the code of articulation point ( except the initialization of AP[] )
	
	for(int i=1;i<=n;i++)
	{
		adjList[i].clear();
		visited[i] = false;
		discovered[i] = 0;
		low[i] = INT_MAX;
	}
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	dfs(1,-1);		
}


/*

Input : 
7 7
2 3
3 1
2 4
2 7
4 6
5 6
3 7

Output : 
6 5
4 6
2 4
1 3

----------

Input : 
7 8
1 2
2 3
3 1
2 4
2 5
2 7
4 6
5 6

Output : 
2 7

----------

Input : 
6 5
2 3
1 5
1 6
2 6
3 4

Output : 
1 5
3 4
2 3
6 2
1 6

*/
