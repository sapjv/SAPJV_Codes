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
		int negative=0,positive=0;
		for(int i=0;i<n;i++)
		{
		    cin>>a[i];
		    if(a[i]<0)
		    negative=1;
		    if(a[i]>0)
		    positive=1;
		}
		
		// if all array elements are positive
		if(negative==0 && positive==1)
		{
		    lli sum=0;
		    for(int i=0;i<n;i++)
		    sum+=a[i];
		    cout<<sum<<"\n";
		}
		
		// if all array elements are negative
		else if(negative==1 && positive==0)
		{
		    sort(a,a+n);
		    cout<<a[n-1]<<"\n";
		}
		
		// if all array elements are both positive and negative
		else
		{
    		lli max_so_far=0,max_ending_here=0;
    		for(int i=0;i<n;i++)
    		{
    		    max_ending_here+=a[i];
    		    if(max_ending_here<0)
    		    max_ending_here = 0;
    		    if(max_so_far<max_ending_here)
    		    max_so_far=max_ending_here;
    		}
    		cout<<max_so_far<<"\n";
		}
	}
}
