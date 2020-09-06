// This below solution is valid for both directed and undirected tree. 

// Note : A single node will have 1 as its subtree size ( because it will also be included in the subtree of itself )

#include<bits/stdc++.h>
using namespace std;
   
set<int> adjList[M];            // we can either use set or vector, both are correct
vector<int> subtree_size(M,0);       // it will store subtree sizes of all the nodes
vector<bool> visited(M,false);
   
void dfs(int source)
{
   visited[source] = true;
   cout << source <<" ";            // elements in the dfs traversal
   subtree_size[source] = 1;           // setting the subtree size of current node as 1 initially ( this is for getting the subtree size of current node )
   for(int x:adjList[source])
   {
      if(!visited[x])
      {
         dfs(x);
         
         // incrementing the subtree size of the current node by adding all of its children's subtree sizes
         subtree_size[source] += subtree_size[x];   
      }
   }
}


int main()
{  
   int n;
   cin>>n;
   
   // you can avoid this input format ( this input format is taken from this problem :  http://codeforces.com/problemset/problem/1006/E )
   for(int i=2;i<=n;i++)
   {
      int p;
      cin>>p;
      adjList[p].insert(i);
   }
   
   dfs(1);      // 1 is the root node
   
   for(int i=1;i<=n;i++)
      cout<<subtree_size[i]<<" ";
}

