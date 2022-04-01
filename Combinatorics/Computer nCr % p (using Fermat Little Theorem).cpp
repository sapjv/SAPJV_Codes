
/*

    ### Compute nCr % p | Set 3 (Using Fermat Little Theorem) ###

Given three numbers n, r and p, compute the value of nCr mod p. Here p is a prime number
greater than n. Here nCr is Binomial Coefficient.

NOTE: p>n MUST BE A FULFILLED GIVEN CONDITION

Example:

Input:  n = 10, r = 2, p = 13
Output: 6 (Explanation: 10C2 is 45 and 45 % 13 is 6.)

Input:  n = 6, r = 2, p = 13
Output: 2

IN THIS POST, FERMAT THEOREM-BASED SOLUTION IS DISCUSSED.

Fermat's little theorem states that if p is a prime number, then for any integer a, the number (a)^p – a is
an integer multiple of p. In the notation of modular arithmetic, this is expressed as:

a^p = a (mod p)

For example, if a = 2 and p = 7, 27 = 128, and 128 – 2 = 7 × 18 is an integer multiple of 7.

If a is not divisible by p, Fermat's little theorem is equivalent to the statement a^(p – 1) – 1 is an
integer multiple of p, i.e

a^(p-1) = 1 (mod p)

If we multiply both sides by a^(-1), we get.

a^(p-2) = (a^(-1)) (mod p)

So we can find modular inverse as power(p-2).

Computation:

We know the formula for  nCr i.e., nCr = fact(n) / (fact(r) x fact(n-r))

Here fact() means factorial.

So, nCr % p = (fac[n]* [modIverse(fac[r]) % p] * [modIverse(fac[n-r]) % p]) % p;

Here modIverse() means modular inverse under modulo p.

Following is the implementation of the above algorithm. In the following implementation, an
array fac[] is used to store all the computed factorial values.

*/

// A modular inverse based solution to compute nCr % p
#include <bits/stdc++.h>
using namespace std;
#define ulli unsigned long long int

// Iterative Function to calculate (a^b)%p in O(log y) i.e., This function computes (a^b) mod M
ulli modExp(ulli a, ulli b, ulli M) {
    ulli res = 1;
    a = a % M;
    while(b > 0){
        if(b & 1){
            res = ( res * a ) % M;
        }
        a = (a * a) % M;
        b = b >> 1;
    }
    return res;
}

// Returns n^(-1) mod p i.e., modular inverse of n under modulo p.
ulli modInverse(ulli n, int p){
	return modExp(n, p - 2, p);
}

// Returns nCr % p using Fermat's little theorem.
ulli nCrModPFermat(ulli n, int r, int p){
	if (n < r)      // If n<r, then nCr should return 0
		return 0;

	if (r == 0)     // Base case
		return 1;

	// Fill factorial array so that we can find all factorial of r, n and n-r
	ulli fac[n + 1];
	fac[0] = 1;
	for(int i = 1; i <= n; i++){
		fac[i] = (fac[i - 1] * i) % p;
	}

	ulli numerator = fac[n];
	ulli denominator1 = modInverse(fac[r], p) % p;
	ulli denominator2 = modInverse(fac[n - r], p) % p;
	return (numerator * denominator1 * denominator2) % p;
}

int main(){
	int n = 10, r = 2, p = 13;
	cout << "Value of " << n << "C" << r << " % " << p << " is " << nCrModPFermat(n, r, p) << "\n";
	return 0;
}

// Output: Value of nCr % p is 6

/*

NOTE:

Improvements: In competitive programming, we can pre-compute fac[] for given upper limit so that
we don’t have to compute it for every test case. We also can use unsigned long long int everywhere
to avoid overflows.

*/
