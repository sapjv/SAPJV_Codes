
#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int size[100000];

inline int root(int x)
{
    while(parent[x]!=x)
    {
	parent[x] = parent[parent[x]];		// Path Compression
	x = parent[x];
    }
    return x;
}

void Union(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    
    if(root_A==root_B)
    return;
    
    if(root_A<root_B)
    {
        parent[root_A]=root_B;
        size[root_B]+=size[root_A];
    }
    else
    {
        parent[root_B]=root_A;
        size[root_A]+=size[root_B];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
    
	for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        Union(x-1,y-1);
    }
    
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
	int x,y;
	cin>>x>>y;

	int root_x = root(x-1);
	int root_y = root(y-1);

	if(root_x == root_y)
	cout<<"Yes\n";
	else
	cout<<"No\n";
    } 
}

