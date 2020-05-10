
/*

Problem Link :  https://www.codechef.com/problems/PALIN

Task :  For a given positive integer K of not more than 1000000 digits, write the value of the 
        smallest palindrome larger than K to output. Numbers are always displayed without leading 
        zeros. Output the smallest palindrome larger than K.
        
Example
Input:
2     // number of test cases
808
2133
Output:
818
2222

*/

// Solution : 

int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;

		int n = (int)s.size();
		
		string temp = s;

		for(int i=0;i<=(n/2);i++)
			s[n-i-1] = s[i];

		if(s>temp)
		{
			cout<<s<<"\n";
			continue;
		}

		bool done = false;
		for(int i=(n-1)/2;i>=0;i--)
		{
			if(s[i]!='9')
			{
				s[i]++;
				done = true;
				break;
			}
			else
				s[i] = '0';
		}

		for(int i=0;i<=(n/2);i++)
			s[n-i-1] = s[i];

		if(s[0] == '0')
		{
			s[0] = '1';
			s += "1";
		}

		cout<<s<<"\n";
	}	
}
