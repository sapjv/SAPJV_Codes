// print the level of each node in the tree using DFS

#include<bits/stdc++.h>
using namespace std;

#define M 200005
#define ep emplace_back

vector<int> dist(M,0);
vector<int> adjList[M];
vector<bool> visited(M);

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
   dist[source] = level--;
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

  int level = 0;      // level of the root is 0 (zero)
  dfs(1,level);       // 1 is the root of the tree

  for(int i=1;i<=n;i++)
      cout<<"dist["<<i<<"] = "<<dist[i]<<"\n";
}
