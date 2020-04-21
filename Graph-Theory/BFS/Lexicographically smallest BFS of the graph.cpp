/*
    ###  Lexicographically smallest BFS of the graph starting from 1  ###
    
Problem Link :  https://codeforces.com/problemset/problem/1106/D
    
Given a connected graph with N vertices and M edges. The task is to print the 
lexicographically smallest BFS traversal of the graph starting from 1.

Note: The vertices are numbered from 1 to N.
Examples:

Input-1: N = 5, M = 5 
       Edges: 
       1 4
       3 4
       5 4
       3 2
       1 5 
Output : 1 4 3 2 5 
Start from 1, go to 4, then to 3 and then to 2 and to 5. 

---------------

Input-2: N = 3, M = 2 
       Edges: 
       1 2 
       1 3 
Output : 1 2 3 

Approach: Instead of doing a normal BFS traversal on the graph, we can use a priority 
queue(min heap) instead of a simple queue. When a node is visited add its adjacent 
nodes into the priority queue. Every time, we visit a new node, it will be the one 
with the smallest index in the priority queue. Print the nodes when every time we 
visit them starting from 1.

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

vector<bool> visited(M);
vector<int> adjList[M];

void bfs(int source)
{
    priority_queue<int,vector<int>,greater<int> > min_pq;
    min_pq.push(1);
    visited[source] = true;
    while(!min_pq.empty())
    {
        int current = min_pq.top();
        min_pq.pop();
        cout<<current<<" ";
        for(int x:adjList[current])
        {
            if(!visited[x])
            {   
                visited[x] = true;
                min_pq.push(x);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","rt",stdin);

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
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            bfs(i);
    }
}
