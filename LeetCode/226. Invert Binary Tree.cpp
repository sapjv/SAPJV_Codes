
/*

Problem Link :  https://leetcode.com/problems/invert-binary-tree/

Problem Description :  Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

/*

Approach #1 (Recursive) :

Algorithm :  The inverse of an empty tree is the empty tree. The inverse of a tree with root r, and subtrees 
right and left, is a tree with root r, whose right subtree is the inverse of left, and whose left subtree is 
the inverse of right.

*/

// Solution :

TreeNode* invertTree(TreeNode* root) 
{    
	if(root == nullptr)
		return nullptr;
	
	TreeNode *Left = invertTree(root->left);
	TreeNode *Right = invertTree(root->right);
	
	root->left = Right;
	root->right = Left;
	
	return root;
}

/*

Complexity Analysis :  Since each node in the tree is visited only once, the time complexity is O(n), where n is the number
of nodes in the tree. We cannot do better than that, since at the very least we have to visit each node to invert it.

Because of recursion, O(h) function calls will be placed on the stack in the worst case, where h is the height of the tree. 
Because h belongs to O(n). Hence, the space complexity is O(n).

*/

// -------------------------------------------


// Approach #2 (Iterative) : ( Using a stack - this is my own solution )

TreeNode* invertTree(TreeNode* root) 
{
        if(root == nullptr)
            return nullptr;
        
        stack<TreeNode *> st;		// note that this stack is of (TreeNode *) type
        st.push(root);
        while(!st.empty())
        {
            TreeNode *current = st.top();
            st.pop();
            
            if(current == nullptr)
                continue;
            
            TreeNode *Left = current->left;
            TreeNode *Right = current->right;
            
            current->left = Right;
            current->right = Left;
            
            st.push(current->left);
            st.push(current->right);
        }
        
        return root;
}

// ------------------------

// Approach #3 (Iterative) : ( Using a queue - this is also my own solution )

// Note : In below solution, everything is similar like Approach2 usng stack. The only change is to 
// replace stack with queue. Just replaced stack with queue only.

 TreeNode* invertTree(TreeNode* root) 
 {
        if(root == nullptr)
            return nullptr;
        
        queue<TreeNode *> q;		// note that this queue is of (TreeNode *) type
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            
            if(current == nullptr)
                continue;
            
            TreeNode *Left = current->left;
            TreeNode *Right = current->right;
            
            current->left = Right;
            current->right = Left;
            
            q.push(current->left);
            q.push(current->right);
        }
        
        return root;
 }


/*

Complexity Analysis of Approach 2 and 3 : 

Since each node in the tree is visited / added to the stack and queue only once, the time complexity is O(n), where n is the 
number of nodes in the tree.

Space complexity is O(n), since in the worst case, the queue/stack will contain all nodes in one level of the binary tree. For 
a full binary tree, the leaf level has ⌈n/2⌉ = O(n) leaves.

*/
