// Question : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

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
		lli n,s;
		cin>>n>>s;
		lli a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		if(n==1)
		{
		    if(s==a[0])
		    cout<<"1 1\n";
		    else
		    cout<<"-1\n";
		}
		if(n>=2)
		{
    		lli start=-1,end=-1;
    		lli sum=a[0];
    		lli i=0,j=1;
    		while(i<=j && i<n)
    		{
    		    if(sum==s)
    		    {
    		        start=i+1;
    		        end=j;
    		        break;
    		    }
    		    
    		    if(sum>s)
    		    {
    		        sum-=a[i];
    		        i++;
    		    }
    		    else
    		    {
    		        sum+=a[j];
    		        j++;
    		    }
    		}
    		if(start==-1 && end==-1)
    		{
    		    if(sum==s)
    		    cout<<i+1<<" "<<j+1<<"\n";
    		    else
    		    cout<<"-1\n";
    		}
    		else
    		cout<<start<<" "<<end<<"\n";
		}
	}
}

