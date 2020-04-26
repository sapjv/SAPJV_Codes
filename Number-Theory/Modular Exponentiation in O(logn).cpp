/*

        ### Modular Exponentiation in O(logn) ###
        
Useful Link :  https://cp-algorithms.com/algebra/binary-exp.html
    
Task :  Compute  (a^b) mod M   in O(logn)

Note-1 :  This below code can handle very large values of a and b 
          both ( i.e., 0 <= A <= 10^18 , 0 <= B <= 10^18 can be handled too ).
    
Note-2 :  If m is a prime number we can speed up a bit this algorithm by 
          calculating x^(n mod (M−1)) instead of x^n. This follows directly 
          from Fermat's little theorem.

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

// This function computes (a^b) mod M        
lli modExp(lli a, lli b, lli M) 
{
    lli res = 1;
    a = a % M;
    while (b > 0) 
    {
        if(b & 1)
            res = ( res * a ) % M;
        a = (a * a) % M;
        b = b >> 1;
    }
    return res;
}

int main()
{
     lli a,b,MOD;
     cin>>a>>b>>MOD;
     lli ans = modExp(a,b,MOD);
     cout<<ans<<"\n";
}
