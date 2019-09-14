// Finding number of connected components in the undirected graph

// Question :  https://www.spoj.com/problems/CAM5/


#include<bits/stdc++.h> 
using namespace std;
typedef long long int lli;

#define M 100000
#define MOD 1000000007
#define ep emplace_back
 		
vector<bool> visited;

void dfs(int source,vector<int> adjList[])
{
	visited[source] = true;
	for(auto it = adjList[source].begin();it!=adjList[source].end();it++)
	{
		if(!visited[*it])
		dfs(*it,adjList);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int N;
 		cin>>N;
		 
		vector<int> adjList[N+5];
		
		int e;
 		cin>>e;
 		
 		for(int i=1;i<=e;i++)
 		{
 			int a,b;
 			cin>>a>>b;
 			a++;b++;
 			adjList[a].ep(b);
 			adjList[b].ep(a);
		}
		
		visited.assign(N+5,false);
		
		lli count = 0;
		for(int i=1;i<=N;i++)
		{
			if(visited[i]==false)
			{
				count++;
				dfs(i,adjList);
			}
		}
		
		visited.clear();
		
		cout<<count<<"\n";
	}
}   
 
