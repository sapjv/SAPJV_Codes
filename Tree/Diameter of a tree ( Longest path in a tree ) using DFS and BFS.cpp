/*
			
			###  Diameter of a tree ( Longest path in a tree ) using DFS  ###
		
Question Link :  https://www.spoj.com/problems/PT07Z/  ( check my solution )

Useful Link :  https://www.quora.com/How-does-following-algorithm-for-finding-longest-path-in-tree-work
		
Definition : The Diameter of a tree ( Longest path in a tree ) is the length of the longest path (from one node to 
	     another) in the tree. The length of a path is the number of edges we traverse from source to destination.
				OR
	     The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between 
             two leaves in the tree.
			 
			 
Solution :  We'll discuss a DFS based solution. As we know that the longest path will always occur between two leaf 
	    nodes. So, We start DFS from any random node and then find which node is farthest from it using DFS. Let 
	    the node farthest be X. It is clear that X will always be a leaf node and a corner of DFS. Now if we start 
	    DFS from X and check the farthest node from it, we will get the diameter of the tree.	
			

Algorithm :  There is a standard algorithm for finding longest path in undirected trees using two depth-first searches:
		 Step 1 :  Start DFS from a random vertex v and find the farthest vertex from it; say it is v'.
		 Step 2 :  Now start a DFS from v' to find the vertex farthest from it. This path is the longest path in the graph.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define M 10001
#define ep emplace_back

vector<int> adjList[M];
vector<bool> visited;

int x;			// it will track farthest node. 

// Sets maxCount as maximum distance from node. 
void dfs(int source,int count,int &maxCount)
{
	visited[source] = true;
	count++;
	for(int i:adjList[source])
	{
		if(!visited[i])
		{
			if(count>=maxCount)
			{
				maxCount = count;
				x = i;
			}
			dfs(i,count,maxCount);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].ep(v);
		adjList[v].ep(u);
	}
	
	int maxCount = INT_MIN;			// maxCount will have diameter of tree 
	
	int count = 0;
	visited.assign(n+1,false);			// Marking all the vertices as not visited 
	
	// Incrementing count by 1 for visited node
	dfs(1,count+1,maxCount);			// DFS from a random node and then see farthest node x from it
	
	visited.assign(n+1,false);			// Again Marking all the vertices as not visited for 2nd-DFS
	
	// Incrementing count by 1 for visited node 
	dfs(x,count+1,maxCount);		// DFS from x and check the farthest node from it using DFS
	
	int ans = maxCount-1;
	cout<<ans<<"\n";
}


//---------------------------------

// Solution 2 : using similar approach, but in different way :
// problem link :  http://codeforces.com/problemset/problem/690/C2

#include<bits/stdc++.h>
using namespace std;

#define M 100005
#define ep emplace_back

int leaf;
int ans = INT_MIN;
vector<bool> visited(M);
vector<int> adjList[M];

void dfs(int source,int &level)
{
   visited[source] = true;
   for(int x:adjList[source])
   {
      if(!visited[x])
      {
         level++;
         dfs(x,level);
      }
   }
   if(ans<level)
   {
      ans = max(ans,level);
      leaf = source;
   }
   level--;
}

int main()
{  
   int n,m;
   cin>>n>>m;
   
   for(int i=1;i<=m;i++)
   {
      int u,v;
      cin>>u>>v;
      adjList[u].ep(v);
      adjList[v].ep(u);
   }
   
   int level = 0;
   dfs(1,level);        // first we'll assign the level of each node and then we'll find which node has highest level ( we'll call it as leaf )
   
   visited.assign(M,false);
   
   level = 0;
   dfs(leaf,level);        // then we'll again do dfs from the leaf and we'll get the highest level from leaf and that we'll be the diameter
   
   cout<<ans<<"\n";
}
 
//---------------------------------
// Solution 3 : Another simple approach using simple DFS
// problem link and my submission :   http://codeforces.com/contest/120/submission/93377504

int leaf;
int height = 0;
vector<bool> visited(M);
vector<int> adjList[M];

void dfs(int source,int level)
{
   visited[source] = true;
   for(int x:adjList[source])
   {
      if(!visited[x])
      {
         dfs(x,level+1);
         if(level+1>height)
         {
            height = level+1;
            leaf = x;
         }
      }
   }
}

int main()
{
      int n,m;
      cin>>n>>m;
      
      for(int i=0;i<m-1;i++)
      {
         int u,v;
         cin>>u>>v;
         adjList[u].ep(v);
         adjList[v].ep(u);
      }
      
      visited.assign(M,false);
      dfs(1,0);
      
      visited.assign(M,false);
      dfs(leaf,0);
	
      cout<<"diameter = "<<height;
}


//----------------------------------------

// 3rd approach : using BFS ( we can solve this same problem using BFS too )
// problem link :  http://codeforces.com/problemset/problem/690/C2 ( same problem )

// Solution :

#include<bits/stdc++.h>
using namespace std;

#define M 100005
#define ep emplace_back

int leaf;
int ans = INT_MIN;
int level[M] = {0};
vector<bool> visited(M);
vector<int> adjList[M];

void bfs(int source)
{
   queue<int> q;
   q.push(source);
   level[source] = 0;
   visited[source] = true;
   while(!q.empty())
   {
      int current = q.front();
      q.pop();
      for(int x:adjList[current])
      {
         if(!visited[x])
         {
            visited[x] = true;
            level[x] = level[current]+1;
            if(level[x]>ans)
            {
               ans = level[x];
               leaf = x;
            }
            q.push(x);
         }
      }
   }
}

int main()
{
   int n,m;
   cin>>n>>m;
   
   for(int i=1;i<=m;i++)
   {
      int u,v;
      cin>>u>>v;
      adjList[u].ep(v);
      adjList[v].ep(u);
   }
   
   bfs(1);          // first we'll find the level of each node and store the maximum level node as leaf
   
   memset(level,0,sizeof(level));
   visited.assign(M,false);
   
   bfs(leaf);          // then we'll again start bfs from the leaf node and find the maximum level node from leaf ( that we'll be our answer )
   
   cout<<ans<<"\n";
}


