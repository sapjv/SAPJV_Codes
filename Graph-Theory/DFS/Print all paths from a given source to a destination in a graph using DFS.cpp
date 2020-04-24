/*
    ### Print all paths from a given source to a destination using DFS ###
    
Link :  https://www.geeksforgeeks.org/find-paths-given-source-destination/

Given a directed graph, a source vertex ‘src’ and a destination vertex ‘dest’, print 
all paths from given ‘src’ to ‘dest’.

Consider the following directed graph ( below link ). Let the src be 2 and dest 
be 3. There are 3 different paths from 2 to 3.

Image ( Graph ) Link :  https://media.geeksforgeeks.org/wp-content/cdn-uploads/allPaths.png

----------------

The idea is to do Depth First Traversal of given directed graph. Start the traversal from 
source. Keep storing the visited vertices in an array/vector say ‘path’. If we reach the 
destination vertex, print contents of path[]. The important thing is to mark current 
vertices in path[] as visited also, so that the traversal doesn’t go in a cycle.

*/

#include<bits/stdc++.h>
using namespace std;

#define M 100005
#define MOD 1000000007
#define ep emplace_back
#define mk make_pair
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> PII;

vector<int> path;
vector<bool> visited(M);
vector<int> adjList[M];

void dfs(int source,int parent,int destination)
{
    visited[source] = true;
    path.ep(source);
    
    if(source == destination)
    {
        for(int x:path)
            cout<<x<<"->";
        cout<<"\n";
    }
    else
    {
        for(int x:adjList[source])
        {
            if(!visited[x])
                dfs(x,source,destination);          // destination is fixed
        }
    }
    
    path.pop_back();
    visited[source] = false;
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
        adjList[u].ep(v);           // directed graph
    }
    
    visited.assign(n+1,false);
    
    int source = 9 , destination = 8;
    
    dfs(source,-1,destination);
}

/*

Input : 
9 13
2 1
6 1
3 2
4 8
3 4
3 6
2 4
2 5
2 6
3 7
3 8
9 3
7 2

Output :
9->3->8
9->3->4->8
9->3->2->4->8
9->3->7->2->4->8

*/
