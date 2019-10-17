/*

		### Trie data Structure ###

---------------------------------------------------------------------------------

Related Problem : https://www.spoj.com/problems/ADAINDEX/ ( check my last accepted solution )

Also check out this link :  https://www.geeksforgeeks.org/auto-complete-feature-using-trie/


Useful video Links : 

1.  https://www.youtube.com/watch?v=AXjmTQ8LEoI
2.  https://www.youtube.com/watch?v=-urNrIAQnNo&t=5s
3.  https://www.youtube.com/watch?v=zIjfhVPRZCg


Trie visualization :   

1.  https://www.cs.usfca.edu/~galles/visualization/Trie.html
2.  https://people.ok.ubc.ca/ylucet/DS/Trie.html

---------------------------------------------------------------------------------

	Techiedelight Notes : 

Trie is a tree-based data structure, which is used for efficient reTrieval 
of a key in a large data-set of strings. There are several ways to represent tries, corresponding 
to different trade-offs between memory use and speed of the operations. The basic form is that of 
a linked set of nodes, where each node contains an array of child pointers, one for each symbol 
in the alphabet (so for the English alphabet, one would store 26 child pointers and for the alphabet 
of bytes, 256 pointers). 

This is simple but wasteful in terms of memory: using the alphabet of bytes (size 256) and four-byte 
pointers, each trie node requires a kilobyte of storage , and when there is little overlap in the 
strings’ prefixes, the number of required nodes is roughly the combined length of the stored strings. 
Also, the nodes near the bottom of the tree tend to have few children and there are many of them, so 
the structure wastes space storing null pointers.

The storage problem can be alleviated by an implementation where we use map to store children of a 
node. Now we allocate memory only for alphabets in use, and don’t waste space storing null pointers.

---------------------------------------------------------------------------------

	HackerEarth Notes : 

Strings can essentially be viewed as the most important and common topics for a variety of programming
problems. String processing has a variety of real world applications too, such as:

1. Search Engines
2. Genome Analysis
3. Data Analytics

All the content presented to us in textual form can be visualized as nothing but just strings.

Tries : Tries are an extremely special and useful data-structure that are based on the prefix of a 
string. They are used to represent the “Retrieval” of data and thus the name Trie.

Prefix : What is prefix : The prefix of a string is nothing but any n letters n<=|S| that can be considered 
beginning strictly from the starting of a string. For example , the word “abacaba” has the following 
prefixes:

a
ab
aba
abac
abaca
abacab

A Trie is a special data structure used to store strings that can be visualized like a graph. It 
consists of nodes and edges. Each node consists of at max 26 children and edges connect each parent 
node to its children. These 26 pointers are nothing but pointers for each of the 26 letters of the 
English alphabet A separate edge is maintained for every edge.

Strings are stored in a top to bottom manner on the basis of their prefix in a trie. All prefixes 
of length 1 are stored at until level 1, all prefixes of length 2 are sorted at until level 2 and 
so on.

For example , consider the following diagram :  https://he-s3.s3.amazonaws.com/media/uploads/fb14630.png

Now, one would be wondering why to use a data structure such as a trie for processing a single string? 
Actually, Tries are generally used on groups of strings, rather than a single string. When given 
multiple strings , we can solve a variety of problems based on them. For example, consider an English 
dictionary and a single string s, find the prefix of maximum length from the dictionary strings matching 
the string s. Solving this problem using a naive approach would require us to match the prefix of the 
given string with the prefix of every other word in the dictionary and note the maximum. The is an 
expensive process considering the amount of time it would take. Tries can solve this problem in much 
more efficient way.

Before processing each Query of the type where we need to search the length of the longest prefix, we 
first need to add all the existing words into the dictionary. A Trie consists of a special node called 
the root node. This node doesn't have any incoming edges. It only contains 26 outgoing edges for each 
letter in the alphabet and is the root of the Trie.

So, the insertion of any string into a Trie starts from the root node. All prefixes of length one are 
direct children of the root node. In addition, all prefixes of length 2 become children of the nodes 
existing at level one.

---------------------------------------------------------------------------------

	GeeksforGeeks Notes : 

Trie is an efficient information reTrieval data structure. Using Trie, search complexities can be brought 
to optimal limit (key length). If we store keys in binary search tree, a well balanced BST will need time 
proportional to M * log N, where M is maximum string length and N is number of keys in tree. Using Trie, 
we can search the key in O(M) time. However the penalty is on Trie storage requirements.

Every node of Trie consists of multiple branches. Each branch represents a possible character of keys. We 
need to mark the last node of every key as end of word node. A Trie node field isLeaf is used to 
distinguish the node as end of word node. 

Inserting a key into Trie is a simple approach. Every character of the input key is inserted as an individual 
Trie node. Note that the children is an array of pointers (or references) to next level trie nodes. The key 
character acts as an index into the array children. If the input key is new or an extension of the existing 
key, we need to construct non-existing nodes of the key, and mark end of the word for the last node. If the 
input key is a prefix of the existing key in Trie, we simply mark the last node of the key as the end of a 
word. The key length determines Trie depth.

Searching for a key is similar to insert operation, however, we only compare the characters and move down. 
The search can terminate due to the end of a string or lack of key in the trie. In the former case, if the 
isEndofWord field of the last node is true, then the key exists in the trie. In the second case, the search 
terminates without examining all the characters of the key, since the key is not present in the trie.


During delete operation we delete the key in bottom up manner using recursion. 
The following are possible conditions when deleting key from trie :

	1. Key may not be there in trie. Delete operation should not modify trie.
	
	2. Key present as unique key (no part of key contains another key (prefix), nor the key itself is 
	   prefix of another key in trie). Delete all the nodes.
	
	3. Key is prefix key of another long key in trie. Unmark the leaf node.
	
	4. Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key 
	   until first leaf node of longest prefix key.


Advantages of Trie Data Structure : Tries is a tree that stores strings. Maximum number of children 
of a node is equal to size of alphabet. Trie supports search, insert and delete operations in O(L) 
time where L is length of key.

Hashing:- In hashing, we convert key to a small value and the value is used to index data. Hashing 
supports search, insert and delete operations in O(L) time on average.

Self Balancing BST : The time complexity of search, insert and delete operations in a self-balancing 
Binary Search Tree (BST) (like Red-Black Tree, AVL Tree, Splay Tree, etc) is O(L Log n) where n is 
total number words and L is length of word. The advantage of Self balancing BSTs is that they maintain 
order which makes operations like minimum, maximum, closest (floor or ceiling) and k-th largest faster. 
Please refer Advantages of BST over Hash Table for details ( https://www.geeksforgeeks.org/advantages-of-bst-over-hash-table/ )


Why Trie? :- With Trie, we can insert and find strings in O(L) time where L represent the length of a 
single word. This is obviously faster than BST. This is also faster than Hashing because of the ways 
it is implemented. We do not need to compute any hash function. No collision handling is required (like 
we do in open addressing and separate chaining). Another advantage of Trie is, we can easily print all 
words in alphabetical order which is not easily possible with hashing. We can efficiently do prefix 
search (or auto-complete) with Trie.

Issues with Trie :- The main disadvantage of tries is that they need a lot of memory for storing the 
strings. For each node we have too many node pointers(equal to number of characters of the alphabet), 
if space is concerned, then Ternary Search Tree can be preferred for dictionary implementations. In 
Ternary Search Tree, the time complexity of search operation is O(h) where h is the height of the tree. 
Ternary Search Trees also supports other operations supported by Trie like prefix search, alphabetical 
order printing, and nearest neighbor search.

The final conclusion is regarding tries data structure is that they are faster but require huge memory 
for storing the strings.

-------------------

Time Complexity : Insert and search costs O(key_length), however the memory requirements of Trie is 
				  O(ALPHABET_SIZE * key_length * N) where N is number of keys in Trie. There are 
				  efficient representation of trie nodes (e.g. compressed trie, ternary search tree, etc.) 
				  to minimize memory requirements of trie. 

---------------------------------------------------------------------------------

Below is the memory efficient Trie Implementation in C++ using Map | Insert, Search and Delete

*/

#include<bits/stdc++.h>
using namespace std;

// A Trie node
struct trieNode
{
	bool isLeaf;			// true when node is a leaf node
	unordered_map<char,trieNode*> umap;			// each node stores a map to its child nodes
};

// Function that returns a new Trie node
trieNode* getNewTrieNode()
{
	trieNode* node = new trieNode;
	node->isLeaf = false;
	return node;
}

// Iterative function to insert a string in Trie.
void insert(trieNode* &root,string key)
{
	if(root == nullptr)
	root = getNewTrieNode();
	
	trieNode* current = root;			// start from root node
	
	for(int i=0;i<(int)key.size();i++)			// iterating to all characters of input string key
	{
		char ch = key[i];
		
		// create a new node if path doesn't exists
		if(current->umap.find(ch)==current->umap.end())
			current->umap[ch] = getNewTrieNode();
			
		current = current->umap[ch];			// go to next node
	}
	
	current->isLeaf = true;				// marking current node as leaf
}

// Iterative function to search a string in Trie. It returns true
// if the string is found in the Trie, else it returns false
bool searchKey(trieNode* root,string key)
{
	// return false if Trie is empty
	if(root == nullptr)
	return false;
	
	trieNode* current = root;
	
	for(int i=0;i<(int)key.size();i++)			// iterating to all characters of input string key
	{
		char ch = key[i];
		current = current->umap[ch];			// go to next node
		
		if(current == nullptr)
			return false;
	}
	
	// if current node is a leaf and we have reached the end of the string, return true
	return current->isLeaf;
}

// returns true if given node has any children
bool haveChildren(trieNode const* current)
{
	// Note : Don't use (current->umap).size() to check for children
	for(auto it:current->umap)
	{
		if(it.second!=nullptr)			// if string is invalid (reached end of path in Trie)
		return true;
	}	
	return false;
}

// Recursive function to delete a string in Trie.
bool deleteKey(trieNode* &current,string str,int index)
{
	// return if Trie is empty
	if(current == nullptr)
		return false;
	
	// if we have not reached the end of the string
	if(str[index])
	{
		// recur for the node corresponding to next character in the string and
		// if it returns true, delete current node (if it is non-leaf)
		bool res1 = deleteKey(current->umap[str[index]],str,index+1);
		bool res2 = (current->umap.find(str[index]))!=(current->umap.end());
		if(current!=nullptr && res1 && res1 && (current->isLeaf==false)) 
		{
			if(!haveChildren(current))
			{
				delete current;
				current = nullptr;
				return true;
			}
			else
			return false;
		}
	}
	
	// if we have reached the end of the string
	if(index==(int)str.size() && current->isLeaf)
	{
		// if current node is a leaf node and don't have any children
		if(!haveChildren(current))
		{
			delete current;			// delete current node
			current = nullptr;
			return true;			 // delete non-leaf parent nodes
		}
		
		// if current node is a leaf node and have children
		else
		{
			current->isLeaf = false;		// mark current node as non-leaf node (DON'T DELETE IT)
			return false;			// don't delete its parent nodes
		}
	}
	
	return false;
}

int main()
{
	trieNode *head = nullptr;

	insert(head, "hello");
	cout << searchKey(head, "hello") << " ";   	// print 1 ( present )

	insert(head, "helloworld");
	cout << searchKey(head, "helloworld") << " ";  // print 1

	cout << searchKey(head, "helll") << " ";   	// print 0 (Not present)

	insert(head, "hell");
	cout << searchKey(head, "hell") << " ";		// print 1

	insert(head, "h");
	cout << searchKey(head, "h") << endl;  		// print 1 + newline

	// here in deleteKey(), 0 ( third argument ) is necessary to pass because this is the 
	// starting index of any string
	deleteKey(head, "hello",0);
	cout << searchKey(head, "hello") << " ";   	// print 0 (hello deleted)
	cout << searchKey(head, "helloworld") << " ";  // print 1
	cout << searchKey(head, "hell") << endl;   	// print 1 + newline

	deleteKey(head, "h",0);
	cout << searchKey(head, "h") << " ";   		// print 0 (h deleted)
	cout << searchKey(head, "hell") << " ";		// print 1
	cout << searchKey(head, "helloworld") << endl; // print 1 + newline

	deleteKey(head, "helloworld",0);		
	cout << searchKey(head, "helloworld") << " ";  // print 0
	cout << searchKey(head, "hell") << " ";		// print 1

	deleteKey(head, "hell",0);
	cout << searchKey(head, "hell") << endl;   	// print 0 + newline

	if (head == nullptr)
		cout << "Trie empty!!\n";   			// Trie is empty now

	cout << searchKey(head, "hell");   			// print 0
}

/*

Output :

	1 1 0 1 1
	0 1 1
	0 1 1
	0 1 0
	Trie empty!!
	0

*/
