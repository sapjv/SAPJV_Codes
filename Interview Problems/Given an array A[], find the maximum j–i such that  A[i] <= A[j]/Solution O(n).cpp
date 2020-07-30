
/*

###  Given an array A[], find the maximum j–i such that  A[i] <= A[j] ###

Task :  Given an array A[] of N positive integers. The task is to find the maximum 
of j-i subjected to the constraint of A[i] <= A[j].

Problem Link :  https://practice.geeksforgeeks.org/problems/maximum-index/0

Useful Link :  https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

Examples :
Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 6  (j = 7, i = 1)

Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
Output: 8 ( j = 8, i = 0)

Input:  {1, 2, 3, 4, 5, 6}
Output: 5  (j = 5, i = 0)

Input:  {6, 5, 4, 3, 2, 1}
Output: -1 

-------------------------------

Solution :  To solve this problem, we need to get two optimum indexes of arr[]: left index i and right index j. For an 
element arr[i], we do not need to consider arr[i] for left index if there is an element smaller than arr[i] on left side 
of arr[i]. Similarly, if there is a greater element on right side of arr[j] then we do not need to consider this j for 
right index. So we construct two auxiliary arrays LMin[] and RMax[] such that LMin[i] holds the smallest element on left 
side of arr[i] including arr[i], and RMax[j] holds the greatest element on right side of arr[j] including arr[j]. After 
constructing these two auxiliary arrays, we traverse both of these arrays from left to right. While traversing LMin[] 
and RMa[] if we see that LMin[i] is greater than RMax[j], then we must move ahead in LMin[] (or do i++) because all 
elements on left of LMin[i] are greater than or equal to LMin[i]. Otherwise we must move ahead in RMax[j] to look for 
a greater j – i value.

Time Complexity: O(n)
Auxiliary Space: O(n)

------------------------------

Note : My two pointer solution is passing in 0.18sec , whereas this solution of geeksforgeeks is passing in 0.28sec.
It means my two pointer method is faster than this solution.

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
            
        vector<lli> Lmin(n+1),Rmax(n+1);
        
        // Construct LMin[] such that LMin[i] stores the minimum value from (arr[1], arr[2], ... arr[n]) 
        Lmin[1] = a[1];
        for(int i=2;i<=n;i++)
            Lmin[i] = min(Lmin[i-1],a[i]);
        
        // Construct RMax[] such that RMax[j] stores the maximum value from (arr[n], arr[n-1], ..arr[1]) 
        Rmax[n] = a[n];
        for(int i=n-1;i>=1;i--)
            Rmax[i] = max(Rmax[i+1],a[i]);
    
        // Traverse both arrays from left to right to find optimum j-i. This process is similar to merge() of MergeSort 
        int i=1,j=1;
        int ans = -1;
        while(j<=n && i<=n)
        {
            if(Lmin[i]<=Rmax[j])
            {
                ans = max(ans,j-i);
                j++;
            }
            else
                i++;
        }
    
        cout<<ans<<"\n";
    }
}
