
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

/*

