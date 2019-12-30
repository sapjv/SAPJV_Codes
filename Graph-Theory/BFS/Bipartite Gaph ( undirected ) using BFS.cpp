#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 2005
#define ep emplace_back

int nodes;
int color[M];			// here M is equal to total number of nodes
vector<int> adjList[M];

bool isBipartite(int source)
{
	color[source] = 1;
	queue<int> q;
	q.push(source);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int j:adjList[u])
		{
			if(color[j] == -1)
			{
				color[j] = color[u] ^ 1;   // we'll flip the color of adjacent node of u ( also we can write it as : 1-color[u] )
				q.push(j);
			}
			else if(color[j] == color[u])
				return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	freopen("input.txt","rt",stdin);
	
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cout<<"Scenario #"<<k<<":\n";
		
		int m;
		cin>>nodes>>m;
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			adjList[u].ep(v);
			adjList[v].ep(u);
		}
		
		for(int i=1;i<=nodes;i++)
		color[i] = -1;
	
		int flag = 1;
		for(int i=1;i<=nodes;i++)
		{
			if(color[i] == -1)
			{
				if(!isBipartite(i))
				{
					flag = 0;
					break;
				}
			}
		}
		
		if(flag == 1)
		cout<<"No suspicious bugs found!\n";
		else
		cout<<"Suspicious bugs found!\n";
		
		for(int i=1;i<=nodes;i++)
			adjList[i].clear();
		
	}
}
