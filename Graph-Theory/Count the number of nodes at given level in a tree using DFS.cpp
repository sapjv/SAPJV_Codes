/*
		
		###  Count the number of nodes at given level in a tree using DFS  ###
		
Useful Link : https://www.geeksforgeeks.org/count-the-number-of-nodes-at-a-given-level-in-a-tree-using-dfs/
		
Approach: The idea is to traverse the graph in a DFS manner. Take two variables, node_count and 
		  curr_level. Whenever the curr_level = L increment the value of the node_count.

Below is the implementation of the above approach : 

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10005
#define ep emplace_back

int n,m;
vector<bool> visited;
vector<int> adjList[M];

int node_count = 0;

void dfs(int source,int &curr_level,int L)
{
	visited[source] = true;
	
	// If current level is equal to the given level, increment the no. of nodes 
	if(L==curr_level)
		node_count++;
	
	else if(L<curr_level)
		return;
	
	else
	{
		for(int i:adjList[source])
		{
			if(!visited[i])
			{
				curr_level++;
				dfs(i,curr_level,L);
			}
		}
	}
	
	curr_level--;
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
	
	int level = 2;
	
	int current_level = 0;
	
	dfs(0,current_level,level);
	
	cout<<"No. of nodes at level "<<level<<" are : "<<node_count<<"\n";
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
