vector<bool> visited(105, false);
vector<int> adjList[105];

void dfs(int src, int dest, vector<int> &path, int &flag){
    if(flag == 0){      // already found the path between source and destination, no need to insert anymore nodes in the path
        path.ep(src);
    }
    if(src == dest){
        flag = 1;       // done with the path, now need to return, and no more node push required
        return;
    }
    visited[src] = true;
    for(int x: adjList[src]){
        if(!visited[x]){
            dfs(x, dest, path, flag);
        }
    }
    if(flag == 0){      // if the path is already found, don't pop_back anymore
        path.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt", "r", stdin);

    int n;
    cin>>n;

    for(int i=1;i<=n-1;i++){
        int u, v;
        cin>>u>>v;
        adjList[u].ep(v);
        adjList[v].ep(u);
    }

    int flag = 0;
    
    int src, dest;
    cin>>src>>dest;
    
    vector<int> path;
    dfs(src, dest, path, flag);
    
    for(int x: path){
        cout << x << " ";
    }
}

/*

Input: 

12
1 3
1 5
2 5
3 4
3 7
1 8
5 6
6 9
6 10
9 11
9 12
7 12    // src = 7, dest = 12

Output:
Path: 7 3 1 5 6 9 12 

*/
