/*
	
	#### Detect cycle in an undirected graph using BFS ####

We do a BFS traversal of the given graph. For every visited vertex ‘v’, if there is an adjacent ‘u’ such 
that u is already visited and u is not parent of v, then there is a cycle in graph. If we don’t find such
an adjacent for any vertex, we say that there is no cycle. 

--------------

Note : The assumption of this approach is that there are no parallel edges between any two vertices.

--------------

Time Complexity : The program does a simple BFS Traversal of graph and graph is represented using adjacency
				 list. So the time complexity is O(V+E).

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define M 100001
#define ep emplace_back

vector<int> adjList[M];
vector<bool> visited;
int nodes;

bool bfs(int source)
{	
	queue<int> q;			// Creating a queue for BFS 
	
	// Marking the current node as visited and enqueue it to queue
	q.push(source);
	visited[source] = true;

	// We use a parent array to keep track of parent vertex for a vertex so that we do not consider visited parent as cycle.
	// Set parent vertex for every vertex as -1. 
	vector<int> parent(nodes,-1);	
	
	while(!q.empty())
	{
		// Dequeue a vertex from queue
		int current = q.front();
		q.pop();
		
		// Get all adjacent vertices of the dequeued vertex u. If a adjacent has not been visited, then
		// mark it visited and enqueue it. We also mark parent so that parent is not considered for cycle. 
		for(auto i:adjList[current])
		{
			if(!visited[i])
			{
				visited[i] = true;
				q.push(i);
				parent[i] = current;
			}
			else if(i != parent[current])
			return true;
		}
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
 	freopen("input.txt", "rt", stdin);
	
    int edges;
    cin>>nodes>>edges;
    
    for(int i=0;i<edges;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	adjList[u].ep(v);
    	adjList[v].ep(u);
	}
	
	visited.assign(M,false);
	
	int flag = 0;
	for(int i=0;i<nodes;i++)
	{
		if(!visited[i])
		{
			if(bfs(i))
			{
				flag = 1;
				cout<<"Cycle Detected\n";
				break;
			}
		}
	}
	
	if(flag==0)
	cout<<"No Cycle Detected\n";
}    
