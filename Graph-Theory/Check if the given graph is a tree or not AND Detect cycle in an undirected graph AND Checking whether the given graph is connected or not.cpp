// Detect cycle in an undirected graph 
// Checking whether the given graph is connected or not

// Question : https://www.spoj.com/problems/PT07Y/			( Question : Check if the given graph is a tree or not ) 

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define M 10001
#define MOD 1000000007
#define ep emplace_back

vector<int> adjList[M];
vector<bool> visited;

int cycle = 0;

void is_cycle(int source,int parent)			// Detect cycle in an undirected graph s
{
	visited[source] = true;
	for(int it:adjList[source])
	{
		if(!visited[it])
			is_cycle(it,source);
		else if(it!=parent)
			cycle = 1;
	}
}

bool is_connected(int n)			// Checking whether the given graph is connected or not
{
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==false)
		return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

 	freopen("input.txt", "rt", stdin);
 	
	visited.assign(M,false);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	is_cycle(1,-1);
	
	if(is_connected(n))
	{
		if(cycle==0)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	else
	cout<<"NO\n";
}      
