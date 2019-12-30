/*

		###  Shortest path in an unweighted graph using BFS ###
		
		
Useful Video :  https://www.youtube.com/watch?v=0XgVhsMOcQM

Given a unweighted graph, a source and a destination, we need to find shortest path from source to destination
in the graph in most optimal way.

One solution is to solve in O(V*E) time using Bellman–Ford. If there are no negative weight cycles, then we can 
solve in O(E + VLogV) time using Dijkstra’s algorithm.

Since the graph is unweighted, we can solve this problem in O(V + E) time. The idea is to use a modified version 
of Breadth-first search in which we keep storing the predecessor of a given vertex while doing the breadth first 
search. This algorithm will work even when negative weight cycles are present in the graph.
 
The time complexity of below code is O(V+E).

*/


#include<bits/stdc++.h>
using namespace std;

#define M 250
#define EDGE_COST 1
#define ep emplace_back

vector<int> adjList[M];
vector<int> Distance;			// distance from source to all other vertices will be stored in the Distance array

// Note that there is no need to use visited array while implementing this code

void bfs(int source)
{
	queue<int> q;
	q.push(source);
	Distance[source] = 0;
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		for(int neighbor : adjList[current])
		{
			if(Distance[neighbor] == -1)
			{
				Distance[neighbor] = Distance[current] + EDGE_COST;
				q.push(neighbor);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);

	int nodes,edges;
	cin>>nodes>>edges;
	
	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	Distance.assign(nodes,-1);
	
	bfs(0);				// assuming source node is node 0
	
	for(int i=0;i<nodes;i++)
		cout<<Distance[i]<<" ";
}


/*

input :
7 6
0 4
1 5
1 3
2 6
2 4
4 5

Output :
0 3 2 4 1 2 3

*/
