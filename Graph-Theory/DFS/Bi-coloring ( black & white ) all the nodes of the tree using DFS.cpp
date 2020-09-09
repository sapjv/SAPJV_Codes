
// Bicoloring (white & black) all the nodes of the tree using DFS

#include<bits/stdc++.h>
using namespace std;

#define M 200005
#define ep emplace_back

vector<int> color(M);
vector<int> adjList[M];
vector<bool> visited(M);

void dfs(int source,int c)
{
   visited[source] = true;
   color[source] = c;
   for(int x:adjList[source])
   {
      if(!visited[x])
         dfs(x,c^1);          // we'll flip the color of adjacent node of current_source ( also we can write it as : 1-color[source] )
   }
}

int main()
{  
   int n,m;
   cin>>n>>m;
         
   for(int i=1;i<m;i++)
   {
      int u,v;
      cin>>u>>v;
      adjList[u].ep(v);
      adjList[v].ep(u);
   }

   dfs(1,1);         // dfs(source,initial_color)     [ 1 is for black color , 0 is for white color ]
      
   vector<int> black,white;
   for(int i=1;i<=n;i++)
   {
      if(color[i]==1)
         cout<<"Black_node : "<<i<<" ";
      else
         cout<<"White_node : "<<i<<" ";
   }
}

