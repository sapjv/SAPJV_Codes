/*

https://www.spoj.com/problems/FENTREE/

I have submitted two solutions for this problem : 

Solution 1 :  Using Fenwick Tree 
Solution 2 : Using Segment Tree ( below code )

This is Range Sum Ruery 

Note : When there is an update, the children say an index i and a value x , and we have to 
	   add x to a[i] (so the new value of a[i] will be a[i] + x ).

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
#define M 1000001
#define MOD 1000000007
#define ep emplace_back

lli n;
lli segTree[4*M];
lli a[M];


inline void buildTree(int index,int s,int e)
{
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
 
inline void update(int index,int s,int e,int pos,lli val)
{
	if(pos>e || pos<s)
	return;
	
	if(s==e)
	{
		segTree[index] += val;				// this is important
		return;
	}
	
	lli mid = (s+e)>>1;
	
	update(2*index,s,mid,pos,val);
	update(2*index+1,mid+1,e,pos,val);
	
	lli left = segTree[2*index];
	lli right = segTree[2*index+1];
	
	segTree[index] = left + right;	
}
 
inline lli query(int index,int qs,int qe,int ts,int te)
{
	if(qs<=ts && qe>=te)
	return segTree[index];
	
	if(qs>te || qe<ts)
	return 0;
	
	lli mid = (ts+te)>>1;
	
	lli left = query(2*index,qs,qe,ts,mid);
	lli right = query(2*index+1,qs,qe,mid+1,te);
	
	return left+right;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
// 	freopen("input.txt", "rt", stdin);
 	
	cin>>n;
	
 	for(int i=0;i<n;i++)
 	cin>>a[i];
 	
 	buildTree(1,0,n-1);
	
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		char ch;
		cin>>ch;
		
		if(ch=='q')
		{
			lli l,r;
			cin>>l>>r;
			l--;r--;
			lli ans = query(1,l,r,0,n-1);
			cout<<ans<<"\n";
		}
		else
		{
			lli pos,val;
			cin>>pos>>val;
			
			pos--;
			
			/*
				When there is an update, the children say an index i and a value x , and we have to 
		   		add x to a[i] (so the new value of a[i] will be a[i] + x ).
	   		*/
			
			update(1,0,n-1,pos,val);
		}
	}
}   
