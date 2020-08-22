/*

Problem Link :  http://codeforces.com/contest/580/problem/C

Note : This solution is very useful for operating on internal nodes and leaf nodes separately using dfs. 
       So, try to understand and use this approach whenever you need it.

*/

#include<bits/stdc++.h>
using namespace std;

#define ep emplace_back

int c , ans = 0;
vector<bool> visited(M,false);
vector<int> v(M);
vector<int> adjList[M];
vector<int> current_cnt(M,0);

void dfs(int source)
{
   visited[source] = true;
   if(current_cnt[source]>c)
      return;
  
   // this cnt = 0 will remain zero when we reach to the leaves ( so in any question, if we want to identify 
   // leaves after performing some operations in between internal nodes, then we can use this cnt = 0 method 
   // to reach to the leaves )
   int cnt = 0;
   for(int x:adjList[source])
   {
      if(!visited[x])
      {
         current_cnt[x] = current_cnt[source]+1;
         if(v[x]==0)
            current_cnt[x] = 0;
         dfs(x);
        
         // here we are modifying the cnt variable ( either we can increment cnt or just changing cnt value 
         // from zero to some other value ) because currently we are operating on internal nodes ( not on leaf nodes )
         // if we reach to leaf node, we won't come to this if(!visited[x]) condition as the only node which is 
         // connected with leaf node, has already been visited.
         cnt = 1;          
      }
   }
  
   // this cnt value is still zero, it means we reached to the leaves
   if(cnt == 0)
      ans++;
  
   // it is optional to write return statement here ( there will be no effect because just after processing 
   // all the leaves, this function execution will automatically stop. But if we want to return just after 
   // reaching to a single leaf, then writing this return statement will be useful.
   return;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin>>n>>c;
   
   for(int i=1;i<=n;i++)
      cin>>v[i];
   
   for(int i=0;i<n-1;i++)
   {
      int u,v;
      cin>>u>>v;
      adjList[u].ep(v);
      adjList[v].ep(u);
   }
   
   current_cnt[1] = v[1];
   dfs(1);

   cout<<ans<<"\n";
}
