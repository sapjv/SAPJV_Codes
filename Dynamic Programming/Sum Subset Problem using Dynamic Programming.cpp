/*

Problem Statement : Given a set of non-negative integers, and a value sum, determine if there 
                    is a subset of the given set with sum equal to given sum.
                     
Problem Link :  https://www.codechef.com/problems/MARCHA1

Useful Links : 
1. https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
2. https://stackoverflow.com/questions/4355955/subset-sum-algorithm
3. https://www.techiedelight.com/subset-sum-problem/ ( below code has been taken from this link )

Useful Videos : 
1. https://www.youtube.com/watch?v=kyLxTdsT8ws&t=1s
2. https://www.youtube.com/watch?v=s6FhG--P7z0

Time Complexity : The time complexity of below solution is O(n*sum).
Space Complexity : O(n*sum) because of 2-d Matrix of size (n+1)x(sum+1)

Note : Below code is based on bottom-up approach. In the bottom-up approach, we solve smaller
       sub-problems first, then solve larger sub-problems from them. The following bottom-up 
       approach computes matrix[i][j], for each 1<=i<=n and 1<=j<=sum, which is true if subset 
	   with sum j can be found using items first upto first i items. It uses value of smaller 
	   values i and j already computed. this below solution does not have any recursion overhead.

*/

#include <iostream>
using namespace std;

// Return true if there exists a subarray of array[0..n) with given sum
bool subsetSum(int arr[], int n, int sum)
{
	// matrix[i][j] stores true if subset with sum j can be attained with using items up to first i items
	bool matrix[n + 1][sum + 1];

	// if 0 items in the list and sum is non-zero
	for (int j = 1; j <= sum; j++)
		matrix[0][j] = false;

	// if sum is zero
	for (int i = 0; i <= n; i++)
		matrix[i][0] = true;
	
	for (int i = 1; i <= n; i++)			// do for ith item
	{
		for (int j = 1; j <= sum; j++)			// consider all sum from 1 to sum
		{
			// don't include ith element if j-arr[i-1] is negative
			if (arr[i - 1] > j)
				matrix[i][j] = matrix[i - 1][j];
			else
			// find subset with sum j by excluding or including the ith item
				matrix[i][j] = matrix[i - 1][j] || matrix[i - 1][j - arr[i - 1]];
		}
	}

	return matrix[n][sum];			// return maximum value
}

int main()
{
	// Input: set of items and a sum
	int arr[] = { 7, 3, 2, 5, 8 };
	
	int sum = 18;

	// number of items
	int n = sizeof(arr) / sizeof(arr[0]);

	if (subsetSum(arr, n, sum))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
