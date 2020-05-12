
/*

Useful Videos Link for Matrix Chain Multiplication :

1. https://www.youtube.com/watch?v=prx1psByp7U
2. https://www.youtube.com/watch?v=_WncuhSJZyA
3. https://www.youtube.com/watch?v=eKkXU3uu2zk&t=1s
4. https://www.youtube.com/watch?v=D1U74eFLg_g
5. https://www.youtube.com/watch?v=GMzVeWpyTN0&t=3s

Practice Question :  https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0

Time Complexity :  O(n^3) for both Top Down and Bottom Up approach

*/

//---------------------------------------------


// 1. Top Down Memoized Recursive Solution

int a[101];
lli dp[101][101];

lli matrixChainTopDown(int i,int j)
{
	if(i>=j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	lli temp = INT_MAX;
	for(int k=i;k<j;k++)
	{
		lli current = matrixChainTopDown(i,k) + matrixChainTopDown(k+1,j) + a[i-1]*a[j]*a[k];
		if(temp>current)
			temp = current;
	}
	
	return dp[i][j] = temp;
}

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

		for(int i=0;i<n;i++)
			cin>>a[i];

		memset(dp,-1,sizeof(dp));
		
		lli ans = matrixChainTopDown(1,n-1);
		
		cout<<ans<<"\n";
	} 
}

// ----------------------------------------------------

// 2. Bottum Up Memoized DP Solution

lli matrixChainBottomUp(int a[],int n)				// a[] is given dimension array of matrices
{
	lli dp[n][n];
	
	for(int i=0;i<n;i++)
		dp[i][i] = 0;

	for(int L=2;L<n;L++)
	{
		for(int i=1;i<n-L+1;i++)
		{
			int j = i+L-1;
			
			dp[i][j] = INT_MAX;
			for(int k=i;k<j;k++)
			{
				lli temp = dp[i][k] + dp[k+1][j] + a[i-1]*a[j]*a[k];
				if(temp<dp[i][j])
					dp[i][j] = temp;
			}
		}
	}

	return dp[1][n-1];
}
