
/*

Useful Videos Link for Matrix Chain Multiplication :

1. https://www.youtube.com/watch?v=prx1psByp7U
2. https://www.youtube.com/watch?v=_WncuhSJZyA
3. https://www.youtube.com/watch?v=eKkXU3uu2zk&t=1s
4. https://www.youtube.com/watch?v=D1U74eFLg_g
5. https://www.youtube.com/watch?v=GMzVeWpyTN0&t=3s

Practice Question :  https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0

*/

//---------------------------------------------


// 1. Top Down Memoized Recursive Solution

int a[101];
lli dp[101][101];

lli matrixChain(int i,int j)
{
	if(i>=j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	lli temp = INT_MAX;
	for(int k=i;k<j;k++)
	{
		lli current = matrixChain(i,k) + matrixChain(k+1,j) + a[i-1]*a[j]*a[k];
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
		
		lli ans = matrixChain(1,n-1);
		
		cout<<ans<<"\n";
	} 
}

// ----------------------------------------------------

// 2. Bottum Up Memoized DP Solution

