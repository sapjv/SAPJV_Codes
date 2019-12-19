/*

	###  Subtree of all nodes in a tree using DFS  ###

Task :  Given n nodes of a tree and their connections, print Subtree nodes of every node.

Note : Subtree of a node is defined as a tree which is a child of a node. The name emphasizes 
that everything which is a descendant of a tree node is a tree too, and is a subset of the 
larger tree.

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10005
#define ep emplace_back

int start[M],endd[M];
vector<bool> visited;
vector<int> adjList[M];
vector<int> dfs_order;

void dfs(int a,int &b)
{
	visited[a] = true;
	b++;
	start[a] = b;
	dfs_order.ep(a);
	for(int i:adjList[a])
	{
		if(!visited[i])
			dfs(i,b);
	}
	endd[a] = b;
}

void print(int n)
{
	for(int i=0;i<n;i++)
	{
		if(start[i]!=endd[i])
		{
			cout<<"\nSubtree of node "<<i<<" is : ";
			for(int j=start[i]+1;j<=endd[i];j++)
				cout<<dfs_order[j-1]<<" ";
			cout<<"\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "rt", stdin);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	visited.assign(n+1,false);
	
	int c=0;
	
	dfs(0,c);
		
	print(n);
}

/*

Input :
10 9
0 2
0 3
0 1
1 4
4 7
4 8
1 5
2 6
6 9

Output :

Subtree of node 0 is : 2 6 9 3 1 4 7 8 5

Subtree of node 1 is : 4 7 8 5

Subtree of node 2 is : 6 9

Subtree of node 4 is : 7 8

Subtree of node 6 is : 9

*/
