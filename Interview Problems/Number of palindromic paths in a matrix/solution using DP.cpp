
/*

	### Number of palindromic paths in a matrix using Dynamic Programming ###

Task :  Given a matrix containing lower alphabetical characters only, we need to count number of palindromic 
paths in given matrix. A path is defined as a sequence of cells starting from top-left cell and ending at 
bottom-right cell. We are allowed to move to right and down only from current cell.

Problem Link :  https://practice.geeksforgeeks.org/problems/number-of-palindromic-paths-in-a-matrix/0

Example :

Input : mat[][] = {"aaab”, 
                   "baaa”
                   “abba”}
Output : 3

Number of palindromic paths are 3 from top-left to bottom-right :
aaaaaa (0, 0) -> (0, 1) -> (1, 1) -> (1, 2) -> (1, 3) -> (2, 3)    
aaaaaa (0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (1, 3) -> (2, 3)    
abaaba (0, 0) -> (1, 0) -> (1, 1) -> (1, 2) -> (2, 2) -> (2, 3)    

Example Image Link :  https://media.geeksforgeeks.org/wp-content/cdn-uploads/palindrome-matrix.jpg

------------------------

Useful Video Link ( must watch ) :  https://www.youtube.com/watch?v=whlT0qBGSBg

------------------------

Solution :  We can solve this problem recursively, we start from two corners of a palindromic path(top-left and bottom 
right). In each recursive call, we maintain a state which will constitute two cells one from starting and one from end 
which should be equal for palindrome property. If at a state, both cell characters are equal then we call recursively 
with all possible movements in both directions.

As this can lead to solving same subproblem multiple times, we have taken a dp memo in below code which stores the 
calculated result with key as indices of starting and ending cell so if subproblem with same starting and ending 
cell is called again, result will be returned by memo directly instead of recalculating again.
	
Time Complexity : O(R x C)      where R = no. of rows , C = no. of columns

*/

int n,m;
int dp[10][10][10][10];
char matrix[10][10];

lli solve(int si,int sj,int ei,int ej)
{
	// Base Case 1 : if initial si and sj indices are out of bound, then return 0
	if(si<0 || si>=n || sj<0 || sj>=m)          // this is first base case 
		return 0;

	// Base Case 1 : if final indices ei and ej are out of range ( with respect to initial si and sj indices )
	if(ei<0 || ei<si || ej<0 || ej<sj)          // please note that this base case is different from the first one
		return 0;

	// Base case 2 : if current indices characters are not equal, then palindrome property is not satisfied, Hence return 0 
	if(matrix[si][sj]!=matrix[ei][ej])
		return 0;
	
	// Base Case 3 : if current indices are adjacent then return 1
	if(abs((si-ei) + (sj-ej)) <= 1)
		return 1;

	// if result is already calculated, then return it from here
	if(dp[si][sj][ei][ej]!=-1)
		return dp[si][sj][ei][ej];

	lli ans = 0;			// Initializing ans
	
	// calling recursively for all possible movements 
	ans += solve(si+1,sj,ei-1,ej) + solve(si+1,sj,ei,ej-1) + 
			  solve(si,sj+1,ei-1,ej) + solve(si,sj+1,ei,ej-1);

	// storing the calculated ans in dp array and returning from here 
	return dp[si][sj][ei][ej] = ans;
}

int main()
{
    	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>matrix[i][j];
		}

		memset(dp,-1,sizeof(dp));

		lli res = solve(0,0,n-1,m-1);
		cout<<res<<"\n";
	}
}
