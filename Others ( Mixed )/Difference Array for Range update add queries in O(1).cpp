// 	Difference Array : https://www.geeksforgeeks.org/constant-time-range-add-operation-array/

// 	Difference Array | Range update add queries in O(1)

//  https://www.youtube.com/watch?v=hDhf04AJIRs

//  Question : https://www.spoj.com/problems/UPDATEIT/    ( Check my solution )

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

// 	freopen("input.txt", "rt", stdin);
 	
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int n,u;
		cin>>n>>u;
		
		int a[n+1] = {0};			// note this is a n+1 sized array 
		
		for(int j=0;j<u;j++)
		{
			int l,r,val;
			cin>>l>>r>>val;
			
			// simply these two operations are required for adding val to a[l] to a[r]
			a[l] += val;		
			a[r+1] -= val;
		}
		
		for(int i=1;i<n;i++)			// prefix sum for range update sum
		a[i] += a[i-1];
		
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			int index;
			cin>>index;
			cout<<a[index]<<"\n";
		}
	}
}      
