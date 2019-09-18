// Question :  https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/

// Best tutorial for this, is also of hackerearth notes : https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

// Time Complexity : The time complexity of the Prim’s Algorithm is O((V+E)logV) because each vertex is inserted in the priority queue only once 
// and insertion in priority queue take logarithmic time.


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<lli,lli> PII;

#define ep emplace_back

const int N = 100005;

bool marked[N];
vector<PII> adj[N];

lli prim(int start)
{
	priority_queue<PII,vector<PII>,greater<PII> > min_pq;
	
	lli minimumCost = 0;
	
	min_pq.push(make_pair(0,start));
	
	while(!min_pq.empty())
	{
		auto p = min_pq.top();				// Select the edge with minimum weight
		min_pq.pop();
		
		start = p.second;
		
		if(marked[start]==true)				// Checking for cycle
		continue;
		
		minimumCost += p.first;
		
		marked[start] = true;
		
		for(int i=0;i<adj[start].size();i++)
		{
			int y = adj[start][i].second;
			if(marked[y]==false)
			min_pq.push(adj[start][i]);
		}
	}
	
	return minimumCost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
 	int nodes,edges;
	cin>>nodes>>edges;
	
	for(int i=0;i<edges;i++)
	{
		lli u,v,weight;
		cin>>u>>v>>weight;
		adj[u].ep(make_pair(weight,v));				// this is necessary
		adj[v].ep(make_pair(weight,u));				// this is necessary
	}
	
	lli minimum_cost_of_spanning_tree = prim(1);			// Selecting 1 as the starting node
	
	cout << minimum_cost_of_spanning_tree << "\n";
	
} 




/*

input : 
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

Output : 19

*/

