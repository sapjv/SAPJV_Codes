/*

	####    0/1 Knapsack Problem using Dynamic Programming   ####				
				
 Problem Link :  https://www.spoj.com/problems/KNAPSACK/        ( below code is of this problem )
 
 Useful Links : 
 
 1.  https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 2.  https://medium.com/@fabianterh/how-to-solve-the-knapsack-problem-with-dynamic-programming-eb88c706d3cf
 3.  https://www.dyclassroom.com/dynamic-programming/0-1-knapsack-problem
 4.  http://www.es.ele.tue.nl/education/5MC10/Solutions/knapsack.pdf
 
 Useful Videos : 
 
 1. https://www.youtube.com/watch?v=nLmhmB6NzcM ( Must watch )
 2. https://www.youtube.com/watch?v=zRza99HPvkQ
 3. https://www.youtube.com/watch?v=8LusJS5-AGo

 Time Complexity: O(n*W) where n is the number of items and W is the capacity of knapsack
	
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
	int capacity,n;					// n is the number of weights and number of values
	
	cin>>capacity>>n;
	
	int weight[n],value[n];
	
	for(int i=0;i<n;i++)
		cin>>weight[i]>>value[i];
	
	int knapsack[n+1][capacity+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=capacity;w++)
		{
			if(i==0 || w==0)
				knapsack[i][w] = 0;
			
			else if(weight[i-1]<=w)
				knapsack[i][w] = max(value[i-1]+knapsack[i-1][w-weight[i-1]],knapsack[i-1][w]);
			
			else
				knapsack[i][w] = knapsack[i-1][w];
		}
	}
	
	cout<<knapsack[n][capacity]<<"\n";
}   
