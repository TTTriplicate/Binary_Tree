# Binary Search Tree

## Structure and Usage

Binary Search Trees(BST) are a data structure designed to hold data in a way that makes all searches follow a binary search pattern by default.  It is essentially a modified linked list: a series of nodes containing pointers to the next node.  The primary modification is that each node contains two pointers instead of just 1; a pointer to the next smaller object, and a pointer to the next larger pointer.  This is what makes the default search binary: in a perfectly balanced BST, each comparison leaves you with either the correct node, or half as many possible nodes to search.

BSTs can be used for any data that can be sorted by comparison, some sort of "less-than" and "greater-than".  It can insert faster than a sorted linked list, and search far faster, because it follows the binary search pattern for both insertion and searching.  If there is a way to mathematically calculate which item is needed, a random-access structure can be better.  For example, if you have a hashtable or hashmap, you just calculate the index and pull that, but it isn't always possible or practical.  It can also be a problem if the data is pre-sorted; the resulting tree will simply stretch one way, becoming a linked list in practice and losing any benefit to having made a BST in the first place.  This can be overcome with rebalancing algorithms, but that will, I suspect, be covered in a different write up.

## Insertion

```cpp
void BinarySearchTree::insert(int data) {
	Node* newNode = new Node(data);
	if (root == nullptr) {
		root = newNode;
	}
	else {
		cursor = root;
		while (true) {
			if (*(newNode) < *(cursor)) {
				//insert if less and left is null
				if (cursor->getLeft() == nullptr) {
					cursor->setLeft(newNode);
					break;
				}
				else {
					cursor = cursor->getLeft();
					continue;
				}
			}
			else {
				//insert if greater and right is null
				if (cursor->getRight() == nullptr) {
					cursor->setRight(newNode);
					break;
				}
				else {
					cursor = cursor->getRight();
					continue;
				}
			}
		}
	}
}
```

Inserting items in a BST follows a basic pattern.  The first item becomes the root of the tree, and later items are compared to that; items that compare as "less than" go to the left, "greater than" to the right.  This continues until the next node that would be checked is `NULL.` The new data is inserted in the tree at that point.

In the worst case, this will take $1 +\sum_{i=2}^n i(i-1)$ iterations through the loop per insertion, becoming exactly $O(n^2)$.  This case is when all data is being presented for insertion in sorted order, and will construct a linked list with each new insertion having to traverse to the end of the list.

In the best case, insertion follows the pattern of a binary search.  The first insertion goes to the first node, the next two to that node's pointers, and so on down the tree.  this can be expressed as $1 + \sum_{i=2}^n log_2(i)$, simplifying down to $\Omega(log_2(n))$.

The average case in a non-balancing tree will fall squarely between the two, requiring traversal of about half the tree on average, but potentially to an unbalanced side.  The formula can be expresses as $1 + \sum_{i=2}^n log_2(i)(i - 1)$.  This can be simplified to $Theta(nlog_2(n))$.

* $1 +\sum_{i=2}^n i(i-1) \sim O(n^2)$
* $\Omega(log_2(n))$
* $1 + \sum_{i=2}^n log_2(i)(i - 1) \sim \Theta(nlog_2(n))$

## Searching, Height, and Traversals

The purpose of a BST is to allow for a binary search pattern on a linked list structure.  By inserting items in the pattern that it does, all searches will at least superficially follow a binary search pattern.  The actual efficiency of the search will depend on how effectively the BST has been built; a worst case structure will result in a worst case search, and likewise best case.

The implementation for this assignment does not include an explicit search function, but the `getMin()`,  `getMax()` , and `calculateHeight()` methods follow the basic pattern.  the minimum and maximum methods are simpler than a search: the minimum will be the node farthest to the left, descending in a straight line from the root, and the maximum likewise to the right.  

### Height

Calculating the height requires a full search of every node of the tree to determine how many there are in the longest possible path:

```cpp
int BinarySearchTree::getHeight() {
    //returns the total height of the BST
	return calculateHeight(root);
}

int BinarySearchTree::calculateHeight(Node* node) {
	//recursively adds up the height of subtrees and returns the greatest plus the current height
	if (node == nullptr) {
		//empty node has height of 0
		return 0;
	}
	else if (node->getLeft() == nullptr && node->getRight() == nullptr) {
		//height at node is 1 if there are no deeper subtrees
		return 1;
	}
	else {
		//height is 1 for current node, plus height of tallest subtree
		int leftHeight = calculateHeight(node->getLeft());
		int rightHeight = calculateHeight(node->getRight());
		return  1 + max(leftHeight, rightHeight);
	}
}

int BinarySearchTree::max(int a, int b) {
	//helper function to return max of 2 integers
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}
```

For each node starting at the root, its height is equal to 1 if it is not null, plus the height of either its left or right subtree, whichever is greater.  This means that the function continues to recurse down the tree until every node has been visited, and then the returned values are summed up.  This must, by necessity, reach every node in the tree, and therefore always takes $O(n)$ time.

This is also used as a subroutine to check the balance of the tree.  A tree is balanced if its subtrees are equal, or "close enough" for certain implementations.  I decided to go with a close enough implementation, where the trees is considered balanced as long as the subtrees do not have a difference in depth greater than one level.

```cpp
bool BinarySearchTree::checkBalance() {
	//uses AVL tree criteria for "close enough" balance
	//height not more than 1 greater on one side than the other
	return abs(calculateHeight(root->getLeft()) - calculateHeight(root->getRight())) < 2;
}
```

This follows the same pattern as calculating the height of the tree, and will always take $O(n)$ time.

### Traversals

There are three separate traversal patterns within this BST implementation: In-Order, Pre-Order, and Post-Order.  The use case for the traversals is very different, but they all meet the same complexity criteria.  I will go over Post-Order as my basis for analysis, recognizing that the other two are roughly the same, they just order the returned data differently.

```cpp
std::stringstream BinarySearchTree::dataPostOrder() {
	return PostOrder(root);
}

std::stringstream BinarySearchTree::PostOrder(Node* node) {
	//recursively returns contents of left subtree, then right subtree, then root
	std::stringstream buffer;

	if (node->getLeft() != nullptr) {
		buffer << PostOrder(node->getLeft()).rdbuf();
	}
	if (node->getRight() != nullptr) {
		buffer << PostOrder(node->getRight()).rdbuf();
	}
	buffer << node->getData() << "\n";
	return buffer;
}
```

At each level, a `std::stringstream` object is created to catch the data as it is pulled from the nodes.  Post-Order gets all the data to the left of the starting node first, then from the right, and finally adds the data from the current node, which is returned to the previous call.  By the end of the recursion, it will contain the entire left subtree left to right, bottom to top; the entire right subtree left to right, bottom to top; and the final piece is the root.  Just like the function to calculate the height, this requires the algorithm to visit every single node, making traversals always run in $O(n)$ time.