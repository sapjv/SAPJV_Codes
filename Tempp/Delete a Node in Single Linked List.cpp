#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next;
	node(int x)
	{
		data = x;
		next=NULL;
	}
};

node *start;

node* deleteNth(node *head,int index)
{
	int count=1;
	if(index==1)
	{
		node *temp=start;
		start=start->next;
		free(temp);
	}
	else
	{
		node *prev=head,*start=head;
		while(count!=index)
		{
			prev=head;
			head=head->next;
			count++;
		}
		node *temp=head;
		prev->next = head->next;
		free(head);
	}
	return start;
}

void display(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int value;
			cin>>value;
			node *current;
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
		int index;
		cin>>index;
		start = deleteNth(start,index);
		display(start);
	}
}
