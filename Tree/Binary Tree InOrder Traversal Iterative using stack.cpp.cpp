// Binary Tree InOrder Traversal Iterative using stack.cpp

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	if(root == NULL){
		return result;
	}
	stack<TreeNode *> st;
	TreeNode *currentNode = root;
	while(currentNode != NULL || (!st.empty())){
		while(currentNode != NULL){
			st.push(currentNode);
			currentNode = currentNode -> left;
		}
		currentNode = st.top();
		st.pop();
		result.emplace_back(currentNode->val);
		currentNode = currentNode->right;
	}
	return result;
}
