/*
		
		###  Count the number of nodes at given level in a tree using BFS  ###
		
Useful Link : 	https://www.geeksforgeeks.org/count-number-nodes-given-level-using-bfs/

Given a tree represented as undirected graph. Count the number of nodes at given level L. It may be 
assumed that vertex 0 is root of the tree and level of the root node is 0.

BFS is a traversing algorithm which start traversing from a selected node (source or starting node) and 
traverse the graph layer wise thus exploring the neighbour nodes (nodes which are directly connected to 
source node). Then, move towards the next-level neighbour nodes. As the name BFS suggests, traverse the 
graph breadth wise as follows:

	1. First move horizontally and visit all the nodes of the current layer.
	2. Move to the next layer.

In this code, while visiting each node, the level of that node is set with an increment in the level of 
its parent node i.e., level[child] = level[parent] + 1. This is how the level of each node is determined. 
The root node lies at level zero in the tree.

Explanation :

      0          Level 0
    /  \ 
   1    2        Level 1
 / | \   \
3  4  5   6      Level 2


Given a tree with 7 nodes and 6 edges in which node 0 lies at 0 level. Level of 1 can be updated 
as : level[1] = level[0] + 1 as 0 is the parent node of 1. Similarly, the level of other nodes can
be updated by adding 1 to the level of their parent.

level[0] = 0.
level[1] = level[0] + 1 = 0 + 1 = 1.
level[2] = level[1] + 1, =  level[2] = 1 + 1 = 2.
level[3] = level[2] + 1, = level[3] = 2 + 1 = 3.
level[4] = level[3] + 1, = level[4] = 3 + 1 = 4.
level[5] = level[4] + 1, = level[5] = 4 + 1 = 5.
level[6] = level[5] + 1, = level[6] = 5 + 1 = 6.

Then, count of number of nodes which are at level L(i.e, L=2) is 4 (node:- 3, 4, 5, 6)

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10005
#define ep emplace_back

int n,m;
vector<bool> visited;
vector<int> adjList[M];

void bfs(int source,int L)
{
	int level[n]={0};
	
	visited[source] = true;
	queue<int> q;
	q.push(source);
	
	
	// first we'll assign the level number of each node using bfs, then below we'll count how many nodes are at level L
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		for(int i:adjList[current])
		{
			if(!visited[i])
			{
				level[i] = level[current]+1;		// Setting the level of each node with an increment in the level of its parent node 
				visited[i] = true;
				q.push(i);
			}
		}
	}
	
	int node_count = 0;
	
	// here we are checking how many nodes are at level L
	for(int i=0;i<n;i++)
	{
		if(level[i]==L)
			node_count++;
	}
	
	cout<<"No. of nodes at level "<<L<<" are : "<<node_count<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "rt", stdin);
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	visited.assign(n,false);
	
	int L = 2;
	bfs(0,L);
}

/*

Input :
17 16
0 1
0 2
0 8
1 3
1 4
1 5
2 6
2 7
8 9
8 11
11 13
9 10
9 12
7 16
5 15
4 14

Output :
No. of nodes at level 2 are : 7

*/
