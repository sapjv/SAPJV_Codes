/*

	###  Number of Islands in a graph using BFS  ###
	
Problem Link :  https://www.spoj.com/problems/UCV2013H/  ( solved with little modifications in below code )

Useful Link : https://www.geeksforgeeks.org/islands-in-a-graph-using-bfs/

Task : Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. 
For example, the below matrix contains 5 islands.

Input : matrix[][] = {{1, 1, 0, 0, 0},
                	  {0, 1, 0, 0, 1},
                      {1, 0, 0, 1, 1},
                      {0, 0, 0, 0, 0},
                      {1, 0, 1, 0, 1}}

Output : 5

What is an island ? : A group of connected 1s forms an island. 

Note : This is a variation of the standard problem: connected component. A connected component of an undirected 
graph is a subgraph in which every two vertices are connected to each other by a path(s), and which is connected 
to no other vertices outside the subgraph.

This problem can also be solved by applying BFS() on each component. In each BFS() call, a component or a sub-graph 
is visited. We will call BFS on the next un-visited component. The number of calls to BFS() gives the number of 
connected components. BFS can also be used.
 
A cell in 2D matrix can be connected to 8 neighbours. So, unlike standard BFS(), where we process all adjacent 
vertices, we process 8 neighbours only. We keep track of the visited 1s so that they are not visited again.

---------------

Time Complexity : O(V + E) where V is number of vertices and E is number of edges. Note that the given solution 
is simply works as BFS for disconnected graph.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> P;

#define M 10000
#define ep emplace_back

int n,m;
int matrix[M][M];
bool visited[M][M];

// These arrays are used to get row and column numbers of 8 neighbours of a given cell 
// for understanding about 8 neighbours, watch this video ( https://www.youtube.com/watch?v=KiCBXu4P-2Y ) at 04:20 minutes
int row[] = {-1,-1,-1,0,0,1,1,1};
int col[] = {-1,0,1,-1,1,-1,0,1};

// A function to check if a given cell (i,j) can be included in BFS 
bool isValid(int i,int j)
{
	if(i>=0 && i<n && j>=0 && j<m)
		return true;
	return false;
}

void bfs(int r,int c)
{
	// Simple BFS first step, we enqueue source and mark it as visited 
	queue<P> q;
	q.push(make_pair(r,c));
	visited[r][c] = true;
	
	// Next step of BFS. We take out items one by one from queue and enqueue their univisited adjacent
	while(!q.empty())
	{
		int current_r = q.front().first;
		int current_c = q.front().second;
		q.pop();
		
		// Go through all 8 adjacent 
		for(int k=0;k<8;k++)
		{
			int new_row = current_r+row[k];
			int new_col = current_c+col[k];
			if(isValid(new_row,new_col) && !visited[new_row][new_col] && (matrix[new_row][new_col]==1))
			{
				visited[new_row][new_col] = true;
				q.push(make_pair(new_row,new_col));
			}
		}
	}
}

// This function prints number of islands (connected components) in a graph. It simply works as  
// BFS for disconnected graph and prints the count of BFS calls. 
void countIslands()
{
	// Marking all cells as not visited 
	memset(visited,false,sizeof(visited));
	
	int ans = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j] && !visited[i][j])
			{
				// Calling BFS() for every unvisited vertex Whenever we see an univisted vertex, we increment ans (number of islands) also. 
				bfs(i,j);
				ans++;
			}
		}
	}
	
	cout<<"No. of islands in the given graph are : "<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>matrix[i][j];
	}
  
    countIslands(); 
}
