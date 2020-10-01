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

* $O(n^2)$
* $\Omega(log_2(n))$
* $Theta(nlog_2(n))$

## Searching

The purpose of a BST is to allow for a binary search pattern on a linked list structure.  By inserting items in the pattern that it does, all searches will at least superficially follow a binary search pattern.  The actual efficiency of the search will depend on how effectively the BST has been built; a worst case structure will result in a worst case search, and likewise best case.