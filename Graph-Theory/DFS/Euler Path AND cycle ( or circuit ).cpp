/*

		###  Detect Eulerian path or circle or circuit in an undirected graph  ###

Eulerian Path :  Eulerian Path is a path in graph that visits every edge exactly once.

Eulerian Circuit :  Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

Question :  How to find whether a given graph is Eulerian or not ?
Answer :  The problem is same as following question. “Is it possible to draw a given graph without 
lifting pencil from the paper and without tracing any of the edges more than once”.

A graph is called Eulerian if it has an Eulerian Cycle and called Semi-Eulerian if it has an Eulerian 
Path. The problem seems similar to Hamiltonian Path which is NP complete problem for a general graph. 
Fortunately, we can find whether a given graph has a Eulerian Path or not in polynomial time. In fact, 
we can find it in O(V+E) time.

Following are some interesting properties of undirected graphs with an Eulerian path and cycle. We can 
use these properties to find whether a graph is Eulerian or not :

(A) Eulerian Cycle :  An undirected graph has Eulerian cycle if following two conditions are true.
	a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree 
	   because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
	b) All vertices have even degree.

(B) Eulerian Path :  An undirected graph has Eulerian Path if following two conditions are true.
	a) Same as condition (a) for Eulerian Cycle
	b) If two vertices have odd degree and all other vertices have even degree. Note that only one 
	   vertex with odd degree is not possible in an undirected graph (sum of all degrees is always 
	   even in an undirected graph)
	   
Must check these three images of examples :  
1.  https://media.geeksforgeeks.org/wp-content/cdn-uploads/Euler1.png
2.  https://media.geeksforgeeks.org/wp-content/cdn-uploads/Euler2.png
3.  https://media.geeksforgeeks.org/wp-content/cdn-uploads/Euler3.png

Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

Question :  How does this work ?
Answer :  In Eulerian path, each time we visit a vertex v, we walk through two unvisited edges with 
	  one end point as v. Therefore, all middle vertices in Eulerian Path must have even degree. For 
	  Eulerian Cycle, any vertex can be middle vertex, therefore all vertices must have even degree.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10005
#define ep emplace_back

vector<int> adjList[M];
vector<bool> visited;

int n,m;

void dfs(int source)
{
	visited[source] = true;
	for(int i:adjList[source])
	{
		if(!visited[i])
			dfs(i);
	}
}

bool isConnected()
{
	visited.assign(n,false);
	
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		if(adjList[i].size() != 0)
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 0)
		return true;
	
	dfs(0);
	
	for(int j=0;j<n;j++)
	{
		if(visited[j] == false && adjList[j].size()>0)
			return false;
	}
	
	return true;
}

int isEulerian()
{
	if(isConnected() == false)
		return 0;
	
	int odd_count = 0;
	for(int i=0;i<n;i++)
	{
		if(adjList[i].size()&1)
			odd_count++;
	}
	
	if(odd_count>2)
	return 0;
	
	if(odd_count == 2)
		return 1;
	else 
		return 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);

	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	int ans = isEulerian();
	
	if(ans == 0)
		cout<<"Graph is not Eulerian\n"; 
    	else if(ans == 1) 
        	cout<<"Graph has a Euler Path (Semi-Eulerian) \n"; 
    	else
        	cout<<"Graph has a Euler Cycle or Circuit (Eulerian)\n"; 
}


/*

Input : 
5 5
1 0
0 2
2 1
0 3
3 4

Output :
Graph has a Euler Path (Semi-Eulerian)

-------------

Input : 
5 6
1 0
0 2
2 1
0 3
3 4
4 0

Output :
Graph has a Euler Cycle or Circuit (Eulerian)

-------------

Input : 
5 6
1 0
0 2
2 1
0 3
3 4
1 3

Output :
Graph is not Eulerian

-------------

Input : 
3 3
0 1
1 2
2 0

Output :
Graph has a Euler Cycle or Circuit (Eulerian)

-------------

Input : 
3 0

Output :
Graph has a Euler Cycle or Circuit (Eulerian)

*/
