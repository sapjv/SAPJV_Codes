/*

Problem Link :  https://practice.geeksforgeeks.org/problems/palindromic-array/0

Task :  You are given an array A of size N. Your task is to find the minimum number of 
        operations needed to convert the given array to 'Palindromic Array'.
        Palindromic Array: [23,15,23] is a ‘Palindromic Array’ but [2,0,1] is not.
        The only allowed operation is that you can merge two adjacent elements in the 
        array and replace them with their sum.

Tutorial :  https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

Time Complexity :  O(n)

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

		vector<int> v(n+1);
		for(int i=1;i<=n;i++)
			cin>>v[i];

		int ans = 0;
		int i = 1 , j = n;        // two pointers technique
		while(i<=j)
		{
			if(v[i]<v[j])
			{
				int first = v[i];
				int second = v[i+1];
				i++;
				v[i] = first + second;
				ans++;
			}
			else if(v[i]>v[j])
			{
				int first = v[j];
				int second = v[j-1];
				j--;
				v[j] = first + second;
				ans++;
			}
			else
			{
				i++;
				j--;
			}
		}

		cout<<ans<<"\n";
	}	
}
