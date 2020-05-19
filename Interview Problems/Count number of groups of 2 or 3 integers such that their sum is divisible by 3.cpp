/*

Problem Link :  https://practice.geeksforgeeks.org/problems/number-of-groups/0

Task :  Given an array Arr[] of N distinct integers. Write a program to find the count 
        of groups of 2 or 3 integers that can be formed by choosing integers from the 
        given array such that sum of integers in each of the group is divisible by 3.
        
Tutorial :  https://www.geeksforgeeks.org/number-groups-sizes-two-three-divisible-3/

C++ Solution ( in O(n) time ) :

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			v[i]%=3;
		}

		int two = 0 , one = 0 , zero = 0;
		for(int i=0;i<n;i++)
		{
			if(v[i]==1)
				one++;
			else if(v[i]==2)
				two++;
			else
				zero++;
		}

		lli ans = 0;
		
		ans += (one*two);
		ans += (ans*zero);          // all zeroes will contribute to pairs of 1s and 2s
		
    // we'll use combination formula ( nCr - choose r objects from n objects ) from here below : 
    
		ans += (zero*(zero-1))/2;           // zeroC2 ( choose any two zeroes from all zeroes )
		ans += (((zero*(zero-1))/2)*(zero-2))/3;          // zeroC3 ( choose any three zeroes from all zeroes )
		
		ans += (((one*(one-1))/2)*(one-2))/3;          // oneC3 ( choose any three one's from all one's )
		ans += (((two*(two-1))/2)*(two-2))/3;          // twoC3 ( choose any three two's from all two's )

		cout<<ans<<"\n";
	}
}
