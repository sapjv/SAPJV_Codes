/*

		#### Floyd–Warshall's Algorithm ( uses Dynamic Programming ) ####
 
Floyd–Warshall's Algorithm is an algorithm for finding shortest paths between all pairs of 
vertices in a weighted graph ( both directed or undirected ) with positive or negative edge 
weights (but with no negative cycles).

Note : A negative cycle is a cycle whose edges sum to a negative value. There is no shortest 
	   path between any pair of vertices {\displaystyle i}i, {\displaystyle j}j which form 
	   part of a negative cycle, because path-lengths from i to j can be arbitrarily small
	   (negative). For numerically meaningful output, the Floyd–Warshall algorithm assumes 
	   that there are no negative cycles. Nevertheless, if there are negative cycles, the 
	   Floyd–Warshall algorithm can be used to detect them. To detect negative cycles using 
	   the Floyd–Warshall algorithm, one can inspect the diagonal of the path matrix, and 
	   the presence of a negative number indicates that the graph contains at least one 
	   negative cycle.

Applications of Floyd–Warshall algorithm :

(A) Shortest paths between all pairs of vertices in an weighted directed graphs (Floyd's algorithm).
(B) Transitive closure of directed graphs (Warshall's algorithm). In Warshall's original 
	formulation of the algorithm, the graph is unweighted and represented by a Boolean 
	adjacency matrix. Then the addition operation is replaced by logical conjunction 
	(AND) and the minimum operation by logical disjunction (OR).
(C) Optimal routing. In this application one is interested in finding the path with the 
	maximum flow between two vertices. This means that, rather than taking minima as in 
	the pseudocode above, one instead takes maxima. The edge weights represent fixed 
	constraints on flow. Path weights represent bottlenecks; so the addition operation 
	above is replaced by the minimum operation.
(D) Fast computation of Pathfinder networks.
(E) Widest paths/Maximum bandwidth paths
(F) Computing canonical form of difference bound matrices (DBMs)
(G) Computing the similarity between graphs


Comparison with other shortest path algorithms : The Floyd–Warshall algorithm is a good 
choice for computing paths between all pairs of vertices in dense graphs, in which most 
or all pairs of vertices are connected by edges. For sparse graphs with non-negative 
edge weights, a better choice is to use Dijkstra's algorithm from each possible starting 
vertex, since the running time of repeated Dijkstra ( O(|E||V|+|V|^{2}log|V|) using 
Fibonacci heaps) is better than the O(|V|^{3}) running time of the Floyd–Warshall 
algorithm when |E| is significantly smaller than |V|^{2}. 

-------------------------------

Useful Videos ( Must Watch ): 

Video-1 : https://www.youtube.com/watch?v=oNI0rf2P9gE&t=595s
Video-2 : https://www.youtube.com/watch?v=LwJdNfdLF9s&t=2s

--------------------------------

HackerEarth Notes : Floyd–Warshall's Algorithm is used to find the shortest paths between 
all pairs of vertices in a graph, where each edge in the graph has a weight which is 
positive or negative. The biggest advantage of using this algorithm is that all the 
shortest distances between any 2 vertices could be calculated in O(V^3) , where V is the 
number of vertices in a graph.

The Algorithm Steps:

For a graph with N vertices :

	Step 1 : Initialize the shortest paths between any 2 vertices with Infinity.
	Step 2 : Find all pair shortest paths that use 0 intermediate vertices, then find the 
		 	 shortest paths that use 1 intermediate vertex and so on.. until using all N vertices 
			 as intermediate nodes.
	Step 3 : Minimize the shortest paths between any 2 pairs in the previous operation.
	Step 4 : For any 2 vertices (i,j) , one should actually minimize the distances between this 
			 pair using the first K nodes, so the shortest path will be: min ( dist[i][k] , dist[i][k] + dist[k][j] ).
	
dist[i][k] represents the shortest path that only uses the first K vertices, dist[k][j] 
represents the shortest path between the pair k,j. As the shortest path will be a 
concatenation of the shortest path from i to k, then from k to j.

-------------------------------

Time Complexity of Floyd–Warshall's Algorithm is O(V^3) , where V is the number of vertices in a graph.

-------------------------------

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define ep emplace_back
#define MAX 99999

int graph[1000][1000];			// this is initial given matrix
int dist[1000][1000];			// this will store the shortest distance between all pairs of vertices in the graph
int path[1000][1000];			// this will store the shortest route between all pairs of vertices in the graph

int nodes,e;

// Recursive function to print the path of the given vertex end from source vertex start 
void getPath(int start,int end)
{
	if(path[start][end]==start)
        return;
    getPath(start,path[start][end]);
    cout << path[start][end] << " -> ";
}

// function to print the shortest distance and shortest route/path between all
// pairs of vertices in the graph
void printPath()
{
	// printing shortest distance matrix
	cout<<"\nShortest distance Matrix : \n";
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		cout<<dist[i][j]<<" ";
		cout<<"\n";
	}
	
	
	// printing shortest path/route between all pairs of vertices in the graph
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(i!=j && path[i][j] != -1)
			{
				cout<<"\nShortest Path from vertex " <<i<<" to vertex "<<j<<" : ";
				cout<< i << " -> " ;
				getPath(i,j);			// calling getPath() to get shorteest path between vertex i and vertex j
				cout << j ;
			}
		}
		cout<<"\n";
	}
}

// this function will detect negative edge weight cycle in the graph ( if any )
void Check_Negative_Weight_Cycle()
{
	// if any entry of the right diagonal (\) is negative, then it means the graph have negative edge weight cycle
	for(int i=0;i<nodes;i++)
	{
		if(dist[i][i]<0)		
		{
			cout<<"\n Negative Edge Weight Cycle Detected ! \n";
			return;
		}
	}
}

void floydWarshal()
{
	// dist[][] and path[][] will store the shortest path and shortest route information
	// initializing path[][] and dist[][]
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			// initially distance will be same as the weight of the edge
			dist[i][j] = graph[i][j];
			
			if(graph[i][j]!=MAX && i!=j)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}
	
	// this is floyd warshal algorithm
	for(int k=0;k<nodes;k++)
	{
		for(int i=0;i<nodes;i++)
		{
			for(int j=0;j<nodes;j++)
			{
				// if the vertex k is on the shortest path from v to u, then 
				// we'll update the value of dist[i][j] and path[i][j]
				if(dist[i][j] > dist[i][k] + dist[k][j] )
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
 	freopen("input.txt", "rt", stdin);
 	
 	cin>>nodes>>e;
 	
 	// Initializing matrix by these default values
 	for(int i=0;i<nodes;i++)
 	{
 		for(int j=0;j<nodes;j++)
 		{
 			if(i==j)
 			graph[i][i] = 0;
 			else
 			graph[i][j] = MAX;			// will be change below if there is an edge given
		}
	}
 	
 	// getting edges and their weights and assigning the weight to the appropriate edge
 	// rest edges will have MAX weights ( see video for more and better understandings ) 
 	for(int i=0;i<e;i++)
 	{
 		int u,v,weight;
 		cin>>u>>v>>weight;
 		graph[u][v] = weight;
	}
	 
	floydWarshal();			
	
	printPath();			// this will print the shortest distance and shortest paths between all the pairs of vertices in the graph
			
	Check_Negative_Weight_Cycle();			// detecting if there any negative edge weight cycle in the graph or not
 	
}



/*
input ( Directed graph ): 

4 5
1 0 4
0 2 -2
1 2 3
3 1 -1
2 3 2



Output :

Shortest distance Matrix :
0 -1 -2 0
4 0 2 4
5 1 0 2
3 -1 1 0

Shortest Path from vertex 0 to vertex 1 : 0 -> 2 -> 3 -> 1
Shortest Path from vertex 0 to vertex 2 : 0 -> 2
Shortest Path from vertex 0 to vertex 3 : 0 -> 2 -> 3

Shortest Path from vertex 1 to vertex 0 : 1 -> 0
Shortest Path from vertex 1 to vertex 2 : 1 -> 0 -> 2
Shortest Path from vertex 1 to vertex 3 : 1 -> 0 -> 2 -> 3

Shortest Path from vertex 2 to vertex 0 : 2 -> 3 -> 1 -> 0
Shortest Path from vertex 2 to vertex 1 : 2 -> 3 -> 1
Shortest Path from vertex 2 to vertex 3 : 2 -> 3

Shortest Path from vertex 3 to vertex 0 : 3 -> 1 -> 0
Shortest Path from vertex 3 to vertex 1 : 3 -> 1
Shortest Path from vertex 3 to vertex 2 : 3 -> 1 -> 0 -> 2

*/
