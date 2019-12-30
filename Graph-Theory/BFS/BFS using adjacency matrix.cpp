#include<bits/stdc++.h>
using namespace std;

int nodes = 6;

int adjMatrix[6][6] = {0};
vector<bool> visited;

void bfs(int source)
{
	queue<int> q;
	visited[source] = true;
	q.push(source);
	while(!q.empty())
	{
		int current = q.front();
		cout<<current<<" ";
		q.pop();
		for(int i=0;i<nodes;i++)		// iterating in each column for current node
		{
			if(adjMatrix[current][i] == 1 && (!visited[i]))
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	int edges;
	cin>>edges;
	
	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;
	}
	
	visited.assign(nodes,false);
	
	bfs(0);
}

/*

input : 
8
0 2
0 4
0 5
1 4
1 5
2 3
2 4
4 5

Output :
0 2 4 5 3 1

*/
