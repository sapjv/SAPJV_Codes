#include <bits/stdc++.h> 
using namespace std; 

vector<bool> visited; 
vector<int> adjList[10000];           // Adjacency list 

void dfs(int source) 
{ 
	visited[source]=true;
	cout<<source<<" ";
	
	for(auto it=adjList[source].begin();it!=adjList[source].end();it++)
	{
		if(!visited[*it])
		dfs(*it);				// recursive call
	}
} 

int main() 
{ 
	int n, e;               // n = number of vertices , e = number of edges
	cin >> n >> e; 

	visited.assign(n, false);               // initially all nodes are not visited   

	int a, b;               // both ends of an edge
	for (int i = 0; i < e; i++) 
	{ 
		cin >> a >> b; 
		adjList[a].push_back(b);                      // Adding the edge
	    adjList[b].push_back(a);                  // for undirected graph , we'll add this line 
	} 

	for (int i = 0; i < n; i++) 
	{ 
        if (!visited[i]) 
            dfs(i); 
    } 

	return 0; 
} 



/*

Input 1:
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

Output 1:
0 1 5 2 6 7 3 4

Input 2: 
5 5
1 0 
0 2 
2 1 
0 3
1 4

Output 2:
0 1 2 4 3

Input 3:
13 11
1 2
1 7
1 8
2 3
2 6
3 4
3 5
8 9
8 12
9 10
9 11
		
Output 3:
0 1 2 3 4 5 6 7 8 9 10 11 12

*/

