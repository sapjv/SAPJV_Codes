
/*

Task :   https://practice.geeksforgeeks.org/problems/reach-a-given-score/0

	### Count number of ways to reach a given score in a game ###
	
Problem : Consider a game where a player can score 3 or 5 or 10 points in a move. Given 
a total score n, find number of ways to reach the given score.

Examples:

Input: n = 20
Output: 4
There are following 4 ways to reach 20
(10, 10)
(5, 5, 10)
(5, 5, 5, 5)
(3, 3, 3, 3, 3, 5)

Input: n = 13
Output: 2
There are following 2 ways to reach 13
(3, 5, 5)
(3, 10)

The idea is to create a table of size n+1 to store counts of all scores from 0 to n. 
For every possible move (3, 5 and 10), increment values in table.

Time Complexity: O(N)
Auxiliary Space: O(N)

*/

int main()
{

   	int n;
	cin>>n;

	// ways[i] will store count of solutions for value i.
	lli ways[n+1] = {0};
	
	// Base case (If given value is 0) 
	ways[0] = 1;

	// One by one consider given 3 moves and update the ways[] values after 
    	// the index greater than or equal to the value of the picked move
	for(int i=3;i<=n;i++)
		ways[i] += ways[i-3];

	for(int i=5;i<=n;i++)
		ways[i] += ways[i-5];

	for(int i=10;i<=n;i++)
		ways[i] += ways[i-10];

	cout<<ways[n]<<"\n";
}
