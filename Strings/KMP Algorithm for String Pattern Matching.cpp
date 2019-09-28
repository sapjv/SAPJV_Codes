/*

Given 2 strings (pattern) and (text), find the number of occurrences of pattern in text.

Question Link :  https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/problem-to-be-linked-with-kmp-tutorial-1/description/

Time Complexity : The time complexity of KMP algorithm is O(m+n) => O(n) in the worst case. 
				  ( Here m = size of pattern , n = size of text )

*/

#include<bits/stdc++.h>
using namespace std;

// Creating lps[] that will hold the longest prefix suffix values for pattern 
int lps[9];			// lps[m] : Here 9 is the size of pattern ( lps array will be of size pattern.size() )

// Preprocessing the pattern (calculating lps[] array). Filling lps[] for given pattern pattern[0..m-1] 
inline void computeLPS(string text,string pattern,int m)
{
	int len = 0;		// length of the previous longest prefix suffix 
	
	lps[0] = 0;			// lps[0] is always 0 
	
	int j = 1;
	while(j < m)			// the loop calculates lps[j] for j = 1 to m-1 
	{
		if(pattern[j]==pattern[len])
		{
			len++;
			lps[j] = len;
			j++;
		}
		else			 // (pat[j] != pat[len]) 
		{
			if(len!=0)			// Also, note that we do not increment j here 
				len = lps[len-1];
			else			 // if (len == 0) 
			{
				lps[j] = 0;
				j++;
			}
		}
	}
}

inline void KMP(string text,string pattern)
{
	int n = (int)text.size();
	int m = (int)pattern.size();
	
	computeLPS(text,pattern,m);
	
	int i = 0 , j = 0;		// i for the indices of txt[] , j for the indices of pattern
	while(i<n)
	{
		if(pattern[j]==text[i])
		{
			i++;
			j++;
		}
		
		if(j==m)
		{
			cout<<"\nPattern found at index "<<(i-j);
			j = lps[j-1];
		}
		else if(i<n && pattern[j]!=text[i])			// mismatch after j matches 
		{
			if(j!=0)			// Do not match lps[0..lps[j-1]] characters, they will match anyway 
				j = lps[j-1];
			else
				i++;
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string text1 = "ABABDABACDABABCABAB";
	string pattern1 = "ABAB";
	
	KMP(text1,pattern1);
	
	cout<<"\n\n";
	
	string text2 = "AACAACACACAAACAAAA";
	string pattern2 = "ACA";
	
	KMP(text2,pattern2);
	
}


/*

Output : 

Pattern found at index 0
Pattern found at index 10
Pattern found at index 15


Pattern found at index 1
Pattern found at index 4
Pattern found at index 6
Pattern found at index 8
Pattern found at index 12

*/
