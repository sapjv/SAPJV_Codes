/*

	###  Minimum steps to reach end from start by performing multiplication and mod operations with array elements  ###
	
Useful Link : https://www.geeksforgeeks.org/minimum-steps-to-reach-end-from-start-by-performing-multiplication-and-mod-operations-with-array-elements/
	
Task : Given start, end and an array of N numbers. At each step, start is multiplied with any number in 
the array and then mod operation with 100000 is done to get the new start. The task is to find the minimum 
steps in which end can be achieved starting from start.

Examples:

Input: start = 3 end = 30 a[] = {2, 5, 7}
Output: 2
Step 1: 3*2 = 6 % 100000 = 6
Step 2: 6*5 = 30 % 100000 = 30

Input: start = 7 end = 66175 a[] = {3, 4, 65}
Output: 4
Step 1: 7*3 = 21 % 100000 = 21
Step 2: 21*3 = 6 % 100000 = 63
Step 3: 63*65 = 4095 % 100000 = 4095
Step 4: 4095*65 = 266175 % 100000 = 66175

-------------

Approach: Since in the above problem the modulus given is 100000, therefore the maximum number of states 
will be 105. All the states can be checked using simple BFS. Initialize an steps[] array with -1 which marks 
that the state has not been visited. steps[i] stores the number of steps taken to reach i from start. Initially 
push the start to the queue, then apply BFS. Pop the top element and check if it is equal to the end, if it 
is then print the steps[end]. If the element is not equal to the topmost element, then multiply top element 
with every element in the array and perform a mod operation. If the multiplied element state has not been 
visited previously, then push it into the queue. Initialize steps[pushed_element] by steps[top_element] + 1. Once 
all the states are visited, and the state cannot be reached by performing every possible multiplication, then 
print -1.

Below is the implementation of the above approach :

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define MOD 100000			// it is given
#define ep emplace_back


// bfs() Function that returns the minimum operations (steps) required
int bfs(int start,int end,int a[],int n)
{
	// array which stores the minimum steps to reach i from start 
	int steps[100001];			// number of possible states will be 100000
	
	// -1 indicated the state has not been visited 
	memset(steps,-1,sizeof(steps));
	
	queue<int> q;				// creating a queue for storing all possible states
	q.push(start % MOD);		// initially push the start % MOD
	steps[start] = 0;			// to reach start we require 0 steps 
	
	// till all states are visited 
	while(!q.empty())
	{
		// getting the current (topmost) element in the queue 
		int current = q.front();
		
		q.pop();		// pop the current (topmost) element
		
		// if the  current (topmost) element is end 
		if(current == end)
			return steps[end];
			
		// perform multiplication with all the given array elements 
		for(int i=0;i<n;i++)
		{
			// getting the new adjacent value of the current element
			int adj = (current*a[i]) % MOD ;
			
			// if the adjacent is not visited yet, then push it into the queue 
			if(steps[adj]==-1)
			{
				steps[adj] = steps[current] + 1;
				q.push(adj);
			}
		}
	}
	
	return -1;			// if not reached
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	int start,end,n;
	cin>>start>>end>>n;
	
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	int ans = bfs(start,end,a,n);
	
	cout<<"Minimum steps required = "<<ans<<"\n";
}


/*

input :
7 66175 3
3 4 65

Output :
Minimum steps required = 4

-------------

input :
3 30 3
2 5 7

Output :
Minimum steps required = 2

*/
