#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int V,E;
		cin>>V>>E;
	    vector<int> adj[V];
	    
	    for(int i=0;i<E;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        adj[x].push_back(y);
	        adj[y].push_back(x);
	    }
	    for(int i=0;i<V;i++)
	    {
	        cout<<i;
	        for(int j=0;j<adj[i].size();j++)
	        cout<<"-> "<<adj[i][j];
	        cout<<"\n";
	    }
	}
}
