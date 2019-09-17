// Problem : https://www.spoj.com/problems/CONGRAPH/

#include<bits/stdc++.h> 
using namespace std;
typedef long long int lli;
 
#define M 800000
#define MOD 1000000007
#define ep emplace_back

vector<int> adjList[M+1];
vector<bool> visited;

void dfs(int source)
{
	visited[source]=true;
	for(int i : adjList[source])
	{
		if(!visited[i])
		dfs(i);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
 	int n,m;
 	cin>>n>>m;
 	
 	for(int i=0;i<m;i++)
 	{
 		int a,b;
 		cin>>a>>b;
 		adjList[a].ep(b);
 		adjList[b].ep(a);
	}
	
	visited.assign(M+1,false);
	
 	int connected_components = 0;
 	for(int i=0;i<n;i++)
 	{
 		if(!visited[i])
 		{
 			connected_components++;
 			dfs(i);
		}
	}
	
	int result = connected_components-1;
	cout<<result<<"\n";
}   
