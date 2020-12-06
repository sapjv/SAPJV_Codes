#include <bits/stdc++.h>

using namespace std;

long int binpower(long int base, long int e, long int mod) {
    long int result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (long int)result * base % mod;
        base = (long int)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(long int n, long int b, long int t, int a) {
    long int test = binpower(b, t, n);
    if (test == 1 || test == n - 1)
        return false;
    for (int r = 1; r < a; r++) {
        test = ((long int)test * test) % n;
        if (test == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(long int n, int b) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int a = 0;
    long int t = n - 1;
    while ((t & 1) == 0) {
        t >>= 1;
        a++;
    }

    int iter = 10;
    for (int i = 0; i < iter; i++) {
        if (check_composite(n, b, t, a))
            return false;
    }
    return true;
}

int main() 
{
    int b = 163;  // relative prime to n (will be given)
  
    cout << "All primes smaller than 100: \n"; 
    for (int n = 1; n < 100; n++) 
       if (MillerRabin(n, b)) 
          cout << n << " "; 
  
}