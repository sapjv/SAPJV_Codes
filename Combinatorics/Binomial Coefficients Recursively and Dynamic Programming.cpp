/*
    ### Binomial Coefficient (Recursively + Dynamic Programming) ###

A binomial coefficient C(n, k) can be defined as the coefficient of x^k in the expansion of (1 + x)^n.

A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects
can be chosen from among n objects more formally, the number of k-element subsets (or k-combinations)
of a n-element set.

Question: Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).

1) Optimal Substructure: The value of C(n, k) can be recursively calculated using the following standard
formula for Binomial Coefficients.

   C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1
   Note: if k > n, then C(n, k) = 0

Following is a simple recursive implementation that simply follows the recursive structure mentioned above.

Time Complexity: O(n*max(k,n-k))
Auxiliary Space: O(n*max(k,n-k))

*/

// A naive recursive C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k){
	if(k > n){
		return 0;
	}
	if(k == 0 || k == n){
		return 1;
	}
	return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

// ------------------------------------------- //

/*

2) Overlapping Subproblems: It should be noted that the above function computes the same subproblems
again and again. See the following recursion tree for n = 5 an k = 2. The function C(3, 1) is called
two times. For large values of n, there will be many common subproblems.

check this image:  https://media.geeksforgeeks.org/wp-content/uploads/20200721141715/tt-300x155.jpg

Since the same subproblems are called again, this problem has the Overlapping Subproblems property.
So, the Binomial Coefficient problem has both properties (see this and this) of a dynamic programming
problem. Like other typical Dynamic Programming(DP) problems, re-computations of the same subproblems
can be avoided by constructing a temporary 2D-array C[][] in a bottom-up manner. Following is Dynamic
Programming-based implementation.

Time Complexity: O(n*k)
Auxiliary Space: O(n*k)

*/

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeffDP(int n, int k){
    int C[n + 1][k + 1];

    memset(C, 0, sizeof(C));

    // Calculate value of Binomial Coefficient in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i){       // Base Cases
                C[i][j] = 1;
            } else {    // Calculate value using previously stored values
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    return C[n][k];
}

// ------------------------------------------- //

/*

Memoization Approach: The idea is to create a lookup table and follow the recursive top-down approach.
Before computing any value, we check if it is already in the lookup table. If yes, we return the value.
Else we compute the value and store it in the lookup table. Following is the Top-down approach of
dynamic programming to finding the value of the Binomial Coefficient.

Time Complexity: O(max(n,n-k))
Auxiliary Space: O(n*k)

*/

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeffUtil(int n, int k, int** dp){
    if(k>n){
        return 0;
    }

    if(dp[n][k] != -1){         // If value in lookup table then return
        return dp[n][k];
    }

    if(k == 0 || k == n){       // store value in a table before return
        dp[n][k] = 1;
        return dp[n][k];
    }

    // save value in lookup table before return
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) + binomialCoeffUtil(n - 1, k, dp);
    return dp[n][k];
}

int binomialCoeffMemoizedDP(int n, int k){
    int** dp = new int*[n + 1];      // make a temporary lookup table

    for (int i = 0; i < (n + 1); i++) {     // loop to create table dynamically
        dp[i] = new int[k + 1];
    }

    // nested loop to initialize the table with -1
    for (int i = 0; i < (n + 1); i++) {
        for (int j = 0; j < (k + 1); j++) {
            dp[i][j] = -1;
        }
    }

    return binomialCoeffUtil(n, k, dp);
}

// ------------------------------------------------------- //


int main(){
	int n = 5, k = 2;
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k) << "\n";
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeffDP(n, k) << "\n";
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeffMemoizedDP(n, k) << "\n";

	n = 5, k = 12;
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k) << "\n";
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeffDP(n, k) << "\n";
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeffMemoizedDP(n, k) << "\n";
	return 0;
}

/*

Output:

Value of C(5, 2) is 10
Value of C(5, 2) is 10  // Value of C[5][2] is 10
Value of C(5, 2) is 10

Value of C(5, 12) is 0
Value of C(5, 12) is 0
Value of C(5, 12) is 0
*/
