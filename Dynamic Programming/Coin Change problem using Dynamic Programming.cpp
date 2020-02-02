/*

	### Coin Change problem using Dynamic Programming ###

Problem Link : https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0

Time Complexity: O(n*amount)		where n = no. of coins 

*/

#include<bits/stdc++.h>
using namespace std;

int coins[]={1,2,5,10,20,50,100,200,500,2000};		// possible coins based on INR

void change(int amount)
{
    int dp[10][amount+1];
    
    for(int i=0;i<=amount;i++)
	dp[0][i]=i;
    
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(j>=coins[i])
		dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
            else
		dp[i][j]=dp[i-1][j];
        }
    }
    
    // printing the denominations
    int i = 9 , j = amount;
    while(i>=0 && j>0)
    {
        if(dp[i][j] == dp[i-1][j])
	     i = i-1;
        else
        {
            cout << coins[i] << " ";
            j = j - coins[i];
        }
    }
}

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
		change(n);
		cout<<"\n";
	}
}
