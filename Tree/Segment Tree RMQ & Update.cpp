#include<bits/stdc++.h>
using namespace std;

/*
    st[] = segment tree
    ss = segment_tree_starting_index
    se = segment_tree_ending_index
    qs = query_starting_index
    qe = query_ending_index
    
    pos = Index of current node in the segment tree. Initially 1 is passed as root is always at index 1 
    
    diff = Value to be added to all nodes whose index will come in range ( Value will get updated )
*/
inline int RMQ(int a[],int st[],int ss, int se, int qs, int qe, int pos) 
{ 
    // If segment of this node is a part of given query range, then return the current node ( min of the segment ) 
    if (qs <= ss && qe >= se) 		    // Total Overlap ( we'll return the value of current node )
        return st[pos]; 
  
    //  If segment of this node is outside the given query range
    if (se < qs || ss > qe) 	// no Overlap ( we'll return a very large number )
        return INT_MAX;
        
    // partial overlap ( we'll  look into both the directions of the current node)
    // Means range of the current node is partially inside and partially outside the asked query range
    int mid = ss + (se - ss)/2; 		
    return min(RMQ(a,st,ss, mid, qs, qe, 2*pos), RMQ(a,st,mid+1, se, qs, qe, 2*pos+1)); 
} 

inline void Update(int a[],int st[],int ss,int se,int pos,int x,int diff)
{
  // if segment_tree_starting_index and segment_tree_ending_index becomes equal , 
  // then pos will also be equal to them and Update that value in segment tree
  // at pos
  if (ss == se)
  {
    a[x] += diff;
    st[pos] += diff;
    return;
  }
  
  int mid  = (ss+se)/2;
 
  if (ss <= x and x<=mid )      // If x is in the left child, recurse on the left child
    Update(a,st,ss,mid,2*pos,x,diff);
  else                      // If x is in the right child, recurse on the right child
    Update(a,st,mid+1,se,2*pos+1,x,diff);
 
  // current pos node will have the min of both of its children
  st[pos] = min(st[2*pos],st[2*pos+1]);
}

inline void buildTree(int a[],int st[],int ss, int se, int pos) 
{ 
    // If there is one element in array, store it in current node of segment tree and return 
    if (ss == se) 		
    { 
        st[pos] = a[ss]; 
        return; 
    } 
    
    // If there are more than one elements, then recur for left and right subtrees
    // and store the minimum of values in this node 
    int mid = (se + ss)/2;
    buildTree(a,st,ss, mid,pos*2);
    buildTree(a,st,mid+1, se,pos*2+1);
    st[pos] =  min(st[2*pos],st[2*pos+1]); 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    /*
        if input len(n) is pow of 2 then size of segment tree is 2*n - 1, otherwise
        size of segment tree is next (pow of 2 for n)*2 - 1.
    */
    int height_of_seg_tree = (int)ceil(log2(n));        //Height of segment tree
    int tree_size = 2*(int)pow(2,height_of_seg_tree)-1;    // Maximum size of segment tree is : 2*{2^Height}-1
    
    int segment_tree[tree_size];        // Allocating memory for the segment tree 
    
    buildTree(a,segment_tree,0,n-1,1);      // for constructing and filling the allocated memory of the segment tree 
    
    for(int i=0;i<q;i++)
    {
        char ch;
        cin>>ch;
        if(ch=='q')
        {
            int l,r;
            cin>>l>>r;
            int minimum = RMQ(a,segment_tree,0,n-1,l-1,r-1,1);
            cout<<minimum<<"\n";
        }
        else if(ch=='u')
        {
            int x,y;
            cin>>x>>y;
            Update(a,segment_tree,0,n-1,1,x-1,-a[x-1]+y);
        }
    }
}

