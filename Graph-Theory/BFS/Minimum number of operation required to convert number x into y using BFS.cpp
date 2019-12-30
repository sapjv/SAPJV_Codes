/*

	###  Minimum number of operation required to convert number x into y using BFS  ###
	
Useful Link :  https://www.geeksforgeeks.org/minimum-number-operation-required-convert-number-x-y/

Problem Link :  https://codeforces.com/contest/520/problem/B  ( solved )
	
Task : Given a initial number x and two operations which are given below:

	1. Multiply number by 2.
	2. Subtract 1 from the number.

The task is to find out minimum number of operation required to convert number x into y using only 
above two operations. We can apply these operations any number of times.

Constraints:
1 <= x, y <= 10000

------------------

Example:

Input : x = 4, y = 7
Output : 2
We can transform x into y using following two operations.
1. 4*2  = 8
2. 8-1  = 7

Input  : x = 2, y = 5
Output : 4
We can transform x into y using following four operations.
1. 2*2  = 4
2. 4-1   = 3
3. 3*2  = 6
4. 6-1   = 5

Note that other sequences of two operations would take more operations.

-------------------

Approach : The idea is to use BFS for this. We run a BFS and create nodes by multiplying with 2 and 
subtracting by 1, thus we can obtain all possible numbers reachable from starting number.

Important Points :

1) When we subtract 1 from a number and if it becomes < 0 i.e. Negative then there is no reason to create 
next node from it (As per input constraints, numbers x and y are positive).

2) Also, if we have already created a number then there is no reason to create it again. i.e. we maintain 
a visited array.

*/



#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define M 10000
#define ep emplace_back

typedef pair<lli,lli> P;

// Returns minimum number of operations needed to convert x into y using BFS
lli bfs(lli x,lli y)
{
	// To keep track of visited numbers in BFS. 
	set<lli> visited;
	queue<P> q; 		// Create a queue 
	
	q.push(make_pair(x,0));			// pushing x into queue
	
	// Do BFS starting from x
	while(!q.empty())
	{
		auto top = q.front();		// Remove an item from queue
		q.pop();
		
		lli current = top.first;
		lli steps = top.second;
		
		// Mark popped number as visited
		if(current<=10000)			// this condition is necessary to check for avoiding TLE
			visited.insert(current);
		else
			continue;
		
		// If the removed item is target number y, return its steps
		if(current == y)
			return steps;
		
		// If we can reach y in one more step 
		if(2*current==y || current-1==y)
			return steps+1;
		
		// Insert new adjacent of current if not visited already 
		if(visited.find(2*current)==visited.end())
			q.push(make_pair(2*current,steps+1));
		
		// Insert new adjacent of current if not visited already 
		if(current-1>=0 && visited.find(current-1)==visited.end())
			q.push(make_pair(current-1,steps+1));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	freopen("input.txt","rt",stdin);
	
	int x,y;
	cin>>x>>y;
	
	int ans = bfs(x,y);
	
	cout<<"Minimum number of operation required to convert number "<<x<<" into "<<y<<" : "<<"\n";
}
