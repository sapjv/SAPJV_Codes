/*

	### DSU (Disjoint Set Union) operations on 2-D matrix (graph source to destination) ###

Problem Link: https://codeforces.com/contest/1598/problem/A

I have solved this problem using all three BFS/DFS/DSU techniques. Below is the DSU based solution code.

BFS based solution is also good for this problem, here is my BFS solution: https://codeforces.com/contest/1598/submission/155128844

This solution will perform DSU (Disjoint Set Union) operations on 2-D matrix (graph source to destination).
Make sure you understand the solution completely.

DSU based solution link: https://codeforces.com/contest/1598/submission/155170645
*/


#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

string result = "NO";
char matrix[2][105];
bool visited[2][105];

map<PII, PII> parent;
map<PII, int> sizee;

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int i, int j, int n){
    if(i>=0 && i<n && j>=0 && j<n){
        return true;
    }
    return false;
}

bool equals(PII p1, PII p2){
    if(p1.first == p2.first && p1.second == p2.second){
        return true;
    }
    return false;
}

PII root(int i, int j){
    while(!equals(parent[mk(i, j)], mk(i, j))){
        parent[mk(i, j)] = parent[parent[mk(i, j)]];
        i = parent[mk(i, j)].first;
        j = parent[mk(i, j)].second;
    }
    return mk(i, j);
}

void solve(int n){
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=='0'){
                for(int k=0;k<8;k++){
                    int newRow = i + row[k];
                    int newCol = j + col[k];
                    if(isValid(newRow, newCol, n) && matrix[newRow][newCol]=='0'){
                        PII rootA = root(i, j);
                        PII rootB = root(newRow, newCol);
                        if(equals(rootA, rootB)){
                            continue;
                        }
                        if(sizee[rootA]<sizee[rootB]){
                            parent[rootA] = rootB;
                            sizee[rootB] += sizee[rootA];
                        } else {
                            parent[rootB] = rootA;
                            sizee[rootA] += sizee[rootB];
                        }
                    }
                }
            }
        }
    }
    if(equals(root(0, 0), root(1, n-1))){
        result = "YES";
    }
}

int main(){
	
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        result = "NO";
        memset(visited, false, sizeof(visited));

        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
                parent[mk(i, j)] = mk(i, j);
                sizee[mk(i, j)] = 1;
            }
        }

        solve(n);
        cout << result << "\n";
    }
}