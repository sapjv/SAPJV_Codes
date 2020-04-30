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

node *start,*current;

void display(node *head,int index)
{
	int count=1;
	while(count!=index)
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
		int n,index;
		cin>>n>>index;
		start=NULL;
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
		display(start,index);
	}
}
