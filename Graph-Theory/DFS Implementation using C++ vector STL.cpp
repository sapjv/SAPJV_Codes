// Must visit and make some notes : https://www.techiedelight.com/depth-first-search/
// A Quick implementation of DFS using vectors and queue 

#include <bits/stdc++.h> 
using namespace std; 
vector<bool> visited; 
vector<vector<int> > adjList;           // The adjacency list is represented using vectors of vector.

void dfs(int source) 
{ 
	stack<int> st; 
    st.push(source);        // Push the current source node. 
  
    while (!st.empty()) 
    { 
        int current = st.top();         // Pop a vertex from stack and print it 
        st.pop(); 
  
        // Stack may contain same vertex twice. So we need to print the popped item only if it is not visited. 
        if (!visited[current]) 
        { 
            cout << current << " "; 
            visited[current] = true; 
        } 
  
        // Get all adjacent vertices of the popped vertex s , If a adjacent has not been visited, then push it to the stack. 
        for (auto i = adjList[current].begin(); i != adjList[current].end(); ++i) 
        {
            if (!visited[*i]) 
                st.push(*i); 
        }
    } 
} 

int main() 
{ 
	int n, e;               // n = number of vertices , e = number of edges
	cin >> n >> e; 

	visited.assign(n, false);                  
	adjList.assign(n, vector<int>());               // creating adjacency list

	int a, b;               // both ends of an edge
	for (int i = 0; i < e; i++) 
	{ 
		cin >> a >> b; 
		adjList[a].push_back(b);                      // Adding the edge
	    // adjList[b].push_back(a);                  // for undirected graph , we'll add this line 
	} 

	for (int i = 0; i < n; i++) { 
        if (!visited[i]) 
            dfs(i); 
    } 

	return 0; 
} 



/*

Input 1:
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7

Output 1:
0 4 6 7 3 2 5 1

Input 2: 
5 5
1 0 
0 2 
2 1 
0 3
1 4

Output 2:
0 3 2 1 4

Input 3:
13 11
1 2
1 7
1 8
2 3
2 6
3 4
3 5
8 9
8 12
9 10
9 11
		
Output 3:
0 1 8 12 9 11 10 7 2 6 3 5 4

*/

