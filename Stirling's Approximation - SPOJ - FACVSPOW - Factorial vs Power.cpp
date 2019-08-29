//  Stirling's Formula for calculating log(n!).    Formula of log(n!) = (n*ln(n))-n+(ln(2*pi*n)/2) 

//  Question : https://www.spoj.com/problems/FACVSPOW/

//  Note : This Question needs more Optimization

//  https://en.wikipedia.org/wiki/Stirling%27s_approximation

/*
	Question : f(n) = n! and g(n) = a^n
	Solution : for  f(n)>g(n) , 
					n! > a^n
					ln(n!) > nln(a)			( After taking natural log to both the sides )
				OR,	ln(n!) / n > ln(a)			( Now, we can use the Stirling formula for calculating log(n!)

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define M 10000000			// Here, we can optimize our code by reducing the value of M
#define MOD 1000000007
#define ep emplace_back
#define pi 3.14159

vector<double> f;

double stirling(double n)
{
	double numerator = n*log(n) - n + ( log ( 2 * pi * n ) / 2.0 );				// This is Stirling's Formula for calculating log(n!)
	double res = numerator / n;	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

// 	freopen("input.txt", "rt", stdin);
 	
 	for(int i=1;i<=M;i++)
 	f.ep(stirling(i));
 	
 	int x;
 	cin>>x;
 	
 	for(int i=0;i<x;i++)
 	{
 		lli a;
 		cin>>a;
 		double rhs = log(a);
 		lli upper = upper_bound(f.begin(),f.end(),rhs)-f.begin();
 		cout<< upper+1 <<"\n";
	}
}   
