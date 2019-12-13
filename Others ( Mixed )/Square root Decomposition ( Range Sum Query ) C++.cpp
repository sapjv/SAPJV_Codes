/*

		### Square root Decomposition ( Range Sum Query ) ###
		
Sqrt (or Square Root) Decomposition Technique is one of the most common query optimization technique used by 
competitive programmers. This technique helps us to reduce Time Complexity by a factor of sqrt(n).

The key concept of this technique is to decompose given array into small chunks specifically of size sqrt(n).

Let’s say we have an array of n elements and we decompose this array into small chunks of size sqrt(n). We will 
be having exactly sqrt(n) such chunks provided that n is a perfect square. Therefore, now our array on n elements 
is decomposed into sqrt(n) blocks, where each block contains sqrt(n) elements (assuming size of array is perfect 
square).

Let’s consider these chunks or blocks as an individual array each of which contains sqrt(n) elements and you have 
computed your desired answer(according to your problem) individually for all the chunks. Now, you need to answer 
certain queries asking you the answer for the elements in range l to r(l and r are starting and ending indices of 
the array) in the original n sized array.

Sqrt Decomposition Trick : As we have already precomputed the answer for all individual chunks and now we need to 
answer the queries in range l to r. Now we can simply combine the answers of the chunks that lie in between the 
range l to r in the original array. So, if we see carefully here we are jumping sqrt(n) steps at a time instead 
of jumping 1 step at a time as done in naive approach.

----------------------------

Useful Link :

1. https://www.geeksforgeeks.org/sqrt-square-root-decomposition-technique-set-1-introduction/	
		
Useful Videos : 

1. https://youtu.be/yjHDwnONdI8  ( Part-1 )
2. https://youtu.be/AcvVlneAYZE  ( Part-2 )

----------------------------

Time Complexity: In the worst case our range can be 0 to n-1(where n is the size of array and assuming n to be a 
perfect square). In this case all the blocks are completely overlapped by our query range. Therefore,to answer 
this query we need to iterate over all the decomposed blocks for the array and we know that the number of 
blocks = sqrt(n). Hence, the complexity for this type of query will be O(sqrt(n)) in worst case.

Note : Let’s consider a query [l = 1 and r = n-2] (n is the size of the array and has a 0 based indexing). Therefore, 
for this query exactly ( sqrt(n) – 2 ) blocks will be completely overlapped where as the first and last block will be 
partially overlapped with just one element left outside the overlapping range. So, the completely overlapped blocks 
can be summed up in ( sqrt(n) – 2 ) ~ sqrt(n) iterations, whereas first and last block are needed to be traversed 
one by one separately. But as we know that the number of elements in each block is at max sqrt(n), to sum up last 
block individually we need to make, (sqrt(n)-1) ~ sqrt(n) iterations and same for the last block.

So, the overall Complexity = O(sqrt(n)) + O(sqrt(n)) + O(sqrt(n)) = O(3*sqrt(N)) = O(sqrt(n))


Update Queries(Point update) : In this query we simply find the block in which the given index lies, then subtract 
			       its previous value and add the new updated value as per the point update query.
 			       So, the Time Complexity for point update is : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

#define n 10
#define root_n (int)sqrt(n)

int arr[n];
int blocks[root_n+1];				// root_n = 3
	
void buildBlocks()
{
	int block_id = -1;
	for(int i=0;i<n;i++)
	{
		if(i%root_n == 0)
			block_id++;
		blocks[block_id] += arr[i];
	}
}

void update(int index,int new_value)
{
	int block_id = index/root_n;
	blocks[block_id] += (new_value - arr[index]);
	arr[index] = new_value;
}

int query(int L,int R)
{
	int sum = 0;
	
	// left part ( left partial block )
	while(L<R && L!=0 && (L%root_n!=0))
	{
		sum += arr[L];
		L++;
	}
	
	// sum of middle (complete ) blocks
	while(L+root_n<=R)
	{
		int block_id = L/root_n;
		sum += blocks[block_id];
		L += root_n;
	}
	
	// right part ( right partial block )
	while(L<=R)
	{
		sum += arr[L];
		L++;
	}
	
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt","rt",stdin);
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	buildBlocks();
	
	int l,r;
	cin>>l>>r;
	int ans = query(l,r);
	cout<<"ans = "<<ans<<"\n";
	
	int pos,value;
	cin>>pos>>value;
	update(pos,value);
	
	cin>>l>>r;
	ans = query(l,r);
	cout<<"ans = "<<ans<<"\n";
}

/*

input : 
1 3 5 2 7 6 3 1 4 8
2 8
2 15
2 8

Output :
ans = 28
ans = 38

*/
