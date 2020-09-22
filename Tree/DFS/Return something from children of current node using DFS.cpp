
/*

      ###  Return something from children of current node using DFS ### 

If you really want to return something from bottom nodes to upper nodes i.e., from leaves to root node 
using DFS ( and something you want to get from children of the current node so that you could modify 
them for current node ) , then you have to use this technique : 

for more information, check out my submission for this problem : 
link :  http://codeforces.com/contest/839/submission/93452517

*/

vector<int> sum(M,0);

void dfs(int source)
{
   visited[source] = true;
   for(int x:adjList[source])
   {
      if(!visited[x])
      {
         dfs(x);
         sum[source] += sum[x];	  // here, we are adding all sums in children nodes of the current node ( please note that it should be below to dfs() call )
      }
   }
   
   // here we can do some modifications ( perform some operations ) on sum[source] like this :
   sum[source] *= 5;
}




