/*

Task : Given a graph and a source vertex in graph, find shortest paths
	   from source to all vertices in the given graph.

-----------------------------------

Steps used in Dijkstra Algorithm while using Min Priority Queue :

Step 1) Initialize distances of all vertices as infinite ( or by INT_MAX ).

Step 2) Creating an empty min priority_queue min_pq. Every item of min_pq is a pair (weight, vertex). 
		Weight (or distance) is used as first item of pair which is by default used to compare two pairs.

Step 3) Insert source vertex into min_pq and make its distance as 0.

Step 4) While min_pq doesn't become empty :
		    a) Extract minimum distance vertex from min_pq. Let the extracted vertex be u.
		    b) Loop through all adjacent of u and do following for every vertex v.
           	    If there is a shorter path to v through u. If distance[v] > distance[u] + weight(u, v)
                (i) Update distance of v, i.e., do distance[v] = distance[u] + weight(u, v)
                (ii) Insert v into the min_pq (Even if v is already there)
               
Step 5) Print distance array distance[] to print all shortest paths. 

----------------------------------

Note : For sparse graphs, that is, graphs with far fewer than (|V|^2) edges, Dijkstra's algorithm 
	   can be implemented more efficiently by storing the graph in the form of adjacency lists and
	   using a self-balancing binary search tree, binary heap, pairing heap, or Fibonacci heap as 
	   a priority queue to implement extracting minimum efficiently. To perform decrease-key steps
	   in a binary heap efficiently, it is necessary to use an auxiliary data structure that maps
	   each vertex to its position in the heap, and to keep this structure up to date as the priority
	   queue Q changes. With a self-balancing binary search tree or binary heap, the algorithm requires
	   Theta((|E|+|V|)log|V|) time in the worst case (where log denotes the binary logarithm log2); for
	   connected graphs this time bound can be simplified to Theta(|E|log|V|). 
	   
	   The Fibonacci heap improves this to O(|E|+|V|log|V|).
	   
	   When using binary heaps, the average case time complexity is lower than the worst-case.

----------------------------------

Note : For Dijkstra’s algorithm, it is always recommended to use heap (or priority queue) as the required
	   operations (extract minimum and decrease key) match with speciality of heap (or priority queue). 
	   However, the problem is, priority_queue doesn’t support decrease key. To resolve this problem, do
	   not update a key, but insert one more copy of it. So we allow multiple instances of same vertex 
	   in priority queue. This approach doesn’t require decrease key operation and has below important
	   properties.

	   Whenever distance of a vertex is reduced, we add one more instance of vertex in priority_queue. 
	   Even if there are multiple instances, we only consider the instance with minimum distance and 
	   ignore other instances. The time complexity remains O(ELogV)) as there will be at most O(E) 
	   vertices in priority queue

-----------------------------------

Note : Dijkstra Algorithm does not work with negative edge weights. But, Unlike Dijkstra's algorithm, 
	   the Bellman–Ford algorithm can be used on graphs with negative edge weights, as long as the 
	   graph contains no negative cycle reachable from the source vertex s. The presence of such 
	   cycles means there is no shortest path, since the total weight becomes lower each time the 
	   cycle is traversed.

-----------------------------------

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define ep emplace_back

typedef pair<int,int> PII;

int parent[10000];		// this array will store the parent node of each node in shortest path from source to destination
vector<PII> adjList[10000];

int nodes,edges;

// this function will print the shortest path from source to destination
// Question Link :  https://codeforces.com/contest/20/problem/C  ( this question needs to print shortest path b/w source and destination )
void print_path(int j)
{
	if(parent[j] == -1)		// if current node is source ( we know that parent of source node is -1 ), then we'll print it and return from here.
	{
		cout<<j<<" ";
		return;
	}
	print_path(parent[j]);
	cout<<j<<" ";			// printing the nodes in the shortest path from source to destination
}


// Prints shortest paths from source to all other vertices 
void dijkstraShortestPath(int source)		
{
	// Creating a min priority queue to store vertices that are being preprocessed.
	priority_queue<PII,vector<PII>,greater<PII> > min_pq;
	
	vector<int> distance(10000,INT_MAX);			// Create a vector for distances and initialize all distances as infinite (INF) 
	
	min_pq.push(make_pair(0,source));		// Insert source itself in priority queue and initialize its distance as 0. 
	distance[source] = 0;
	
	while(!min_pq.empty())			// Looping till priority queue becomes empty (or all distances are not finalized)
	{
		/*
			The first vertex in pair is the minimum distance vertex, extract it from priority queue. 
        	vertex label is stored in second of pair (it has to be done this way to keep the vertices 
			sorted distance (distance must be first item in pair) 
		*/
		int u = min_pq.top().second;
		min_pq.pop();
		
		for(auto i:adjList[u])			// Geting all adjacents of u.  
		{
			int weight = i.first;			// Geting weight of current adjacent of u
			int v = i.second;				// Getting vertex label of current adjacent of u 
			if( distance[v] > distance[u] + weight )            // If there is shorted path to v through u.
			{
				distance[v] = distance[u] + weight;			                // Updating distance of v 
				min_pq.push(make_pair(distance[v],v));
				parent[v] = u;			// assigning parent of each node in the shortest path
			}
		}
	}
	
	cout<<"Source -> Destination ----> weight\n";
	
	for(int i=0;i<nodes;i++)			    // Printing shortest distances stored in distance[] 
	cout << 0 << " -> " <<i<<" -----> "<<distance[i]<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
 	freopen("input.txt", "rt", stdin);
 	
 	cin>>nodes>>edges;
 	
 	for(int i=0;i<edges;i++)
 	{
 		int u,v,weight;
 		cin>>u>>v>>weight;
 		adjList[u].ep(make_pair(weight,v));	
		adjList[v].ep(make_pair(weight,u));				// for undirected
	}
	
	parent[0] = -1;			// parent of source node is -1
	
	dijkstraShortestPath(0);
	
	print_path(destination);
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
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

Output-1 :
Source -> Destination ----> weight
0 -> 0 -----> 0
0 -> 1 -----> 4
0 -> 2 -----> 12
0 -> 3 -----> 19
0 -> 4 -----> 21
0 -> 5 -----> 11
0 -> 6 -----> 9
0 -> 7 -----> 8
0 -> 8 -----> 14


------------------------------


input-2 : 
6 9
0 1 2
1 2 1
0 2 4
1 3 4
1 4 2
2 4 3
3 5 2
4 5 2
4 3 3

Output-2 :
Source -> Destination ----> weight
0 -> 0 -----> 0
0 -> 1 -----> 2
0 -> 2 -----> 3
0 -> 3 -----> 6
0 -> 4 -----> 4
0 -> 5 -----> 6

--------------------------------------------

Note : We can do Further Optimization in above algorithm by doing this : We can use a flag array to 
	   store what all vertices have been extracted from priority queue. This way we can avoid 
	   updating weights of items that have already been extracted. Check below more optimized code :
	
		void dijkstraShortestPath_More_Optimized(int source)		
		{
			priority_queue<PII,vector<PII>,greater<PII> > min_pq;
			
			vector<int> distance(10000,INT_MAX);	
			
			min_pq.push(make_pair(0,source));	
			distance[source] = 0;
			
			vector<bool> f(nodes, false);			// this is new added line
			
			while(!min_pq.empty())		
			{
				int u = min_pq.top().second;
				min_pq.pop();
				
				f[u] = true;				// new line added here
				
				for(auto i:adjList[u])		
				{
					int weight = i.first;	
					int v = i.second;		
					if( f[v] == false && distance[v] > distance[u] + weight )  				// something added here
					{
						distance[v] = distance[u] + weight;			           
						min_pq.push(make_pair(distance[v],v));
					}
				}
			}
			
			for(int i=0;i<nodes;i++)			    // Printing shortest distances stored in distance[] 
			cout << 0 << " -> " <<i<<" -----> "<<distance[i]<<"\n";
		}
		
------------------------------------------------

*/
