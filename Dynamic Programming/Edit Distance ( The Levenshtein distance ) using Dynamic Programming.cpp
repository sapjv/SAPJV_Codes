/*

		### Edit Distance ( The Levenshtein distance ) using Dynamic Programming ###
	
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of 
edits (operations) required to convert ‘str1’ into ‘str2’.

1. Insert
2. Remove
3. Replace

Note that All of the above operations are of equal cost.

----------------------

Problem Link :  https://www.spoj.com/problems/EDIST/   ( check my accepted solution )

Useful Link :  https://www.geeksforgeeks.org/edit-distance-dp-5/

Video Link : 

1. https://www.youtube.com/watch?v=We3YDTzNXEk
2. https://www.youtube.com/watch?v=MiqoA-yF-0M
3. https://www.youtube.com/watch?v=b6AGUjqIPsA

------------------------

Examples:

Input:   str1 = "geek", str2 = "gesek"
Output:  1 ( We can convert str1 into str2 by inserting a 's' )

Input:   str1 = "cat", str2 = "cut"
Output:  1 ( We can convert str1 into str2 by replacing 'a' with 'u' )

Input:   str1 = "sunday", str2 = "saturday"
Output:  3 ( Last three and first characters are same.  We basically need to convert "un" to "atur".  
			 This can be done using below three operations. Replace 'n' with 'r', insert t, insert a )


Time Complexity: O(m*n)		// where m = length of first string , n = length of second string
Auxiliary Space: O(m*n)		// where m = length of first string , n = length of second string

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

int editDistance(string x,string y,int lenX,int lenY)
{
	// Creating a dp table to store results of subproblems 
	int dp[lenX+1][lenY+1] = {0};
	
	// If second string is empty, only option is to remove all characters of second string 
	for(int i=0;i<=lenX;i++)
		dp[i][0] = i;		 // Min. operations = i 
	
	// If first string is empty, only option is to insert all characters of second string 
	for(int j=0;j<=lenY;j++)
		dp[0][j] = j;			 // Min. operations = j 
	
	// Filling dp[][] table in bottom up manner 
	for(int i=1;i<=lenX;i++)
	{
		for(int j=1;j<=lenY;j++)
		{
			// If last characters are same, ignore last char and recur for remaining string 
			if(x[i-1] == y[j-1])
				dp[i][j] = dp[i-1][j-1];
				
			// If the last character is different, consider all possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(dp[i-1][j],		  // Remove
									min(dp[i][j-1],		  // Insert 
										dp[i-1][j-1]));		 // Replace
		}
	}
		
	return dp[lenX][lenY];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		
		int lenA = (int)a.size();
		int lenB = (int)b.size();
		
		int ans = editDistance(a,b,lenA,lenB);
		
		cout<<ans<<"\n";
	}
}   
