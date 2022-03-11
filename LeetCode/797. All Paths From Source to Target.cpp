Solution 1 (Recursive DFS - Most efficient approach on this whole page):  Execution Time = 21 ms, Memory Consumed =	10.5 MB

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
  
Solution2 (DFS iterative using stack): 


Approach1: Execution Time = 49 ms, Memory Consumed =	17.4 MB  

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

====================
    
Approach2: Runtime: 49 ms, Memory Usage: 17.8 MB

#define ep emplace_back

class Solution {
public:
    
    // function to check if current vertex is already present in path
    bool isNotVisited(int x,vector<int> &current_path){  
        for(int temp : current_path){
            if(temp == x)
                return true;
        }
        return false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = (int)graph.size()-1;
        
        vector<vector<int>> result;
        stack<vector<int>> st;
        vector<int> currentPath;
        currentPath.ep(src);
        st.push(currentPath);
        
        while(!st.empty()){
            currentPath = st.top();
            st.pop();
            int lastNode = currentPath.back();
            if(lastNode == dest){
                result.ep(currentPath);
            }
            for(int x:graph[lastNode]){
                if(!isNotVisited(x, currentPath)){
                    vector<int> newPath{currentPath};
                    newPath.ep(x);
                    st.push(newPath);
                }
            }
        }

        return result;
    }
};

-----------------------------------------------
  
Solution 3: using BFS (just replace stack with queue in both of the above approaches), BFS solution will be very little bit 
efficient than above both iterative approaches.

#define ep emplace_back

class Solution {
public:
    
    // function to check if current vertex is already present in path
    bool isNotVisited(int x,vector<int> &current_path){  
        for(int temp : current_path){
            if(temp == x)
                return true;
        }
        return false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = (int)graph.size()-1;
        
        vector<vector<int>> result;
        queue<vector<int>> q;
        vector<int> currentPath;
        currentPath.ep(src);
        q.push(currentPath);
        
        while(!q.empty()){
            currentPath = q.front();
            q.pop();
            int lastNode = currentPath.back();
            if(lastNode == dest){
                result.ep(currentPath);
            }
            for(int x:graph[lastNode]){
                if(!isNotVisited(x, currentPath)){
                    vector<int> newPath{currentPath};
                    newPath.ep(x);
                    q.push(newPath);
                }
            }
        }

        return result;
    }
};

