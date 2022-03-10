// Solution-I (Simpler Solution):

int findCenter(vector<vector<int>>& edges) {
    int n = 0;
    for(auto &it:edges){
        n = max(n, max(it[0], it[1]));
    }
    vector<int> degree(n+1, 0);
    for(auto it:edges){
        degree[it[0]]++;
        degree[it[1]]++;
    }
    int ans = 1;
    for(int i=1;i<=n;i++){
        if(degree[i] == n-1){
            ans = i;
        }
    }
    return ans;
}

Time Complexity : O(N)
Space Complexity : O(N)
  
-------------------------
  
/*
Solution-II (Optimized Simpler Approach) : We can notice that the center node has to appear in every edge. This mean the node 
that appears in both edge[0] and edge[1] will be the center node. This is much better that direct implementation. The below 
solution is based on that -
*/

int findCenter(vector<vector<int>>& edges) {
    int u1 = edges[0][0];
    int v1 = edges[0][1];
    int u2 = edges[1][0];
    int v2 = edges[1][1];
    // if first node of edge-0 occurs in edge-1 as well, it's the center one
    if(u1 == u2 || u1 == v2){
        return u1;
    }
    return v1;    // otherwise, the second node of edge-0 will be center node for sure
}

Time Complexity : O(1)
Space Complexity : O(1)

