/*

    ### Compute nCr % p | Set 1 (Introduction and Dynamic Programming Solution) ###

Given three numbers n, r and p, compute value of nCr mod p.

Example:

Input:  n = 10, r = 2, p = 13
Output: 6 (Explanation: 10C2 is 45 and 45 % 13 is 6).


METHOD 1: (Using Dynamic Programming):

A Simple Solution is to first compute nCr, then compute nCr % p. This solution works fine when the
value of nCr is small.

What if the value of nCr is large?

The value of nCr%p is generally needed for large values of n when nCr cannot fit in a variable, and
causes overflow. So computing nCr and then using modular operator is not a good idea as there will be
overflow even for slightly larger values of n and r. For example the methods discussed here and here
cause overflow for n = 50 and r = 40.

The idea is to compute nCr using below formula

C(n, r) = C(n-1, r-1) + C(n-1, r)
C(n, 0) = C(n, n) = 1

Working of Above formula and Pascal Triangle:

Let us see how above formula works for C(4, 3):

1==========>> n = 0, C(0, 0) = 1
1–1========>> n = 1, C(1, 0) = 1, C(1, 1) = 1
1–2–1======>> n = 2, C(2, 0) = 1, C(2, 1) = 2, C(2, 2) = 1
1–3–3–1====>> n = 3, C(3, 0) = 1, C(3, 1) = 3, C(3, 2) = 3, C(3, 3)=1
1–4–6–4–1==>> n = 4, C(4, 0) = 1, C(4, 1) = 4, C(4, 2) = 6, C(4, 3)=4, C(4, 4)=1

So here every loop on i, builds i'th row of pascal triangle, using (i-1)th row Extension of above
formula for modular arithmetic:

We can use distributive property of modular operator to find nCr % p using above formula.

   C(n, r)%p = [ C(n-1, r-1)%p + C(n-1, r)%p ] % p
   C(n, 0) = C(n, n) = 1

The above formula can implemented using Dynamic Programming using a 2D array (not discussing
here). The 2D array based dynamic programming solution can be further optimized by constructing
one row at a time.

Below is implementation based on the space optimized version discussed in above post.

Time complexity of below solution is O(n*r) and it requires O(r) space.

Note: There are more and better solutions to above problem.
*/


// A Dynamic Programming based solution to compute nCr % p using 1-D array
#include <bits/stdc++.h>
using namespace std;

// Returns nCr % p
int nCrModp(int n, int r, int p){
	// Optimization for the cases when r is large
	if (r > n - r)
		r = n - r;

	// The array C is going to store last row of pascal triangle at the end. And
	// last entry of last row is nCr
	int C[r + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // Top row of Pascal Triangle

	// One by one constructs remaining rows of Pascal Triangle from top to bottom
	for (int i = 1; i <= n; i++) {
		// Fill entries of current row using previous row values
		for (int j = min(i, r); j > 0; j--){
			C[j] = (C[j] + C[j - 1]) % p;   // nCj = (n-1)Cj + (n-1)C(j-1);
		}
	}
	return C[r];
}

// Driver program
int main(){
	int n = 10, r = 2, p = 13;
	cout << "Value of " << n << "C" << r << " % " << p << " is " << nCrModp(n, r, p) << "\n";
	return 0;
}



