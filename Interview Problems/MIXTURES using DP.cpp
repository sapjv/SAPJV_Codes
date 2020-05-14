
/*

Problem Link :  https://www.codechef.com/problems/MIXTURES

Note : This problem is exactly similar to the matrix chain multiplication 
       problem ( which can be solved using DP in O(n^3) time ).

*/

// C++ Solution : 

lli a[101];
lli dp[101][101];

lli sum(int s,int e)
{
	lli total = 0;
	for(int i=s;i<=e;i++)
		total += a[i];
	return (total%100);
}

lli getSmoke(int i,int j)
{
	if(i>=j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	dp[i][j] = INT_MAX;
	for(int k=i;k<=j;k++)
	{
		lli current = getSmoke(i,k)+getSmoke(k+1,j)+(sum(i,k)*sum(k+1,j));
		if(dp[i][j]>current)
			dp[i][j] = current;
	}

	return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];

		memset(dp,-1,sizeof(dp));

		lli ans = getSmoke(0,n-1);
		cout<<ans<<"\n";
	}
}
