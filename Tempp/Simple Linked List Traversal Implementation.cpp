#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next;
	node(int x)
	{
		next=NULL;
		data=x;
	}
};

node *start,*first;

void display(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main()
{
	int n;
	cin>>n;
	start=NULL;
	for(int i=0;i<n;i++)
	{
		int value;
		cout<<"Enter value : ";
		cin>>value;
		if(i==0)
		{
			start = new node(value);
			first = start;
		}
		else
		{
			node *temp=new node(value);
			start->next=temp;
			start=temp;
		}
	}
	display(first);
	cout<<"\n";
}
