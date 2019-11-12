/*
		### Finding Articulation Points in a graph ###
		
Useful videos :
 
1. https://www.youtube.com/watch?v=jFZsDDB0-vo
2. https://www.youtube.com/watch?v=EvShMOf5CRQ
3. https://www.youtube.com/watch?v=2kREIkF9UAs&t=1097s

		
Useful Links : 

1. https://codeforces.com/blog/searleser97
2. https://cp-algorithms.com/graph/cutpoints.html#toc-tgt-1
3. https://iq.opengenus.org/find-articulation-points-or-cut-vertices-in-a-graph/ 

---------------------------------

Definition :  We are given an undirected graph. An articulation point (or cut vertex) is defined as a vertex 
which, when removed along with associated edges, makes the graph disconnected (or more precisely, increases 
the number of connected components in the graph). The task is to find all articulation points in the given graph.
												(OR)
A vertex in an undirected connected graph is an articulation point or cut vertex if and only if removing it, and 
the edges connected to it, splits the graph into multiple components.

---------------------------------

Note : Given a DFS tree of a graph, a Back Edge is an edge that connects a vertex to a vertex that is discovered 
before it's parent.

Algorithm-1 ( from stackoverflow ) : 
Hint: Apply Depth First Search on a graph. 

Step 1 : Construct the DFS tree.
Step 2 : A node which is visited earlier is a "parent" of those nodes which are reached by it and visited later.
Step 3 : If any child of a node does not have a path to any of the ancestors of its parent, it means that removing 
		 this node would make this child disjoint from the graph. This means that this node is an articulation point.

Note that : There is an exception: the root of the tree. If it has more than one child, then it is an articulation 
			point, otherwise not.
			
Now for a child, this path to the ancestors of the node would be through a back-edge from it or from any of its children.

--------------------------------

Algorithm-2 ( https://cp-algorithms.com/graph/cutpoints.html#toc-tgt-1 ) : 

Step 1 : Pick an arbitrary vertex of the graph root and run depth first search from it. Note the following fact (which is 
		 easy to prove):

Step 2 : Let's say we are in the DFS, looking through the edges starting from vertex v?root. If the current edge (v,to) is 
		 such that none of the vertices to or its descendants in the DFS traversal tree has a back-edge to any of ancestors 
		 of v, then v is an articulation point. Otherwise, v is not an articulation point.

Step 3 : Let's consider the remaining case of v=root. This vertex will be the point of articulation if and only if this 
		 vertex has more than one child in the DFS tree.

Now we have to learn to check this fact for each vertex efficiently. We'll use "time of entry into node" computed by the 
depth first search.

So, let tin[v] denote entry time for node v. We introduce an array low[v] which will let us check the fact for each vertex 
v. low[v] is the minimum of tin[v], the entry times tin[p] for each node p that is connected to node v via a back-edge (v,p) 
and the values of low[to] for each vertex to which is a direct descendant of v in the DFS tree:

		low[v]=min(tin[v],tin[p],low[to])     
		
		Note => tin[p] : for all p for which (v,p) is a back edge AND low[to] : for all to for which (v,to) is a tree edge.
		
Now, there is a back edge from vertex v or one of its descendants to one of its ancestors if and only if vertex v has a child 
to for which low[to]<tin[v]. If low[to]=tin[v], the back edge comes directly to v, otherwise it comes to one of the ancestors 
of v.

Thus, the vertex v in the DFS tree is an articulation point if and only if low[to]>=tin[v].

-----------------------------------


Algorithm-3 ( GeeksforGeeks ) : A O(V+E) algorithm to find all Articulation Points (APs) :

The idea is to use DFS (Depth First Search). In DFS, we follow vertices in tree form called DFS tree. In DFS tree, a vertex 
u is parent of another vertex v, if v is discovered by u (obviously v is an adjacent of u in graph). In DFS tree, a vertex u 
is articulation point if one of the following two conditions is true.

1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the 
   ancestors (in DFS tree) of u.

Note that a leaf in DFS Tree can never be an articulation point.

------------------------------------

Implementation-4 ( https://codeforces.com/blog/searleser97 ) : 

Well, first thing we need is a way to know if some node A is ancestor of some other node V, for this we can assign a discovery 
time to each vertex V in the graph G based on the DFS traversal, so that we can know which node was discovered before or after
another. e.g. in G1 with the traversal A -> B -> C the dicovery times for each node will be respectively 1, 2, 3; with this 
we know that A was discovered before C since discovery_time[A] < discovery_time[C].

Now we need to know if some vertex U is an articulation point. So, for that we will check the following conditions:

1. If there is NO way to get to a node V with strictly smaller discovery time than the discovery time of U following the DFS traversal, 
then U is an articulation point. (it has to be strictly because if it is equal it means that U is the root of a cycle in the DFS 
traversal which means that U is still an articulation point).

2. If U is the root of the DFS tree and it has at least 2 children subgraphs disconnected from each other, then U is an 
   articulation point.

So, for implementation details, we will think of it as if for every node U we have to find the node V with the least discovery 
time that can be reached from U following some DFS traversal path which does not require to pass through any already visited 
nodes, and let's call this node low.

Then, we can know that U is an articulation point if the following condition is satisfied: discovery_time[U] <= low[V] ( V in 
this case represents an adjacent node of U ). To implement this, in each node V we will store some identifier of its corresponding 
node low found, this identifier will be the corresponding low's discovery time because it helps us to know when the node low was 
discovered, hence it helps us to know by which node we can discover U first.

--------------------------------------
 
Applications of Articulation Points ( Cut vertices ) : 

1. Cut vertices ( Articulation Points ) denote the vertices that are critical in keeping the graph connected. Removing the vertex 
results in splitting of the graph.

2. Think of a cut vertex as a person who keeps five communities connected. The person may be a motivational activist. If this person is 
taken off consideration, then the five different communities become separate and hence, is detrimental as it results in discrimination. 
Thus, the person (cut vertex) is very important and must be supported.

3. Articulation Points represent vulnerabilities in a network – single points whose failure would split the network into 2 or more 
disconnected components.

-------------------------------------

Complexity of the below code for finding the Articulation Points : 

1. Worst case time complexity: Theta(V+E)
2. Average case time complexity: Theta(V+E)
3. Best case time complexity: Theta(V+E)
4. Space complexity: Theta(V)

--------------------------------------

Note that below code is mostly based on above Algorithm-1 and Implementation-4.

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10005
#define ep emplace_back

vector<int> adjList[M];

// visited[] : It is an array of size N which denotes whether a vertex is visited or not during the DFS. It is initialized by false.
// AP[] : It is an array of size N. AP[i] = true, if ith vertex is an articulation point.
bool visited[M] , AP[M];

/*

low[i] is the minimum of visited current_time of all vertices which are reachable from i. It is an array of N elements which stores, 
for every vertex v, the discovery time of the earliest discovered vertex to which v or any of the vertices in the subtree rooted at 
v is having a back edge. It is initialized by INFINITY.

Let Low(v) = lowest-numbered vertex reachable from v using 0 or more spanning tree edges and then at most one back edge. i.e., 
			 Low(v) = minimum of { Num(v) , Lowest Num(w) among all back edges (v,w) , Lowest Low(w) among all tree edges (v,w) }
	   
discovered[] stores the discovery time of every vertex. It is initialized by 0. 

*/
int low[M],discovered[M];		

int n,m,current_time;		// current_time :	Current value of discovery time.

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
			low[source] = min(low[source],low[v]);		// checking if subtree rooted at i has a connection to one of the ancestors of source.
			if(parent == -1 && child>1)
				AP[source] = true;
			if(parent!=-1 && low[v]>=discovered[source])
				AP[source] = true;
		}
		else
			low[source] = min(low[source],discovered[v]);			// back edge
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	cin>>n>>m; 			// n = number of vertices, m = number of edges
	
	// initialization ( this is necessary )
	for(int i=1;i<=n;i++)
	{
		adjList[i].clear();
		visited[i] = false;
		AP[i] = false;
		discovered[i] = 0;
		low[i] = INT_MAX;
	}
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);			// undirected graph
	}
	
	dfs(1,-1);			// start dfs() from any random vertex, make its parent -1. 
	
	for(int i=1;i<=n;i++)
	{
		if(AP[i] == true)
			cout<<i<<" ";			// printing Articulation Points
	}
	
}


/*

Input 1 :

7 8
1 2
2 3
3 1
2 4
2 5
2 7
4 6
5 6

Output : 2

----------

Input 2 : 

6 6
1 2
2 3
3 1
1 4
2 5
3 6

Output : 1 2 3

-----------

Input 3 :

6 5
2 3
1 5
1 6
2 6
3 4

Output : 1 2 3 6

*/

