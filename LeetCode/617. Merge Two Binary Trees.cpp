
// Question Link :  https://leetcode.com/problems/merge-two-binary-trees/

/*

Approach #1 Using Recursion :

We can traverse both the given trees in a preorder fashion. At every step, we check if the current node 
exists(isn't null) for both the trees. If so, we add the values in the current nodes of both the trees 
and update the value in the current node of the first tree to reflect this sum obtained. At every step, 
we also call the original function mergeTrees() with the left children and then with the right children 
of the current nodes of the two trees. If at any step, one of these children happens to be null, we return 
the child of the other tree(representing the corresponding child subtree) to be added as a child subtree to 
the calling parent node in the first tree. At the end, the first tree will represent the required resultant
merged binary tree.

*/

// Solution 1a :

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
        if(t1 == nullptr)
            return t2;
        
        if(t2 == nullptr)
            return t1;
        
        t1->val += t2->val;
        
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        
        return t1;
}

// OR

// Solution 1b ( this is my own solution ) :

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
        if(t1)
        {
            if(t2)
            {
                t1->val += t2->val;
                t1->left = mergeTrees(t1->left,t2->left);
                t1->right = mergeTrees(t1->right,t2->right);
                return t1;
            }
            else
                return t1;
        }
        else
        {
            if(t2)
            {
                t1 = new TreeNode();
                t1->val += t2->val;
                t1->left = mergeTrees(t1->left,t2->left);
                t1->right = mergeTrees(t1->right,t2->right);
                return t1;
            }
            else
                return nullptr;
        }
        
        return t1;
}

/*

Complexity Analysis :

Time complexity : O(m). A total of m nodes need to be traversed. Here, m represents the minimum number of nodes 
from the two given trees.

Space complexity : O(m). The depth of the recursion tree can go upto m in the case of a skewed tree. In average 
case, depth will be O(logm).

*/

// -------------------------------------------------------------------

/*

Approach #2 Iterative Method :

Algorithm :  In the current approach, we again traverse the two trees, but this time we make use of a stack to do 
so instead of making use of recursion. Each entry in the stack stores data in the form [node_{tree1}, node_{tree2}]. 
Here, node_{tree1} and node_{tree2} are the nodes of the first tree and the second tree respectively.

We start off by pushing the root nodes of both the trees onto the stack. Then, at every step, we remove a node pair 
from the top of the stack. For every node pair removed, we add the values corresponding to the two nodes and update 
the value of the corresponding node in the first tree. Then, if the left child of the first tree exists, we push the 
left child(pair) of both the trees onto the stack. If the left child of the first tree doesn't exist, we append the 
left child(subtree) of the second tree to the current node of the first tree. We do the same for the right child pair 
as well.

If, at any step, both the current nodes are null, we continue with popping the next nodes from the stack.

*/

// Solution 2 :

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{        
        if(t1 == nullptr)
            return t2;
        
        stack< pair<TreeNode *,TreeNode *> > st;          // note this step ( we used * here, because we'll push pointers to both current nodes )
        
        st.push(make_pair(t1,t2));
        
        while(!st.empty())
        {
            TreeNode *t1 = st.top().first;
            TreeNode *t2 = st.top().second;
            
            st.pop();
            
            if(t1 == nullptr || t2 == nullptr)
                continue;
            
            t1->val += t2->val;
            
            if(t1->left == nullptr)
                t1->left = t2->left;
            else
                st.push(make_pair(t1->left,t2->left));
            
            if(t1->right == nullptr)
                t1->right = t2->right;
            else
                st.push(make_pair(t1->right,t2->right));
        }

        return t1;
}

/*

Complexity Analysis :

Time complexity : O(n). We traverse over a total of nn nodes. Here, n refers to the smaller of the number of 
nodes in the two trees.

Space complexity : O(n). The depth of stack can grow upto nn in case of a skewed tree.

*/
