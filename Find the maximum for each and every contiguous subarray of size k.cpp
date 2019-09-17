// This solution is taken from GeeksforGeeks after understanding the solution steps. 
// for detailed explanation, see this video :  https://www.youtube.com/watch?v=39grPZtywyQ
// Problem Link : https://www.spoj.com/problems/ARRAYSUB/
// My Priority Queue solution is giving TLE everytime. I don't know how to optimize my priority queue solution.

#include<bits/stdc++.h> 
using namespace std;
typedef long long int lli;

void printKMax(int arr[], int n, int k) 			// A Dequeue (Double ended queue) based method for printing maximum element of all subarrays of size k 
{ 
	// Create a Double Ended Queue, Qi that will store indexes of array elements. The queue will store indexes of useful elements in every window and it will 
	// maintain decreasing order of values from front to rear in Qi, i.e., arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order.
	deque<int> Qi(k); 

	for(int i=0;i<k;i++) 				/* Process first k (or first window) elements of array */
	{ 
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 					// For every element, the previous smaller elements are useless so remove them from Qi 
			Qi.pop_back(); 				// Remove from rear 
		Qi.push_back(i); 				// Add new element at rear of queue 
	} 

	for(int i=k;i<n;i++) 			// Process rest of the elements, i.e., from arr[k] to arr[n-1] 
	{ 	
		cout << arr[Qi.front()] << " "; 				// The element at the front of the queue is the largest element of previous window, so print it 

		while ((!Qi.empty()) && Qi.front() <= i-k) 			// Remove the elements which are out of this window 
			Qi.pop_front(); 				// Remove from front of queue 

		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 			// Remove all elements smaller than the currently being added element (remove useless elements) 
			Qi.pop_back(); 

		Qi.push_back(i); 					// Add current element at the rear of Qi 
	} 
	cout << arr[Qi.front()]; 			// Print the maximum element of last window 
} 

 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
 	int n;
 	cin>>n;
 	
 	int a[n];
 	for(int i=0;i<n;i++)
 	cin>>a[i];
 	
 	int k;
 	cin>>k;

	printKMax(a,n,k);

}   
