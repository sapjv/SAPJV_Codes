
// Problem Link:  https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1/?



// Method 1 ( using left shift operator ) : In this method, we will bitwise AND the given n with 2^k

bool checkKthBit(int n, int k){
    if(n&(1<<k))          // think it deeply
        return true;
    return false;  
}


// ------------------------------



// Method 2 ( using right shift operator ) : In this method, we will right shift n by k positions, and then check whether 0th bit (right most bit) is on or not.

bool checkKthBit(int n, int k){
    if(1&(n>>k))         // think it deeply
        return true;
    return false;   
}


