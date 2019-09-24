#include<iostream>
using namespace std;
int BIT[1000], a[1000], n;			// initially all elements of BIT will be 0 by default

/*
   Start from index+1 if you updating index in original array. Keep adding this value 
   for next node till you reach outside range of tree
*/
void update(int x, int val)
{
	/*
	 To get next
	 1) 2's complement of get minus of index             // -x is the 2's compliment
	 2) AND this with index                              // x & -x 
	 3) Add it to index                            // x + ( x & -x )
	*/
      for(; x <= n; x += x&-x)
        BIT[x] += val;
}
int query(int x)		// Start from index+1 if you want prefix sum 0 to index. Keep adding value till you reach 0
{
	/*
	  To get parent
	  1) 2's complement to get minus of index              // -x is the 2's compliment
	  2) AND this with index                           // x & -x 
	  3) Subtract that from index                  // x - ( x & -x )
	*/

     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     scanf("%d", &n);
     for(int i = 1; i <= n; i++)
     {
           scanf("%d", &a[i]);
           update(i, a[i]);			// Creating tree is like updating Fenwick tree for every value in array
     }
     printf("sum of first 10 elements is %d\n", query(10));
     int q1 = query(7);
	 int q2 = query(1);
     printf("sum of all elements in range [2, 7] is %d\n", (q1-q2));
     return 0;
}
