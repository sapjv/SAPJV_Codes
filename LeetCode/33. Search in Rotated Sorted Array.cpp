
/*

Problem Link :  https://leetcode.com/problems/search-in-rotated-sorted-array/

Description : 

Given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You should search for target in nums and if you found return its index, otherwise return -1.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 
Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4

// -----------------------------------------

Useful Link :  https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/   

Important Node : Must check GFG Basic solution on the website.

-----------------------------

Solution :

Note :  All solutions provided here assume that all elements in the array are distinct.

GFG Basic Solution:  

Approach:

1. The idea is to find the pivot point, divide the array in two sub-arrays and perform binary search to get 
   the pivot point.
2. The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element 
   is the only element for which next element to it is smaller than it.
3. Using the above statement and binary search pivot can be found.
4. After the pivot is found out divide the array in two sub-arrays.
5. Now the individual sub – arrays are sorted so the element can be searched using Binary Search.

Implementation:

Input arr[] = {3, 4, 5, 1, 2}
Element to Search = 1
  1) Find out pivot point and divide the array in two sub-arrays. (pivot = 2)  // Index of 5
  2) Now call binary search for one of the two sub-arrays.
      (a) If element is greater than 0th element then search in left array
      (b) Else Search in right array (1 will go in else as 1 < 0th element(3))
  3) If element is found in selected sub-array then return index
     Else return -1.

Complexity Analysis:

Time Complexity: O(log n).
1. Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
2. Space Complexity: O(1), No extra space is required.

Note :  Check GFG code by yourself.

--------------------------------

GFG Improved Solution :

Approach: Instead of two or more pass of binary search the result can be found in one pass of binary 
search. The binary search needs to be modified to perform the search. The idea is to create a recursive 
function that takes l and r as range in input and the key.

1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l] to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..h]
4) Else (arr[mid+1..h] must be sorted)
    a) If key to be searched lies in range from arr[mid+1] to arr[h], recur for arr[mid+1..h].
    b) Else recur for arr[l..mid] 

Complexity Analysis:

Time Complexity: O(log n).
1. Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
2. Space Complexity: O(1). As no extra space is required.

*/

GFG Improved Solution :

// Returns index of key in arr[l..h] if key is present, otherwise returns -1 
int search(int arr[], int l, int h, int key) 
{ 
    if (l > h) 
        return -1; 
  
    int mid = (l + h) / 2; 
    if (arr[mid] == key) 
        return mid; 
  
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) 
    { 
        
        // As this subarray is sorted, we can quickly check if key lies in half or other half 
        if (key >= arr[l] && key <= arr[mid]) 
            return search(arr, l, mid - 1, key); 
        
        // If key not lies in first half subarray, Divide other half  into two subarrays, such that 
        // we can quickly check if key lies in other half 
        return search(arr, mid + 1, h, key); 
    } 
  
    // If arr[l..mid] first subarray is not sorted, then arr[mid... h] must be sorted subarray 
    if (key >= arr[mid] && key <= arr[h]) 
        return search(arr, mid + 1, h, key); 
  
    return search(arr, l, mid - 1, key); 
} 

// --------------------------------------

// My Iterative Solution : 

int binarySearch(vector<int> nums,int low,int high,int target)
{
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(nums[mid] == target)
            return mid;
        if(nums[mid]>=nums[low])
        {
            if(nums[low]<=target && nums[mid]>=target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if(nums[mid]<=target && nums[high]>=target)
                low = mid + 1;
            else
                high = mid - 1;   
        }
    }
    return -1;
}
    
int search(vector<int>& nums, int target) 
{
    int n = (int)nums.size();
    int index = binarySearch(nums,0,n-1,target);
    return index;
}

/*

Complexity Analysis:

Time Complexity: O(log n).
1. Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
2. Space Complexity: O(1). As no extra space is required.

*/
