// Implementation of Binary Search Tree with three operations : insertion() , deletion() , treeTraversal

// Link : 	https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node(int value)
    {
    	this->data=value;
    	left = right = NULL;
	}
};
struct node* insert_in_BST(struct node* root, int x) 
{ 
    if(root == NULL) 
		return new node(x); 
  
    if (x < root->data) 
        root->left  = insert_in_BST(root->left,x); 
    else if (x > root->data) 
        root->right = insert_in_BST(root->right,x);    
  
    return root; 
}
struct node * minValueNode(struct node* root) 
{ 
    struct node* current = root; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 
struct node* deleteNode(struct node* root, int x) 
{ 
    if (root == NULL) return root; 
    if (x < root->data) 
        root->left = deleteNode(root->left, x); 
    else if (x > root->data) 
        root->right = deleteNode(root->right, x); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 
void preOrder(node *root)
{
	if(root == NULL) 
    	return;  
    cout << root->data << " "; 
    preOrder(root->left); 
    preOrder(root->right); 
}
void inOrder(node *root)
{
	if(root == NULL) 
    	return;  
    inOrder(root->left); 
    cout << root->data << " "; 
    inOrder(root->right); 
}
void postOrder(node *root)
{
	if(root == NULL) 
        return;  
    postOrder(root->left); 
    postOrder(root->right); 
    cout << root->data << " "; 
}

int main()
{
	struct node *root = NULL; 
    root = insert_in_BST(root, 20); 
	
    cout<<"\n\nHello , Welcome to Binary Search Tree Game : \n";
	while(true)
    {
    	cout<<"\n1. Insert a node in the binary search tree \n";
    	cout<<"\n2. Enter a node value to delete it from the binary search tree \n";
    	cout<<"\n3. Tree Traversal \n";
    	cout<<"\n4. Exit\n";
    	
    	cout<<"\nEnter your choice : ";
    	int choice;
    	cin>>choice;
    	
    	switch(choice)
    	{
    		case 1:
    			int x;
    			cout<<"\n\nEnter a value to insert a node at the end of the binary tree : ";
    			cin>>x;
    			insert_in_BST(root,x);
    			break;
    		case 2:
    			int y;
    			cout<<"\n\nEnter a node value to delete from the binary search tree : ";
    			cin>>y;
    			deleteNode(root,y);
    			break;
			case 3:
				cout<<"\n\nWhich Traversal do you want to see : ";
				cout<<"\n\t 1. Pre-Order Traversal \n\t 2. In-Order Traversal \n\t 3. Post-Order Traversal \n\n";
				int ch;
				cin>>ch;
				if(ch==1)
				{
					cout<<"\nPre-Order Traversal of the tree is : ";
					preOrder(root);
					cout<<"\n\n";
					break;
				}
				else if(ch==2)
				{
					cout<<"\nIn-Order Traversal of the tree is : ";
					inOrder(root);
					cout<<"\n\n";
					break;
				}
				else if(ch==3)
				{
					cout<<"\nPost-Order Traversal of the tree is : ";
					postOrder(root);
					cout<<"\n\n";
					break;
				}
				else
				{
					cout<<"Invalid choice..";
					break;
				}
			case 4: 
				exit(0);
			default: ;
    	}
	}
}
