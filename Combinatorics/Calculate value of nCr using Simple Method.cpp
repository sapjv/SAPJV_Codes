/*

    ### Program to calculate value of nCr ###

Following are common definition of Binomial Coefficients.

a) A binomial coefficient C(n, k) can be defined as the coefficient of X^k in the expansion of (1 + X)^n.

b) A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can
be chosen from among n objects; more formally, the number of k-element subsets (or k-combinations) of
an n-element set.

--------------------------

Question: Given two numbers n and r, find value of nCr

Examples :

Input :  n = 5, r = 2
Output : 10 (The value of 5C2 is 10)

Input : n = 3, r = 1
Output : 3

The idea is simply based on below formula.
nCr = (n!) / (r! * (n-r)!)

------------------------------

Time Complexity: O(n)
Auxiliary Space: O(1)

*/

// CPP program To calculate The Value Of nCr
#include <bits/stdc++.h>
using namespace std;

// Returns factorial of n
int fact(int n){
	int res = 1;
	for (int i = 2; i <= n; i++){
		res = res * i;
	}
	return res;
}

int nCr(int n, int r){
	return fact(n) / (fact(r) * fact(n - r));
}

// Driver code
int main(){
	int n = 5, r = 3;
	cout << nCr(n, r);
	return 0;
}


