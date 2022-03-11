Solution 1 (Recursive DFS):  Execution Time = 21 ms, Memory Consumed =	10.5 MB

#define ep emplace_back
vector<bool> visited(20, false);

class Solution {
public:
    void dfs(int s, int d, vector<int> &path, vector<vector<int>> &result, vector<vector<int>>& graph){
        visited[s] = true;
        path.ep(s);
        if(s == d){
            result.ep(path);
        }
        for(int x:graph[s]){
            if(!visited[x]){
                dfs(x, d, path, result, graph);
            }
        }
        path.pop_back();
        visited[s] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int len = (int)graph.size();
        vector<int> path;
        vector<vector<int>> result;
        dfs(0, len-1, path, result, graph);
        return result;
    }
};

----------------
  
Solution2 (DFS iterative using stack): Execution Time = 49 ms, Memory Consumed =	17.4 MB  

// Note that this below is not as efficient as above one.

#define ep emplace_back

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = (int)graph.size()-1;
        
        vector<vector<int>> result;
        stack<vector<int>> st;
        
        st.push({src});
        while(!st.empty()){
            vector<int> currentVector{st.top()};
            st.pop();
            int lastNode = currentVector.back();
            for(int x:graph[lastNode]){
                vector<int> newCurrentVector(currentVector);
                if(x==dest){
                    newCurrentVector.ep(dest);
                    result.ep(newCurrentVector);
                } else {
                    newCurrentVector.ep(x);
                    st.push(newCurrentVector);
                }
            }
        }

        return result;
    }
};

-----------------------------------------------
  
Solution 3: using BFS



