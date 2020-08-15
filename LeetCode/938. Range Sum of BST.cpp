// Question Link :  https://leetcode.com/problems/range-sum-of-bst/

// Question Description :

/*

Given the root node of a binary search tree, return the sum of values of all nodes with value 
between L and R (inclusive). Note that the binary search tree is guaranteed to have unique values.

Example 1:
Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32

Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

---------------------------------

Intuition and Algorithm :  We traverse the tree using Inorder Traversal. If current_node->val falls outside the 
range [L, R], (for example current_node->val < L), then we know that only the right branch could have nodes with 
value inside [L, R].

*/

// Recursive Implementation :

class Solution {
public:
    
    long int ans  = 0;
    void inOrder(TreeNode* root,int L,int R)
    {
        if(root == nullptr)
            return;
        
        if(root->val>L)
            inOrder(root->left,L,R);
        
        int x = root->val;
        if(x>=L && x<=R)
            ans += x;
        
        if(root->val<R)
            inOrder(root->right,L,R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        inOrder(root,L,R);
        return ans;
    }
};

// Iterative Implementation :

class Solution {
public:
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        stack<TreeNode *> st;
        st.push(root);
        long int ans = 0;
        while(!st.empty())
        {
            TreeNode *current = st.top();
            st.pop();
            if(!current)
                continue;
            if(current->val>=L && current->val<=R)
                ans += current->val;
            if(current->val>L)
                st.push(current->left);
            if(current->val<R)
                st.push(current->right);
        }
        return ans;
    }
};


/*

Complexity Analysis : 

Time Complexity: O(N), where N is the number of nodes in the tree.
Space Complexity: O(H), where H is the height of the tree.

*/
