// C++ program for space optimized Dynamic Programming
// Solution of Binomial Coefficient

#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k){
	int C[k + 1];
	memset(C, 0, sizeof(C));
	C[0] = 1;               // nC0 is 1
	for (int i = 1; i <= n; i++){
		// Compute next row of pascal triangle using the previous row
		for (int j = min(i, k); j > 0; j--){
			C[j] = C[j] + C[j - 1];
		}
	}
	return C[k];
}

/* Driver code*/
int main(){
	int n = 5, k = 2;
	cout << "Value of C(" << n << "," << k << ")"<< " is " <<binomialCoeff(n, k);
	return 0;
}

/*

Output: Value of C(5, 2) is 10

Time Complexity: O(n*k)
Auxiliary Space: O(k)

Explanation:
1==========>> n = 0, C(0,0) = 1
1–1========>> n = 1, C(1,0) = 1, C(1,1) = 1
1–2–1======>> n = 2, C(2,0) = 1, C(2,1) = 2, C(2,2) = 1
1–3–3–1====>> n = 3, C(3,0) = 1, C(3,1) = 3, C(3,2) = 3, C(3,3)=1
1–4–6–4–1==>> n = 4, C(4,0) = 1, C(4,1) = 4, C(4,2) = 6, C(4,3)=4, C(4,4)=1

So here every loop on i, builds i'th row of pascal triangle, using (i-1)th row.

At any time, every element of array C will have some value (ZERO or more) and in the next
iteration, the value for those elements comes from the previous iteration.

In statement,

C[j] = C[j] + C[j-1]

The right-hand side represents the value coming from the previous iteration (A row of
Pascal's triangle depends on the previous row). The left-Hand side represents the value
of the current iteration which will be obtained by this statement.

Let's say we want to calculate C(4, 3), i.e. n=4, k=3:

All elements of array C of size 4 (k+1) are initialized to ZERO.

i.e. C[0] = C[1] = C[2] = C[3] = C[4] = 0;

Then C[0] is set to 1

For i = 1:
C[1] = C[1] + C[0] = 0 + 1 = 1 ==>> C(1,1) = 1

For i = 2:
C[2] = C[2] + C[1] = 0 + 1 = 1 ==>> C(2,2) = 1
C[1] = C[1] + C[0] = 1 + 1 = 2 ==>> C(2,1) = 2

For i=3:
C[3] = C[3] + C[2] = 0 + 1 = 1 ==>> C(3,3) = 1
C[2] = C[2] + C[1] = 1 + 2 = 3 ==>> C(3,2) = 3
C[1] = C[1] + C[0] = 2 + 1 = 3 ==>> C(3,1) = 3

For i=4:
C[4] = C[4] + C[3] = 0 + 1 = 1 ==>> C(4,4) = 1
C[3] = C[3] + C[2] = 1 + 3 = 4 ==>> C(4,3) = 4
C[2] = C[2] + C[1] = 3 + 3 = 6 ==>> C(4,2) = 6
C[1] = C[1] + C[0] = 3 + 1 = 4 ==>> C(4,1) = 4

C(4,3) = 4 is would be the answer in our example.

*/
