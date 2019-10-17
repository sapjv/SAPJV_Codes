/*

	#### Detect cycle in an undirected graph using Disjoint Set Data Structure ####
	
Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. 

Initially we'll create the individual sets of each nodes. And then for each edge, we'll check 
whether both vertices of that edge have same root or not. If we found same root for both the 
vertices of any edge, then it means there is a cycle. Otherwise, If we don't find any such edge
whose both vertices contains similar root, then there would be no cycle in the graph.

----------------

Note : This method assumes that the graph doesn’t contain any self-loops.
	
----------------
	
Useful Video Links :

1.  https://www.youtube.com/watch?v=n_t0a_8H8VY
2.  https://www.youtube.com/watch?v=mHz-mx-8lJ8&t=11s

----------------

Time Complexity : O(ELogV)		where E is total number of edges, and V is total number of vertices

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define M 100001
#define ep emplace_back

int parent[M];

inline int root(int x)
{
	while(x!=parent[x])
	{
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

inline void Union(int A,int B)
{
	int root_A = root(A);
	int root_B = root(B);
	
	if(root_A == root_B)
	return;
	
	if(root_A<root_B)
		parent[root_A] = root_B;
	else
		parent[root_B] = root_A;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
 	freopen("input.txt", "rt", stdin);
	
    int nodes,edges;
    cin>>nodes>>edges;
    
    for(int i=0;i<nodes;i++)
    	parent[i] = i;
    
    int flag = 0;
    for(int i=0;i<edges;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	int root_u = root(u);
    	int root_v = root(v);
    	if(root_u == root_v)
    		flag = 1;
    	Union(u,v);
	}
	
	if(flag==1)
	cout<<"Cycle Detected\n";
	else
	cout<<"No Cycle Detected\n";
	
    
}    
