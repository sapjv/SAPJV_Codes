/*

Task :  Given a number N, find the number of binary strings of length N that contains 
        consecutive 1's in them.

Problem Link :  https://practice.geeksforgeeks.org/problems/trail-of-ones/0

Useful Link :

1. https://www.geeksforgeeks.org/count-strings-with-consecutive-1s/
2. https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

Useful Video Link :  

1. https://www.youtube.com/watch?v=a9-NtLIs1Kk
2. https://www.youtube.com/watch?v=Bq9lgqC1YwE

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lli fib[35];
	fib[0] = 0;
	fib[1] = 1;
	for(int i=2;i<35;i++)
		fib[i] = fib[i-1]+fib[i-2];

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		lli ans = (1<<n) - fib[n+2];        // (1<<n) means (int)pow(2,n)
		cout<<ans<<"\n";
	}
}
