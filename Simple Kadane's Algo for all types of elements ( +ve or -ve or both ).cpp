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
		lli n;
		cin>>n;
		lli a[n];
		for(int i=0;i<n;i++)
		{
		    cin>>a[i];
		}
		
		lli max_so_far=INT_MIN ,max_ending_here=0;
		for(int i=0;i<n;i++)
		{
		    max_ending_here+=a[i];
		    if(max_ending_here>max_so_far)
		    max_so_far = max_ending_here;
		    if(max_ending_here<0)
		    max_ending_here = 0;
		}
		cout<<max_so_far<<"\n";
	}
}
