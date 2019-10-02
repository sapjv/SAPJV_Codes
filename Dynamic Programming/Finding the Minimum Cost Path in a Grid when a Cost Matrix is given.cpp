/*

		### Finding Minimum-Cost Path in a 2-D Matrix ( from HackerEarth ) ###
		
Video Link : https://www.youtube.com/watch?v=lBRtnuxg-gU ( Must watch )

Problem Statement : Given a cost matrix Cost[][] where Cost[i][j] denotes the Cost of visiting cell with 
coordinates (i,j), find a min-cost path to reach a cell (x,y) from cell (0,0) under the condition that 
you can only travel one step right or one step down. (We assume that all costs are positive integers).

Solution : It is very easy to note that if you reach a position (i,j) in the grid, you must have come from 
one cell higher, i.e. (i-1,j) or from one cell to your left , i.e. (i,j-1). This means that the cost of 
visiting cell (i,j) will come from the following recurrence relation:

				MinCost(i,j) = min( MinCost(i-1,j) , MinCost(i,j-1) ) + Cost[i][j]

The above statement means that to reach cell (i,j) wit minimum cost, first reach either cell(i-1,j) or 
cell (i,j-1) in as minimum cost as possible. From there, jump to cell (i,j). This brings us to the two 
important conditions which need to be satisfied for a dynamic programming problem:

Optimal Sub-structure:- Optimal solution to a problem involves optimal solutions to sub-problems.

Overlapping Sub-problems:- Subproblems once computed can be stored in a table for further use. This saves 
			   the time needed to compute the same sub-problems again and again.

The problem of finding the min-Cost Path is now almost solved. We now compute the values of the base 
cases: the topmost row and the leftmost column. For the topmost row, a cell can be reached only from 
the cell on the left of it. Assuming zero-based index,

MinCost(0,j) = MinCost(0,j-1) + Cost[0][j]
i.e. cost of reaching cell (0,j) = Cost of reaching cell (0,j-1) + Cost of visiting cell (0,j) 

Similarly,

MinCost(i,0) = MinCost(i-1,0) + Cost[i][0]
i.e. cost of reaching cell (i,0) = Cost of reaching cell (i-1,0) + Cost of visiting cell (i,0)

Other values can be computed from them. See the code below for more understanding.

Time Complexity : O( number of rows * number of columns ) => O(m*n)

*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int rows,columns;			// rows : number of rows , columns : number of columns
	
	rows = columns = 10;
	
	int Cost[rows][columns];			// this Cost matrix will be given in the problem
	
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cin>>Cost[i][j];		// Taking input of the cost of visiting cell (i,j)
		}
	}	
	
	int MinCost[rows][columns];				// declaring the minCost matrix
	
	MinCost[0][0] = Cost[0][0];
	
	for(int i=1;i<rows;i++)				// initializing first row of MinCost matrix
		MinCost[0][i] = MinCost[0][i-1] + Cost[0][i];
	
	for(int j=1;j<columns;j++)			// Initializing first column of MinCost Matrix
		MinCost[j][0] = MinCost[j-1][0] + Cost[j][0];
		
	//This bottom-up approach ensures that all the sub-problems needed have already been calculated.	
	for(int i=1;i<rows;i++)
	{
		for(int j=1;j<columns;j++)
		{
			// Now, we'll calculate the cost of visiting (i,j) using the recurrence relation discussed above
			MinCost[i][j] = min ( MinCost[i-1][j] , MinCost[i][j-1] ) + Cost[i][j];
		}
	}
	
	cout << " Minimum cost from (0,0) to (rows,columns) is : " << MinCost[rows-1][columns-1];
}


/*

Note : Another variant of this problem includes another direction of motion, i.e. one is also allowed to move 
diagonally lower from cell (i,j) to cell (i+1,j+1). This question can also be solved easily using a slight 
modification in the recurrence relation. To reach (i,j), we must first reach either (i-1,j), (i,j-1) or (i-1,j-1).

MinCost(i,j) = min( MinCost(i-1,j) , MinCost(i,j-1) , MinCost(i-1,j-1) ) + Cost[i][j]

*/

