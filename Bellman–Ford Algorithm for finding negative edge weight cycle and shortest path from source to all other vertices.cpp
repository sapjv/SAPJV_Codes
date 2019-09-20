/*

### Bellman–Ford algorithm ###

The Bellman–Ford algorithm is an algorithm that computes shortest paths from a single 
source vertex to all of the other vertices in a weighted digraph ( digraph means 
directed graph ). It is slower than Dijkstra's algorithm for the same problem, but 
more versatile, as it is capable of handling graphs in which some of the edge weights 
are negative numbers.

Negative edge weights are found in various applications of graphs, hence the usefulness
of this algorithm. If a graph contains a "negative cycle" (i.e. a cycle whose edges 
sum to a negative value) that is reachable from the source, then there is no cheapest 
path: any path that has a point on the negative cycle can be made cheaper by one more 
walk around the negative cycle. In such a case, the Bellman–Ford algorithm can detect 
and report the negative cycle.

------------------------------

Useful Videos ( Must Watch ) : 

Video 1   :   https://www.youtube.com/watch?v=FtN3BYH2Zes
Video 2   :   https://www.youtube.com/watch?v=-mOEd_3gTK0

------------------------------
Bellman Ford's Algorithm ( HeckerEarth ) : Bellman Ford's algorithm is used to find the
shortest paths from the source vertex to all other vertices in a weighted graph. It 
depends on the following concept: Shortest path contains at most n-1 edges, because the 
shortest path couldn't have a cycle.

So why shortest path shouldn't have a cycle ?
There is no need to pass a vertex again, because the shortest path to all other vertices 
could be found without the need for a second visit for any vertices.
---------------------------------

Algorithm Steps: ( for more clear Algorithm , see CLRS book )

Step 1 :  The outer loop traverses from 0 : |nodes|-1 .
Step 2 :  Loop over all the edges, check if the 
		  ( next_node_distance > current_node_distance + edge_weight ), if it is true, then 
		  in this case update the next_node_distance to ( current node distance + edge 
		  weight ).
		  
---------------------------------

Summary : This algorithm depends on the relaxation principle where the shortest distance for 
		  all vertices is gradually replaced by more accurate values until eventually reaching 
		  the optimum solution. In the beginning all vertices have a distance of "Infinity", 
		  but only the distance of the source vertex = 0, then update all the connected vertices 
		  with the new distances (source vertex distance + edge weights), then apply the same 
		  concept for the new vertices with new distances and so on.
		  
Note :  1. A very important application of Bellman Ford is to check if there is a negative cycle in 
		   the graph. 
		   
		2. Apart from this, Bellman-Ford works better (better than Dijksra’s) for distributed 
		   systems. Unlike Dijksra’s where we need to find minimum value of all vertices, in 
	       Bellman-Ford, edges are considered one by one.

----------------------------------------

Time Complexity : Bellman–Ford runs in O(|V|.|E|) time, where |V| and |E| are the number of vertices 
				  and edges respectively. Time Complexity of Bellman Ford algorithm is relatively 
				  high O(V.E) , in case of densed or complete graph, E might be V^2 , then the time 
				  complexity of bellman ford algorithm will become O(E^3).

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define ep emplace_back

lli nodes,e;

struct Edge
{
	int u,v,weight;
};

Edge E[1000];
int parent[1000];		// this parent[] will be used to find the shortest path route from source to vertex

// This function finds shortest distances from src to all other vertices. The function also 
// detects negative edge weight cycle ( if any )
void BellmanFord(lli source)
{
	vector<lli> distance(1000,INT_MAX);			// Initializing distance of all vertices as INT_MAX initially
	
	distance[source] = 0;			// The distance from the source to itself is, of course, zero
	parent[source] = source;			// parent[source] = null   ( And having a null parent )
	
	// Relaxing all edges, (nodes-1) times because A simple shortest path from source to any other
	// vertex can have atmost ( |nodes| - 1 ) edges 
	for(int i=0;i<nodes-1;i++)			
	{
		for(int j=0;j<e;j++)
		{
			lli src = E[j].u;
			lli dest = E[j].v;
			lli W = E[j].weight;
			if( (distance[src] + W) < distance[dest] )			// Algorithm Step
			{
				distance[dest] = distance[src] + W;
				parent[dest] = src;				// setting the parent of dest as src for printing shortest route
			}
		}
	}
	
	// checking for the negative edge weight cycles. The above step guarantees gives the shortest distances
	// if graph doesn't contain negative weight cycle. So, If we get a shorter path than above, then it means
	// there is a negative edge weight cycle in the graph ( for more clear understanding , see above videos ).
	for(int j=nodes-1;j<nodes;j++)			// iterating only one time for finding any shorter path
	{
		for(int i=0;i<e;i++)
		{
			lli src = E[i].u; 
	        lli dest = E[i].v; 
	        lli W = E[i].weight; 
	        if( distance[dest] > distance[src] + W ) 		// note this is strictly greater than
	        {
	        	cout << "Negative Edge Weight Cycle Detected !\n";
	        	break;
			} 
		}
	}
	
	cout<<"\nSource -> Destination ----> weight\n";
	
	for(int i=0;i<nodes;i++)			    // Printing shortest distances stored in distance[] 
	cout << 0 << " -> " <<i<<" -----> "<<distance[i]<<"\n";
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
 	freopen("input.txt", "rt", stdin);
 	
 	cin>>nodes>>e;
 	
 	for(int i=0;i<e;i++)
 		cin>>E[i].u>>E[i].v>>E[i].weight;
 	
	BellmanFord(0);				// assuming 0 as source vertex
	
} 


/*

input-1 :
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
5 3 -14
4 5 10
5 6 2
6 7 1
8 6 -17
7 8 7

Output-1 :
Negative Edge Weight Cycle Detected !

Source -> Destination ----> weight
0 -> 0 -----> 0
0 -> 1 -----> 4
0 -> 2 -----> 12
0 -> 3 -----> 2
0 -> 4 -----> 11
0 -> 5 -----> 16
0 -> 6 -----> -30
0 -> 7 -----> -29
0 -> 8 -----> -22

--------------------------

Input-2 :
7 9
0 1 4
3 4 9
5 3 -24
4 5 10
5 6 2
6 2 1
1 2 5
2 0 -8
2 5 12

Output-2 :
Negative Edge Weight Cycle Detected !

Source -> Destination ----> weight
0 -> 0 -----> 0
0 -> 1 -----> 4
0 -> 2 -----> 9
0 -> 3 -----> -13
0 -> 4 -----> 1
0 -> 5 -----> 11
0 -> 6 -----> 13


---------------------------------

Another Note : If we want to find the shortest path route from above bellman ford algorithm,
			   Then, we have to iterate over the parent array from vertex to source backward 
			   repeatedly ( like in Union-find Data structure ) because each vertex will have 
			   a parent except source or starting node. ( See video-1 above if you have any
			   doubt ).
			   
			   But this shortest route or path will be useless to print because bellman ford 
			   algorithm takes much more time in finding shortest path than Dijkstra. So, for
			   printing shortest path, Dijkstra is very useful.

*/
