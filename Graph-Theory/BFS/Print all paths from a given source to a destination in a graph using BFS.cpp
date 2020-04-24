/*

    ### Print all paths from a given source to a destination using BFS ###

Given a directed graph, a source vertex ‘src’ and a destination vertex ‘dest’, print 
all paths from given ‘src’ to ‘dest’.

Consider the following directed graph ( below link ). Let the src be 2 and dest 
be 3. There are 3 different paths from 2 to 3.

Image ( Graph ) Link :  https://media.geeksforgeeks.org/wp-content/cdn-uploads/allPaths.png

--------------

Below is BFS based solution.

Algorithm :

Step1 : create a queue which will store path(s) of type vector initialise the queue with 
        first path starting from src

Step2 : 1. Now run a loop till queue is not empty
        2. get the frontmost path from queue
        3. check if the lastnode of this path is destination, if true then print the path
        4. Now, iterate for all the vertices connected ( neighbors ) to the current vertex i.e. lastnode 
           extracted from path. if the vertex is not visited in current path, then
             a) create a new path from earlier path and append this vertex
             b) insert this new path to queue

-------------

Note : We can avoid checking again and again that node has been visited in that path or not. Initialize 
a visited array as false. While traversing in same level , don't mark nodes of that level visited.
Store nodes of a level and when all the nodes of that level are visited then mark all of them visited.

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
 
vector<int> adjList[M];

// function for printing the found path in graph 
void print_path(vector<int>& current_path) 
{ 
    for(int x:current_path)  
        cout << x << "->";     
    cout<<"\n"; 
}

// function to check if current vertex is already present in path
bool isNotVisited(int x,vector<int> &current_path)
{  
    for(int temp : current_path)
    {
        if(temp == x)
            return true;
    }
    return false;
}

void bfs(int source,int dest)
{
    queue < vector<int> > q;        // create a queue which stores the paths 
    vector<int> current_path;       // vector to store the current path 
    current_path.ep(source);
    q.push(current_path);
    while(!q.empty())
    {
        current_path = q.front();
        q.pop();
        
        int last_node = current_path[(int)current_path.size()-1];
        
        // if last vertex is the desired destination then print the path 
        if(last_node == dest)
            print_path(current_path);
        
        // traverse to all the nodes connected to current vertex and push new path to queue
        for(int neighbor : adjList[last_node])
        {
            if(!isNotVisited(neighbor,current_path))
            {
                vector<int> new_path;
                new_path = current_path;
                new_path.ep(neighbor);
                q.push(new_path);
            }
        }
    }
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
    
    int source = 9 , destination = 8;
    
    bfs(source,destination);
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
