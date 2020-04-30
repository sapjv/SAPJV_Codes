#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};

node *start;

void getMiddle(node *head,int n)
{
	int mid=n/2;
	int count=0;
	while(count!=mid)
	{
		head=head->next;
		count++;
	}
	cout<<head->data<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		node *current;
		for(int i=0;i<n;i++)
		{
			int value;
			cin>>value;
			if(i==0)
			{
				current=new node(value);
				start=current;
			}
			else
			{
				node *temp=new node(value);
				current->next=temp;
				current=temp;
			}
		}
		getMiddle(start,n);
	}
}
