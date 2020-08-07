
/*

Problem Link :  https://leetcode.com/problems/counting-bits/

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the 
number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]

-----------------------------

Follow up ( Requirement ) :

1. It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in 
   linear time O(n) /possibly in a single pass?
   
2. Space complexity should be O(n).

3. Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or 
   in any other language.

------------------------------

Useful Videos : 

1.  https://www.youtube.com/watch?v=awxaRgUB4Kw
2.  https://www.youtube.com/watch?v=ftxesO6jdbQ
3.  https://www.youtube.com/watch?v=iuqr5hHk2MI
4.  https://www.youtube.com/watch?v=yU1EnHZWscU

-----------------------------

Time Complexity of below solution : O(n)
Space Complexity of below solution : O(n)

*/

 vector<int> countBits(int num) 
 {       
        vector<int> ones(num+1);
        
        ones[0] = 0;
        int twoP = 1;
        
        for(int i=1;i<=num;i++)
        {
            if(i==2*twoP)
            {
                ones[i] = 1;
                twoP = i;
            }
            else
                ones[i] = ones[i-twoP]+1;
        }
        
        return ones;
}


