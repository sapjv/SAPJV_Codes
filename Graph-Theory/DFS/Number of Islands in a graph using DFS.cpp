/*

	###  Number of Islands in a graph using DFS  ###
	
Problem Link :  https://www.spoj.com/problems/UCV2013H/  ( solved with little modifications in below code )

Useful Link : https://www.geeksforgeeks.org/find-number-of-islands/

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

The problem can be easily solved by applying DFS() on each component. In each DFS() call, a component or a sub-graph 
is visited. We will call DFS on the next un-visited component. The number of calls to DFS() gives the number of 
connected components. BFS can also be used.
 
A cell in 2D matrix can be connected to 8 neighbours. So, unlike standard DFS(), where we recursively call for all 
adjacent vertices, here we can recursively call for 8 neighbours only. We keep track of the visited 1s so that they 
are not visited again.

---------------

Time Complexity : O(V + E) where V is number of vertices and E is number of edges. Note that the given solution 
is simply works as DFS for disconnected graph.

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

// A function to check if a given cell (i,j) can be included in DFS 
bool isValid(int i,int j)
{
	// row number is in range AND column number is in range 
	if(i>=0 && i<n && j>=0 && j<m)
		return true;
	return false;
}

// A utility function to do DFS for a 2D boolean matrix. It only considers the 8 neighbours as adjacent vertices 
void dfs(int current_row,int current_col)
{
	visited[current_row][current_col] = true;
	for(int k=0;k<8;k++)
	{
		int new_row = current_row+row[k];
		int new_col = current_col+col[k];
		if(isValid(new_row,new_col) && !visited[new_row][new_col] && (matrix[new_row][new_col]==1))
			dfs(new_row,new_col);			// Recurring for all connected neighbours 
	}
}

// This function prints number of islands (connected components) in a graph. It simply works as  
// DFS for disconnected graph and prints the count of DFS calls. 
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
				// Calling DFS() for every unvisited vertex Whenever we see an univisted vertex, we increment ans (number of islands) also. 
				dfs(i,j);
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
