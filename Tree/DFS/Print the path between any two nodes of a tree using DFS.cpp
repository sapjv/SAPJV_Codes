/*

    ###  Print the path between any two nodes of a tree using DFS ###

Link :  https://www.geeksforgeeks.org/print-the-path-between-any-two-nodes-of-a-tree-dfs/
    
Given a tree of distinct nodes N with N-1 edges. The task is to find and print 
the path between the two given nodes of the tree using DFS.

Input: N = 10  ,  source = 4 , destination = 8

          1
       /    \
      2      3
    / | \  / | \
   4  5 6  7 8  9

Output: 4 -> 2 -> 1 -> 3 -> 8

Input: N = 3  ,  source = 2 , destination = 3
  
      1
     / \
    2   3
    
Output:  2 -> 1 -> 3

----------------------

Example Image Link :  
https://media.geeksforgeeks.org/wp-content/uploads/20190814115132/Untitled-Diagram-222.png

For example, in the above tree the path between nodes 5 and 3 is 5 -> 2 -> 1 -> 3. And the Path 
between nodes 4 and 8 is 4 -> 2 -> 1 -> 3 -> 8.

----------------------

Approach:

The idea is to run DFS from the source node and push the traversed nodes into a 
stack ( or vector ) till the destination node is traversed. Whenever backtracking occurs pop 
the node from the stack ( or vector ).

*/


#include<bits/stdc++.h>
using namespace std;

#define M 100005
#define ep emplace_back

vector<bool> visited(M);
vector<int> adjList[M];

// printing path from source to destination
void print_path(vector<int> path)
{
    for(int x:path)
        cout<<x<<"->";          // ignore the last -> sign
}

void dfs(int src,int dest,vector<int> path)      // this path vector will store the path from source to destination
{
    path.ep(src);
    
    if(src == dest)
    {
        print_path(path);
        return;
    }
    
    visited[src] = true;
    
    // A flag variable to keep track if backtracking is taking place 
    int flag = 0;           
    for(int x:adjList[src])
    {
        if(!visited[x])             // if the adjacent node is not visited yet
        {
            dfs(x,dest,path);
            flag = 1;
        }
    }
    
    // If backtracking is taking place, then pop_back from path vector
    if(flag == 0)
        path.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","rt",stdin);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].ep(v);
        adjList[v].ep(u);
    }
    
    visited.assign(n+1,false);
        
    int source = 6 , destination = 8;
    
    vector<int> path1;
    dfs(source,destination,path1);
    
}

/* 

Input :  
9 8
1 2
1 3
2 4
2 5
2 6
3 7
3 8
3 9

Output :  6->2->1->3->8
