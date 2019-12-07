/*

LCS Problem Statement : Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence 
that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are 
subsequences of “abcdefg”.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

Useful Link :
 
1. https://www.techiedelight.com/longest-common-subsequence/
2. https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

Useful Video Link : 

1. https://www.youtube.com/watch?v=sSno9rV8Rhg ( must watch )
2. https://www.youtube.com/watch?v=NnD96abizww

Time Complexity :  The time complexity of the below DP solution is O(m*n) where m = length of first string , n = length of the second string 

Space Complexity : The space complexity of the below DP solution is O(m*n) where m = length of first string , n = length of the second string 

*/

#include<bits/stdc++.h>
using namespace std;

// Function to find length of Longest Common Subsequence of string x[0..lenX-1] and y[0..lenY-1]
int LCSLength(string x,string y,int lenX,int lenY)
{
	// dp table stores solution to already computed sub-problems
	// i.e. dp[i][j] stores the length of LCS of substring x[0..i-1] and y[0..j-1]
	int dp[lenX+1][lenY+1];
	
	// first column of the dp table will be all 0
	for(int i=0;i<=lenX;i++)
		dp[i][0] = 0;
	
	// first row of the dp table will be all 0
	for(int j=0;j<=lenY;j++)
		dp[0][j] = 0;
	
	// fill the dp table in bottom-up manner
	for(int i=1;i<=lenX;i++)
	{
		for(int j=1;j<=lenY;j++)
		{
			// if current character of string x and string y matches
			if(x[i-1] == y[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
				
			// else if current character of string x and string y don't match
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	// length of LCS will be last entry (cell) in the dp table
	return dp[lenX][lenY];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string x = "XMJYAUZ", y = "MZJAWXU";
	
	int lenX = x.length();
	int lenY = y.length();

	cout << "The length of LCS is " << LCSLength(x,y,lenX,lenY);

	return 0;
}
