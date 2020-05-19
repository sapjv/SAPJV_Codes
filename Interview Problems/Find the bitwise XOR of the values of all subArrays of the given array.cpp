/*

Problem Link :  https://practice.geeksforgeeks.org/problems/game-of-xor/0

Task :  You are given an array A[] of size N. Now, we call the value of an array 
        the bit-wise XOR of all elements it contains. For example, the value of 
        the array [1,2,3] = 1^2^3. Now, Your task is to find the bit-wise XOR of 
        the values of all sub arrays of array A. 

Tutorial :  https://www.geeksforgeeks.org/xor-subarray-xors-set-2/

Example:

Input: A[] = {1,2,3} 
Output: 2
xor[1] = 1, 
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3

Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2

C++ Solution ( O(n) time ) :  Please understand below solution using pen and paper with example

*/


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
		lli n;
		cin>>n;

		vector<int> v(n+1);
		for(int i=1;i<=n;i++)
			cin>>v[i];

	        // if n is even, then xor of the elements of all the subarrays will 
                // be 0 ( bcoz all elements will appear even number of times ) 
		if(n%2==0) 
			cout<<"0\n";
		else
		{
			lli res = 0;
      
		        // taking xor of all alternate elements ( bcoz only alternate index
		        // elements ( 1,3,5,7... indices elements ) will appear odd times )
			for(int i=1;i<=n;i+=2)  
				res ^= v[i];
        
			cout<<res<<"\n";
		}
	}	
}
