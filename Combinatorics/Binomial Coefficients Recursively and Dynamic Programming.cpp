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

int main(){
	int n = 5, k = 2;
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k) << "\n";
	cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeffDP(n, k) << "\n";
	return 0;
}

/*

Output:

Value of C(5, 2) is 10
Value of C(5, 2) is 10  // Value of C[5][2] is 10

*/
