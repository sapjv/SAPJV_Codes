// Question :  https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/

// Best tutorial for this, is also of hackerearth notes : https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

// Time Complexity : In Kruskal’s algorithm, most time consuming operation is sorting because the total complexity of the 
// Disjoint-Set operations will be O(ElogV) , which is the overall Time Complexity of the algorithm.

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int N = 100005;
lli parent[N], nodes, edges;

pair<lli,pair<lli,lli> >  p[N];

lli root(lli x)
{
    while(parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void union1(lli x, lli y)
{
    lli p = root(x);
    lli q = root(y);
    parent[p] = parent[q];
}

lli kruskal()
{
	lli minimumCost = 0;
	
	for(int i=0;i<edges;i++)
	{
		lli u = p[i].second.first;
		lli v = p[i].second.second;
		
		lli cost_of_u_v = p[i].first;			// weight of edge u,v
		
		if(root(u)!=root(v))
		{
			minimumCost += cost_of_u_v;
			union1(u,v);
		}
	}
	
	return minimumCost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
	for(int i=0;i<N;i++)
	parent[i] = i;
	
	cin>>nodes>>edges;
	
	for(int i=0;i<edges;i++)
	{
		lli u,v,weight;
		cin>>u>>v>>weight;
		p[i] = make_pair(weight,make_pair(u,v));
	}
	
	sort(p,p+edges);			// Sorting the edges in the ascending order
	
	lli minimum_cost_of_spanning_tree = kruskal();
	
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
