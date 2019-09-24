#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<lli> segTree(28);			// 4 * size of given array

inline void buildTree(lli a[],lli index,lli tree_start,lli tree_end)
{
	if(tree_start==tree_end)			// Base Case - Leaf Node
	{
		segTree[index]=a[tree_start];
		return;
	}
	
	lli mid = tree_start + (tree_end-tree_start)/2;
	
	buildTree(a,2*index,tree_start,mid);		// Left subtree
	buildTree(a,2*index+1,mid+1,tree_end);		// right subtree
	
	lli left = segTree[2*index];
	lli right = segTree[2*index+1];
	
	segTree[index] = min(left,right);
	
	return;
}

inline void update(lli index,lli tree_start,lli tree_end,lli pos,lli value)
{
	if(pos>tree_end || pos<tree_start)
	return;
	
	if(tree_start == tree_end)
	{
		segTree[index]=value;
		return;
	}
	
	lli mid = tree_start+(tree_end-tree_start)/2;
	
	update(2*index,tree_start,mid,pos,value);
	update(2*index+1,mid+1,tree_end,pos,value);
	
	lli left = segTree[2*index];
	lli right = segTree[2*index+1];
	
	segTree[index] = min(left,right);
	
	return;
}

inline lli query(lli index,lli query_start,lli query_end,lli tree_start,lli tree_end)
{
	// 3 cases : total ( complete ) overlap , no overlap , partial overlap
	
	// 1. total ( complete ) overlap
	if(query_start<=tree_start && query_end>=tree_end)
	return segTree[index];
	
	// 2. no overlap
	if(query_start>tree_end || query_end<tree_start)
	return INT_MAX;
	
	// 3. partial overlap
	lli mid = tree_start + (tree_end-tree_start)/2;
	
	lli leftAns = query(2*index,query_start,query_end,tree_start,mid);		// Left subtree
	lli rightAns = query(2*index+1,query_start,query_end,mid+1,tree_end);		// right subtree
	
	return min(leftAns,rightAns);
}

int main()
{
	
	lli a[] = {1,2,3,4,5,6,7};
	
	cout<<"Original Array : ";
	for(int i=0;i<7;i++)
	cout<<a[i]<<" ";
	
	cout<<"\n\n";
	
	//  0 is the starting index of array a[] , and 6 is the ending index of the array a[]
	buildTree(a,1,0,6);				// 1 is the starting index for the first node of segment tree
	
	lli q;
	cout<<"How many queries do you want to ask : ";
	cin>>q;
	
	for(int i=0;i<q;i++)
	{
		lli L,R;
		cout<<"\n\nEnter L : ";
		cin>>L;
		cout<<"\nEnter R : ";
		cin>>R;	
		cout<<"\nSmallest element between index "<<L<<" and "<<R<<" is : "<<query(1,L,R,0,6)<<"\n";
	}
	
	lli u;
	cout<<"How many values do you want to update : ";
	cin>>u;
	
	for(int i=0;i<u;i++)
	{
		lli ind,val;
		cout<<"\n\nEnter index number : ";
		cin>>ind;
		cout<<"\nEnter new value : ";
		cin>>val;	
		update(1,0,6,ind,val);
		cout<<"\nValue of index "<<ind<<" has been updated..\n";
	}
	
	string decision;
	cout<<"\nDo you want to perform some queries again ( yes / no ) : ";
	cin>>decision;
	
	if(decision=="yes")
	{
		cout<<"\nHow many queries do you want to ask : ";
		cin>>q;
		
		for(int i=0;i<q;i++)
		{
			lli L,R;
			cout<<"\n\nEnter L : ";
			cin>>L;
			cout<<"\nEnter R : ";
			cin>>R;	
			cout<<"\nSmallest element between index "<<L<<" and "<<R<<" is : "<<query(1,L,R,0,6)<<"\n";
		}
	}
	else
	cout<<"Thanks for playing with Segment Tree..";
}
