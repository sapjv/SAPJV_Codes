/*

	### Construct Binary Tree From given PreOrder And Inorder Traversals ###
	
---------------
	
Question :  https://www.spoj.com/problems/TREEORD/  ( Check my accepted solution )

---------------

Useful Video :  ( Must watch both videos , both are required )

Exlanation :  https://www.youtube.com/watch?v=3aWagJkOZSg&list=PLrk5tgtnMN6QkNhdIiClZIhxJGwzCEVv9&index=2 
C++ Code :  https://www.youtube.com/watch?v=W9irlUOf6lI&list=PLrk5tgtnMN6QkNhdIiClZIhxJGwzCEVv9&index=3
 
----------------

Time Complexity : O(n*n) = O(n^2)
 
*/

struct node
{
	int data;
	node *left , *right;
	node(int value)
	{
		this->data = value;
		left = right = NULL;
	}
};

node* constructBinaryTree(int inOrder[],int preOrder[],int inStart,int inEnd,int preStart,int preEnd)
{
	if(inStart>inEnd)
		return NULL;
		
	int rootValue = preOrder[preStart];			// we know that the first value in preOrder is always root.
	
	int rootIndex = -1;
	for(int i=inStart;i<=inEnd;i++)
	{
		if(inOrder[i] == rootValue)
		{
			rootIndex = i;
			break;
		}
	}
	
	int leftInStart = inStart;
	int leftInEnd = rootIndex - 1;
	int leftPreStart = preStart + 1;
	int leftPreEnd = leftInEnd - leftInStart + leftPreStart;
	
	int rightInStart = rootIndex + 1;
	int rightInEnd = inEnd;
	int rightPreStart = leftPreEnd + 1;
	int rightPreEnd = preEnd;
	
	node* root = new node(rootValue);
	
	root->left = constructBinaryTree ( inOrder , preOrder , leftInStart , leftInEnd , leftPreStart , leftPreEnd );
	root->right = constructBinaryTree ( inOrder , preOrder , rightInStart , rightInEnd , rightPreStart , rightPreEnd );
	
	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	freopen("input.txt","rt",stdin);
	
	int n;			// no. of nodes
	cin>>n;
	
	int pre[n],in[n];			// Given preorder and inorder array
	
	for(int i=0;i<n;i++)
	cin>>pre[i];
	
	for(int i=0;i<n;i++)
	cin>>in[i];
	
	node *root = constructBinaryTree(in,pre,0,n-1,0,n-1);

}

