
/*
	
	###  Given an array A[], find the maximum j–i such that  A[i] <= A[j] ###

Task :  Given an array A[] of N positive integers. The task is to find the maximum 
of j-i subjected to the constraint of A[i] <= A[j].

Problem Link :  https://practice.geeksforgeeks.org/problems/maximum-index/0

Examples :

  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
  Output: 6  (j = 7, i = 1)

  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
  Output: 8 ( j = 8, i = 0)

  Input:  {1, 2, 3, 4, 5, 6}
  Output: 5  (j = 5, i = 0)

  Input:  {6, 5, 4, 3, 2, 1}
  Output: -1 
  
---------------------

Below Solution is based on two pointers method. I wrote this below solution by 
myself. And it is getting accepted in 0.18sec.

I think the Time Complexity of below solution is O(n) because in the comments, author of this 
problem said that the time limit for this question is set to an upper bound of O(n).

*/

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<lli> a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
            
        vector<lli> res;
        int ans = -1;
        
        int i=1;
        for(int i=1;i<=n;i++)
        {
	    // for each i, we'll start j from last index and try to find the element which 
	    // satisfy the given property a[i]<=a[j]
            int j=n;
			
	    // if the current answer is already greater than the current position of i and j, then no 
	    // need to check for futher i and j because it will be always smaller then current answer.
            if(ans >= (n-i))			
                break;
				
	    // here using two pointers method
            while(i<=j)
            {
                if(a[i]<=a[j])
                {
	               // only update answer if it is greater than the previous answer and break 
                    if(ans<=(j-i))
                    {
                        ans = j-i;
                        break;  
                    }
                }
                j--;
            }
        }
        
        cout<<ans<<"\n";
    }
}
