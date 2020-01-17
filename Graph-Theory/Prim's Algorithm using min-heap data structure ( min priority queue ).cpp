/*

This is the correct and optimised code for Prim's Algorithm

Useful Link : https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/

In Prim’s algorithm, we need a priority queue and below operations on priority queue :

1. ExtractMin : from all those vertices which have not yet been included in MST, we need to 
				get vertex with minimum distance value.
2. DecreaseKey : After extracting vertex we need to update keys of its adjacent vertices, and 
				if new key is smaller, then update that in data structure.
					
The algorithm discussed here can be modified so that decrease key is never required. The idea is, 
not to insert all vertices in priority queue, but only those which are not MST and have been 
visited through a vertex that has included in MST. We keep track of vertices included in MST 
in a separate boolean array inMST[].

1) Initialize distance of all vertices as infinite and parent of every vertex as -1.

2) Create an empty priority_queue pq.  Every item of pq is a pair (weight, vertex). Weight (or 
   distance) is used used as first item  of pair as first item is by default used to compare two pairs.

3) Initialize all vertices as not part of MST yet. We use boolean array inMST[] for this purpose.
   This array is required to make sure that an already considered vertex is not included in pq again. 
   This is where Ptim's implementation differs from Dijkstra. In Dijkstr's algorithm, we didn't need 
   this array as distances always increase. We require this array here because distance value of a 
   processed vertex may decrease if not checked.

4) Insert source vertex into pq and make its distance as 0.

5) While either pq doesn't become empty 
    a) Extract minimum distance vertex from pq. Let the extracted vertex be u.

    b) Include u in MST using inMST[u] = true.

    c) Loop through all adjacent of u and do following for every vertex v.
		   If weight of edge (u,v) is smaller than distance of v and v is not already in MST
           i.e., If inMST[v] = false && distance[v] > weight(u, v)
               (i) Update distance of v, i.e., do  distance[v] = weight(u, v)
               (ii) Insert v into the pq 
               (iv) parent[v] = u
               
6) Print MST edges using parent array.

Time Complexity : The time complexity of the Prim’s Algorithm is O(E Log V) as there will be at 
most O(E) vertices in priority queue and O(LogE) is same as O(LogV). Unlike Dijkstra’s implementation, 
a boolean array inMST[] is mandatory here because the distance values of newly inserted items can be 
less than the distance values of extracted items. So we must not consider extracted items.

 
*/ 
 
#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> PII;

#define ep emplace_back

const int N = 100005;

int nodes,edges;
vector<PII> adjList[N];

lli prim(int start)
{
	priority_queue<PII,vector<PII>,greater<PII> > min_pq;
	
	vector<int> parent(N,-1);		// To store parent array which in turn store MST
	vector<int> dist(N,INT_MAX);		// Creating a vector for distance and initializing all distances as infinite (INF)
	vector<bool> inMST(N,false);		// To keep track of vertices included in MST
	
	dist[start] = 0;
	
	// Insert source itself in priority queue and initialize its distance as 0. 
	min_pq.push(make_pair(0,start));
	
	while(!min_pq.empty())
	{
		// The first vertex in pair is the minimum distance vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it has to be done this way to keep the vertices 
        // sorted distance (distance must be first item in pair) 
		int u = min_pq.top().second;
		min_pq.pop();
		
		if(inMST[u] == true) 		// checking for cycles
			continue ;
		
		inMST[u] = true;		// Include vertex in MST 
		
		for(auto i:adjList[u])
		{
			// Get vertex label and weight of current adjacent of u.
			int v = i.second;
			int weight = i.first;
			
			// If v is not in MST and weight of (u,v) is smaller than current distance of v 
			if(inMST[v] == false && dist[v]>weight)
			{
				dist[v] = weight;			// Updating distance of v 
				min_pq.push(make_pair(dist[v],v));
				parent[v] = u;
			}
		}
	}
	
	lli minimumCost = 0;
	for(int i=1;i<=nodes;i++)
	{
		if(dist[i]!=INT_MAX)
			minimumCost += dist[i];
	}
	
	// Printing edges of MST using parent array 
	cout<<"Edges in MST are : "<<"\n";
    for (int i=1;i<=nodes;i++) 
        cout<<parent[i]<<"--"<<i<<"\n"; 
	
	return minimumCost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
	cin>>nodes>>edges;
	
	for(int i=0;i<edges;i++)
	{
		lli u,v,weight;
		cin>>u>>v>>weight;
		adjList[u].ep(make_pair(weight,v));				// this is necessary
		adjList[v].ep(make_pair(weight,u));				// this is necessary
	}
	
	lli minimum_cost = prim(1);			// Selecting 1 as the starting node
	
	cout << "Minimum Cost = "<< minimum_cost << "\n";
} 


/*

input : 
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

Output :
Edges in MST are :
-1--1
1--2
2--3
1--4
Minimum Cost = 19

*/

