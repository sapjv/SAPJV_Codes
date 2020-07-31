/*

	### Trapping Rain Water Problem ###

Problem Link :  https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

Problem Statement : Given n non-negative integers representing an elevation map where the width 
					          of each bar is 1, compute how much water it is able to trap after raining.

Example Image Link :  https://www.geeksforgeeks.org/wp-content/uploads/watertrap.png

Approach: In the previous solution, to find the highest bar on the left and right, array 
traversal is needed which reduces the efficiency of the solution. To make this efficient 
one must pre-compute the highest bar on the left and right of every bar in linear time. 
Then use these pre-computed values to find the amount of water in every array element.

Algorithm:

Step1 : Create two array left and right of size n. create a variable max_ = INT_MIN.

Step2 : Run one loop from start to end. In each iteration update max_ as max_ = max(max_, arr[i]) 
		    and also assign Lmax[i] = max_

Step3 : Update max_ = INT_MIN.

Step4 : Run another loop from end to start. In each iteration update max_ as max_ = max(max_, arr[i]) 
		    and also assign Rmax[i] = max_

Step5 : Traverse the array from start to end.

Step6 : The amount of water that will be stored in this column is min(a,b) – array[i],(where a = Lmax[i] 
		    and b = Rmax[i]) add this value to total amount of water stored.

Step7 : Print the total amount of water stored.
	
------------------------------

Complexity Analysis:

Time Complexity: O(n). Only one traversal of the array is needed, So time Complexity is O(n).

Space Complexity: O(n). Two extra array is needed each of size n.
	
*/


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<lli> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        
		// Lmax[i] contains height of tallest bar to the left of ith bar including itself 
		// Rmax[i] contains height of tallest bar to the right of ith bar including itself 
        vector<lli> Lmax(n),Rmax(n);
        
		// Fill left array 
        Lmax[0] = a[0];
        for(int i=1;i<n;i++)
            Lmax[i] = max(a[i],Lmax[i-1]);
        
		// Fill right array 
        Rmax[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--)
            Rmax[i] = max(a[i],Rmax[i+1]);
        
		// Calculate the accumulated water element by element. Consider the amount of water 
		// on i'th bar, the amount of water accumulated on this particular bar will be equal 
		// to min(left[i], right[i]) - arr[i] . 
        lli ans = 0;
        for(int i=0;i<n;i++)
        {
            lli current_max = min(Lmax[i],Rmax[i]);
            ans += (current_max-a[i]);
        }
        
        cout<<ans<<"\n";
    }
}
