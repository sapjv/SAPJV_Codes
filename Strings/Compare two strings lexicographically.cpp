// The letter's case does not matter while comparision, So, we are converting both the strings to their lowercase

// Note :  the lexicographical order (also known as the "dictionary order" or "alphabetical order")

#include<bits/stdc++.h> 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	
 	string first;
 	cin>>first;
 	
 	string second;
 	cin>>second;
 	
 	string A = "" , B = "";
 	
 	for(int i=0;i<(int)first.size();i++)
 	{
 		A += tolower(first[i]);
 		B += tolower(second[i]);
	}
	
	int result = 0;					// If both the strings are equal,then print "0"	
	for(int i=0;i<(int)A.size();i++)
	{
		if(A[i]<B[i])			// If the first string is less than the second one, print "-1".
		{
			result = -1;
			break;
		}
		else if(A[i]>B[i])				// If the second string is less than the first one, print "1"
		{
			result = 1;
			break;
		}
	}
	cout<<result<<"\n";
}   
 
