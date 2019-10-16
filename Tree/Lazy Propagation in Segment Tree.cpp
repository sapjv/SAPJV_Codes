/*


	### Lazy Propagation – An optimization to make range updates faster ###

Problem Link :  https://www.spoj.com/problems/HORRIBLE/    ( must check my first accepted solution )

Useful Video Links :  
1. https://www.youtube.com/watch?v=xuoQdt5pHj0
2. https://www.youtube.com/watch?v=CN0N1ddJ9hA  ( seems useful, but i haven't watched it )

Useful Link : https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/


When there are many updates and updates are done on a range, we can postpone some 
updates (avoid recursive calls in update) and do those updates only when required.

Please remember that a node in segment tree stores or represents result of a query
for a range of indexes. And if this node’s range lies within the update operation
range, then all descendants of the node must also be updated. For example consider
the node with value 27 in above diagram ( open below image link ) 

	https://media.geeksforgeeks.org/wp-content/cdn-uploads/segment-tree1.png  

this node stores sum of values at indexes from 3 to 5. If our update query is for 
range 2 to 5, then we need to update this node and all descendants of this node. 
With Lazy propagation, we update only node with value 27 and postpone updates to 
its children by storing this update information in separate nodes called lazy nodes 
or values. We create an array lazy[] which represents lazy node. Size of lazy[] is 
same as array that represents segment tree, which is tree[] in below code.

The idea is to initialize all elements of lazy[] as 0. A value 0 in lazy[i] indicates 
that there are no pending updates on node i in segment tree. A non-zero value of 
lazy[i] means that this amount needs to be added to node i in segment tree before 
making any query to the node.

-------------------

Below is modified update method.

// To update segment tree for change in array values at array indexes from ul to ur

updateRange(us, ue)
Step 1) If current segment tree node has any pending update, then first add that pending update to current node.
Step 2) If current node's range lies completely in update query range.
		a) Update current node
		b) Postpone updates to children by setting lazy value for children nodes.
Step 3) If current node's range overlaps with update range, follow the same approach as above simple update.
		a) Recur for left and right children.
		b) Update current node using results of left and right calls.

-------------------

Question :  Is there any change in Query Function also?

Answer : Since we have changed update to postpone its operations, there may be problems if a query
		is made to a node that is yet to be updated. So we need to update our query method also. 
		The getSum() first checks if there is a pending update and if there is, then updates the node. 

-------------------

HackerEarth Notes : Updating an interval ( Lazy Propagation ):

Sometimes problems will ask you to update an interval from l to r, instead of a single element. 

Now, Let's be Lazy i.e., do work only when needed. How ? When we need to update an interval, we will update 
a node and mark its child that it needs to be updated and update it when needed. For this we need an 
array lazy[] of the same size as that of segment tree. Initially all the elements of the lazy[] array 
will be 0 representing that there is no pending update. If there is non-zero element lazy[k] then this 
element needs to update node k in the segment tree before making any query operation.


To update an interval we will keep 3 things in mind :

1. If current segment tree node has any pending update, then first add that pending update to current node.
2. If the interval represented by current node lies completely in the interval to update, then update the 
   current node and update the lazy[] array for children nodes.
3. If the interval represented by current node overlaps with the interval to update, then update the nodes 
   as the earlier update function.
   
Since we have changed the update function to postpone the update operation, we will have to change the query 
function also. The only change we need to make is to check if there is any pending update operation on that 
node. If there is a pending update operation, first update the node and then work same as the earlier query 
function.

----------------

Time Complexity : Queries can be answered in O(logN) time. Also, Updates can be made lazily by storing the information 
				  at parent and propagating only when required. Hence, the complexity of an update is also O(logN).

----------------

Below code is of the “Sum of given Range” problem to explain Lazy propagation :

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define M 100001
 
lli segTree[4*M] = {0};
lli lazy[4*M] = {0};
lli a[M] = {0};
lli n;


/*
	index -> index of current node in segment tree 
    s and e -> Starting and ending indexes of elements in the segment tree for which current nodes stores sum. 
    ul and ur -> starting and ending indices of update query 
    val -> value which we need to add in the range ul to ur 
*/
void updateRange(int index,int s,int e,int ul,int ur,lli val)
{
	/*
		Make sure all propagation is done at index. And if not, then it is necessary
		to update segTree at index and then mark its children for lazy propagation.
											OR
		If lazy value is non-zero for current node of segment tree, then there are some pending updates. 
		So we need to make sure that the pending updates are done before making new updates. Because 
		this value may be used by parent after recursive calls (See last line of this function).		
	*/
	if(lazy[index]!=0)
	{
		// Making pending updates using value stored in lazy nodes 
		segTree[index] += (e-s+1)*lazy[index];
		
		// checking if it is not a leaf node because if it is leaf node 
		// then we cannot go further 
		if(s!=e)			 // if not a leaf node
		{
			// We can postpone updating children because of no need of their new values now. 
            // Since we are not yet updating children of index, we need to set lazy flags for the children 
			lazy[2*index] += lazy[index];		        // Marking child as lazy
			lazy[2*index+1] += lazy[index];		        // Marking child as lazy
		}
		
		// Setting the lazy value for current node as 0 because it has been updated 
		lazy[index] = 0;
	}
	
	// no overlap condition ( out of range )
	if(s>e || s>ur || e<ul)
	return;
	
	// total overlap condition ( Current segment is fully in range )
	if(s>=ul && e<=ur)
	{
		segTree[index] += (e-s+1)*val;			// Adding the val to current node 
		
		if(s!=e)		// same logic for checking leaf node or not 
		{
			// Rather than updating the segment tree itelf, this is where we store values in lazy nodes.  
            // Since we don't need these updated values now. So, we postpone updates by storing values in lazy[] 
			lazy[2*index] += val;
			lazy[2*index+1] += val;
		}
		return;
	}
	
	// otherwise partial overlap, so look both left and right.
	lli mid = (s+e)>>1;
	
	updateRange(2*index,s,mid,ul,ur,val);
	updateRange(2*index+1,mid+1,e,ul,ur,val);
	
	lli left = segTree[2*index];
	lli right = segTree[2*index+1];
	
	segTree[index] = left + right;			// And using the result of children calls to update current node 
}

/*

	A recursive function to get the sum of values in given range of the array. 
	The following are parameters for this function :
    index : Index of current node in the segment tree. Initially 0 is passed as root is always at index 0 
    s & e : Starting and ending indexes of the segment represented by current node, i.e., segTree[index] 
    ql & qr : Starting and ending indices of query range 

*/
lli getSum(int index,int s,int e,int ql,int qr)			// query()
{	
	/* 
		Make sure all propagation is done at index. And if not, then it is necessary
	 	to update segTree at index and then mark its children for lazy propagation
													OR
		If lazy flag is set for current node of segment tree, then there are some pending updates. So 
		we need to make sure that the pending updates are done before processing the sub sum query. 
	*/
	if(lazy[index]!=0)
	{
		// Making pending updates to this node. Note that this node represents sum of elements in 
		// a[s..e] and all these elements must be increased by lazy[index]
		segTree[index] += (e-s+1)*lazy[index];
		
		
		if(s!=e)			// if not a leaf node
		{
			// Since we are not yet updating children of index, we need to set lazy values for the children 
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		
		// Setting the lazy value for current node as 0 because it has been updated 
		lazy[index] = 0;
	}
	
	// no overlap condition
	if(s>e || s>qr || e<ql)
	return 0;
	
	// At this point we are sure that pending lazy updates are done for current node. So we can return value.  
    
	// total overlap
	if(s>=ql && e<=qr)
	return segTree[index];
	
	// Otherwise partial overlap, so look both left and right.
	lli mid = (s+e)>>1;
	
	lli left = getSum(2*index,s,mid,ql,qr);
	lli right = getSum(2*index+1,mid+1,e,ql,qr);
	
	return left + right;
}

void buildTree(int index,int s,int e)
{
	if(s>e)
	return;
	
	if(s==e)
	{
		segTree[index] = a[s];
		return;
	}
	
	lli mid = (s+e)>>1;
	
	buildTree(2*index,s,mid);
	buildTree(2*index+1,mid+1,e);
	
	lli left = segTree[2*index];
	lli right = segTree[2*index+1];
	
	segTree[index] = left + right;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
	
    cin>>n;
    	
	buildTree(1,0,n-1);
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++)
	{
		int type;
		cin>>type;
		
		if(type==0)
		{
			lli ul,ur,val;
			cin>>ul>>ur>>val;
			ul--;ur--;
			updateRange(1,0,n-1,ul,ur,val);
		}
		else
		{
			int ql,qr;
			cin>>ql>>qr;
			ql--;qr--;
			lli ans = getSum(1,0,n-1,ql,qr); 
			cout<<ans<<"\n";
		}
	} 	
}    
