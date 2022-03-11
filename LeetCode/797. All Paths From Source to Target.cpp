This below explanation is not fully related with below provided solution, i have copied this from below link just for my better understanding of algorithm:

(https://leetcode.com/problems/all-paths-from-source-to-target/discuss/1599683/C%2B%2BPython-Simple-Solution-w-Explanation-or-BFS-and-DFS-Traversals) 


Solution - I (BFS)

We can start from the starting node 0 and traverse every possible next node from the current node. Whenever we reach the last 
node n-1, we will add the path till now into the final answer. This process can be implemented using a BFS traversal as -

1. Initialize a queue of path of nodes with the node 0 inserted into it initially denoting the starting node in our traversal path from 0 to n-1
2. Pop an element path from the queue
3. Explore every child node of last node in the path. That is, we try every possible edge in graph from node at the end of current path. Each 
   edge added to end of path gives us another path which will be added to queue for further exploration
4. If the last node in path is n-1, we know that this is a valid source to target path in the graph. So, we add it to final list of paths
5. We repeat this process until the queue is not empty, that is, until there are paths remaining to be explored.
    
    
Time Complexity : O(N*2^N), where N is the number of nodes in the graph. Every node except the start and end node of graph can either 
be part of a path or not be part of a path. For a path consisting of k (3 <= k <= n) nodes, we have k-2 intermediate nodes and we can 
choose from n-2 available nodes. So, the total number of paths are Σ (n-2)C(k-2) for all 3 <= k <= n, which comes out to be O(2^(N-2)) = O(2N). 
 Each path requires O(N) to be computed. Thus resulting time complexity becomes O(N*2N).
 
Space Complexity : O(N*2^N), as seen in analysis above, there can be O(2^(N-2)) paths and each path can have a maximum of N nodes in 
it. The BFS will store all these paths till it reaches the final node which leads to time complexity of O(2^N-2 * (N-1)) = O(N*2^N)
 
 ===================================
 
 Solution - II (DFS)

We can also solve this problem using DFS traversal. This traversal should also be more efficient in terms of space usage as compared 
to BFS traversal since we are only required to keep a single path in memory at a given time. Note that we dont need to maintain a 
data structure such as seen to keep track of visited nodes since this is a DAG and thus no recursive dfs call will end up visiting 
same node twice.

The process of finding all paths using DFS can be implemented as -

1. Begin DFS traversal from the node 0
2. At each step of DFS, add the current node i to the path.
3. If the current node i in dfs call is n-1, we know that this is a valid source to target path in the graph. So, we add it to final list of paths.
4. Otherwise, we explore further path by trying each possible next nodes, that is, we recursively call DFS for every child node of i in the graph.
5. The above process continues till every possible path is tried out by dfs.
 
Time Complexity : O(N*2^N), same as above
Space Complexity : O(N), required by max recursive stack depth and for storing path. Generally output space is not considered towards 
overall space complexity.


 #############################################################################################################################
------------------------------------------------------------------------------------------------------------------------------
 #############################################################################################################################

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

