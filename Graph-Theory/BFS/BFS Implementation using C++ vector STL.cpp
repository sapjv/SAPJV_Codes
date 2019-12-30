/*
    A STL based simple implementation of BFS using queue and vector in STL. 

    In BFS, we start with a node.
    1) Create a queue and enqueue source into it. 
       Mark source as visited.
    2) While queue is not empty, do following
        a) Dequeue a vertex from queue. Let this be current.
        b) Print current
        c) Enqueue all not yet visited adjacent
           of current and mark them visited.
    
    Note that there can be multple BFSs possible for a graph (even from a particular vertex).

*/

// A Quick implementation of BFS using vectors and queue 

#include <bits/stdc++.h> 
using namespace std; 
vector<bool> visited; 
vector<vector<int> > adjList;           // The adjacency list is represented using vectors of vector.

void bfs(int source) 
{ 
	queue<int> q; 

	q.push(source); 
	visited[source] = true; 

	while (!q.empty()) 
	{ 
		int current = q.front(); 
		q.pop(); 

		cout << current << " "; 

		// Enqueue all adjacent of current node and mark them visited 
		for (auto i = adjList[current].begin(); i != adjList[current].end(); i++) 
		{ 
			if (!visited[*i]) 
			{ 
				q.push(*i); 
				visited[*i] = true; 
			} 
		} 
	} 
} 

int main() 
{ 
	int n, e;               // n = number of vertices , e = number of edges
	cin >> n >> e; 

	visited.assign(n, false);                  
	adjList.assign(n, vector<int>());               // creating adjacency list

	int a, b;               // both ends of an edge
	for (int i = 0; i < e; i++) 
	{ 
		cin >> a >> b; 
		adjList[a].push_back(b);                      // Adding the edge
	    // adjList[b].push_back(a);                  // for undirected graph , we'll add this line 
	} 

	for (int i = 0; i < n; i++) 
	{ 
		if (!visited[i]) 
			bfs(i); 
	} 

	return 0; 
} 



/*

Input:
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7

Output:
0 1 2 3 4 5 6 7

*/



