/*

        ### Binary Exponentiation in O(logn) ###
        
Useful Link :  https://cp-algorithms.com/algebra/binary-exp.html
    
Task :  Compute a^b in O(logn)

Note : Although the complexity of both iterative and recursive approach of binary exponentiation 
       is identical, but this below ( iterative ) approach will be faster in practice because we
       do not have the overhead of the recursive calls.

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

// This function computes a^b in O(logn)        
lli binExp(lli a, lli b) {
    lli res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    lli a,b;
    cin>>a>>b;
    lli ans = binExp(a,b);
    cout<<ans<<"\n";
}
