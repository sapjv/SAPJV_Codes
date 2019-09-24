// Both recursive and iterative function have same time complexity : O(h) where h is height of tree. 

// Note :  the resursive solution requires O(h) extra space in function call stack for recursive function calls. We can avoid extra space using iterative solution.

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node(int value)
    {
        data=value;
        left=right=NULL;
    }
};

// iterative version
struct node *lca(node* root, int n1, int n2) 
{ 
    while (root != NULL) 
    { 
        if (root->data > n1 && root->data > n2) 
           root = root->left; 
  
        else if (root->data < n1 && root->data < n2) 
           root = root->right; 
  
        else break; 
    } 
    return root; 
} 

// Recursive Version

// struct node *lca(struct node* root, int n1, int n2) 
// { 
//     if (root == NULL) return NULL; 
  
//     // If both n1 and n2 are smaller than root, then LCA lies in left 
//     if (root->data > n1 && root->data > n2) 
//         return lca(root->left, n1, n2); 
  
//     // If both n1 and n2 are greater than root, then LCA lies in right 
//     if (root->data < n1 && root->data < n2) 
//         return lca(root->right, n1, n2); 
  
//     return root; 
// } 
    
int main()
{
    // node *root=new node(6);
    // root->left = new node(4);
    // root->right=new node(12);
    // root->left->left = new node(3);
    // root->left->right=new node(5);
    
    node *root               = new node(20); 
    root->left               = new node(8); 
    root->right              = new node(22); 
    root->left->left         = new node(4); 
    root->left->right        = new node(12); 
    root->left->right->left  = new node(10); 
    root->left->right->right = new node(14); 
    
    int n1 = 10, n2 = 14;
    node *res1=lca(root,n1,n2);
    cout<<"res1 = "<<res1->data<<"\n";
    
    n1 = 14, n2 = 8;
    node *res2=lca(root,n1,n2);
    cout<<"res2 = "<<res2->data<<"\n";
    
    n1 = 10, n2 = 22;
    node *res3=lca(root,n1,n2);
    cout<<"res3 = "<<res3->data<<"\n";
}

// Must Watch Another naive & easy solution :   https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

