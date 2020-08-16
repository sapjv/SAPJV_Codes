
// Problem Link :  https://leetcode.com/problems/search-in-rotated-sorted-array/

/*

Description : 

Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the 
node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you 
should return NULL.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2     
     / \   
    1   3
In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) 
as [], not null.

*/

// ---------------------------------

// Solution 1 ( Recursive ) :   

/*

Important Note in this recursive solution : Whenever a function asked to return a pointer to the node, then don't use these two statements :

1. Node *Left = func(root->left);      // recursive call to left subtree
2. Node *Right = func(root->right);      // recursive call to right subtree

because after getting left and right subtree pointer, you will get stuck/confuse at last what to do with Left and Right subtree as you are 
asked to return the pointer to the node.

Instead always try to write and return recursvie call directly in the return statement. Calling recursive function and returning 
directly them will always return pointer to the node.

*/

TreeNode* searchBST(TreeNode* root, int val) 
{
        if(root==nullptr)
            return nullptr;
        if(root->val == val)
            return root;
        if(root->val>val)
            return searchBST(root->left,val);
        else 
            return searchBST(root->right,val);
}

// ..................................

// Solution 2 ( Iterative ) :

TreeNode* searchBST(TreeNode* root, int val) 
{
        if(root==nullptr)
            return nullptr;
        stack<TreeNode *> st;
        TreeNode *res = nullptr;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *current = st.top();
            st.pop();
            if(!current)
                continue;
            if(current->val == val)
            {
                res = current;
                break;
            }
            st.push(current->left);
            st.push(current->right);
        }
        
        return res;
}
