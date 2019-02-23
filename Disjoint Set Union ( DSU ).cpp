/*
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/
algorithm/teachers-dilemma-3/

*/

#include<bits/stdc++.h>
int parent[100000];
int size[100000];
#define MOD 1000000007
using namespace std;
inline int root(int x)
{
    while(parent[x]!=x)
    x=parent[x];
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
    cout.tie(NULL);
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
    
    long long int result=1;
    for(int i=0;i<n;i++)
    {
        if(parent[i]==i)
        result = ((result%MOD)*size[i]%MOD)%MOD;
    }
    cout<<result<<"\n";
}

