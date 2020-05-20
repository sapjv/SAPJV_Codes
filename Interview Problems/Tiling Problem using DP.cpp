/*

Problem Link :  https://practice.geeksforgeeks.org/problems/number-of-ways/0

Task :  Given a tile of size 1 x 4, how many ways you can construct a grid of size N x 4.

-------------

Tutorial :  

Given a number n, count number of ways to fill a n x 4 grid using 1 x 4 tiles.Inline image 1

Examples:

Input : n = 1
Output : 1

Input : n = 2
Output : 1 ( We can only place both tiles horizontally )

Input : n = 3
Output : 1 ( We can only place all tiles horizontally )

Input : n = 4
Output : 2
The two ways are : 
1) Place all tiles horizontally 
2) Place all tiles vertically.

Input : n = 5
Output : 3
We can fill a 5 x 4 grid in following ways : 
1) Place all 5 tiles horizontally
2) Place first 4 vertically and 1 horizontally.
3) Place first 1 vertically and 4 horizontally.
 
This above problem is mainly an extension of this tiling problem ( https://www.geeksforgeeks.org/tiling-problem/ )

Explanation : Let “count(n)” be the count of ways to place tiles on a "n x n" grid, we 
              have following two ways to place first tile.

(a) If we place first tile horizontally, the problem reduces to “count(n-1)”
(b) If we place first tile vertically, then we must place 3 more tiles vertically. So the 
    problem reduces to “count(n-4)”

Therefore, count(n) can be written as below.

   count(n) = 1 if n = 1 or n = 2 or n = 3
   count(n) = count(n-1) + count(n-4) 

------------------------

Time Complexity : O(n)

C++ Solution :

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		lli ways[n+1];
		
		ways[0] = 0;
		ways[1] = 1;
		ways[2] = 1;
		ways[3] = 1;
		ways[4] = 2;

		for(int i=5;i<=n;i++)
			ways[i] = ways[i-1] + ways[i-4];

		cout<<ways[n]<<"\n";
	}	
}

// -----------------------------------------------------------------------

/*

Another tiling problem of size 2x1 and 2xN : 

Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given 
board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or 
vertically i.e., as 2 x 1 tile.

Examples:

Input n = 3
Output: 3
Explanation: We need 3 tiles to tile the board of size  2 x 3. 
We can tile the board using following ways :
1) Place all 3 tiles vertically. 
2) Place first tile vertically and remaining 2 tiles horizontally.
3) Place first 2 tiles horizontally and remaining tiles vertically

Input n = 4
Output: 5
Explanation:
For a 2 x 4 board, there are 5 ways
1) All 4 vertical
2) All 4 horizontal
3) First 2 vertical, remaining 2 horizontal
4) First 2 horizontal, remaining 2 vertical
5) Corner 2 vertical, middle 2 horizontal

Explanation :

Let “count(n)” be the count of ways to place tiles on a “2 x n” grid, we have following 
two ways to place first tile.

1) If we place first tile vertically, the problem reduces to “count(n-1)”
2) If we place first tile horizontally, we have to place second tile also horizontally. So the 
   problem reduces to “count(n-2)”

Therefore, count(n) can be written as below.

   count(n) = n if n = 1 or n = 2
   count(n) = count(n-1) + count(n-2) 
   
The above recurrence is nothing but Fibonacci Number expression. We can find n’th Fibonacci 
number in O(Log n) time using matrix exponentiation method.

*/

//-----------------------------------------------------------

/*

// Another tiling problem of size 1xM and NxM : 

Link :  https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/

Task :  Count the number of ways to tile the floor of size n x m using 1 x m size tiles

Given a floor of size n x m and tiles of size 1 x m. The problem is to count the number of 
ways to tile the given floor using 1 x m tiles. A tile can either be placed horizontally or 
vertically. Both n and m are positive integers and 2 < = m.

Examples:

Input : n = 2, m = 3
Output : 1
Only one combination to place two tiles of size 1 x 3 horizontally on the floor of size 2 x 3. 

Input :  n = 4, m = 4
Output : 2
1st combination: All tiles are placed horizontally
2nd combination: All tiles are placed vertically.

This problem is mainly a more generalized approach to the Tiling Problem.

Approach: For a given value of n and m, the number of ways to tile the floor can be 
          obtained from the following relation.

            {  1, 1 < = n < m }
 count(n) = {  2, n = m }
            { count(n-1) + count(n-m), m < n }
            
Time Complexity: O(n)
Auxiliary Space: O(n)

C++ Code : 

*/

// function to count the total number of ways 
int countWays(int n, int m) 
{ 
  
    // table to store values of subproblems 
    int ways[n + 1]; 
    ways[0] = 0; 
  
    // Fill the table upto value n 
    for (int i = 1; i <= n; i++) 
    { 
        // recurrence relation 
        if (i > m) 
            ways[i] = ways[i - 1] + ways[i - m]; 
  
        // base cases and for i = m = 1 
        else if (i < m || i == 1) 
            ways[i] = 1; 
  
        // i == m 
        else
            ways[i] = 2; 
    } 
 
    return ways[n];       // required number of ways 
} 
