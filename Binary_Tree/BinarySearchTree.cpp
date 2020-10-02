/*
Class: BinarySearchTree
Purpose: It's a binary search tree
*/
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
	cursor = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
	delete root;
}

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

bool BinarySearchTree::isBalanced() {
	return checkBalance();
}

bool BinarySearchTree::checkBalance() {
	//uses AVL tree criteria for "close enough" balance
	//height not more than 1 greater on one side than the other
	return abs(calculateHeight(root->getLeft()) - calculateHeight(root->getRight())) < 2;
}

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

std::stringstream BinarySearchTree::dataPreOrder() {
	return PreOrder(root);
}

std::stringstream BinarySearchTree::PreOrder(Node* node) {
	//recursively returns contents of left subtree, then root, then right subtree
	std::stringstream buffer;
	buffer << node->getData() << "\n";
	if (node->getLeft() != nullptr) {
		buffer << PreOrder(node->getLeft()).rdbuf();
	}
	if (node->getRight() != nullptr) {
		buffer << PreOrder(node->getRight()).rdbuf();
	}
	return buffer;
}

std::stringstream BinarySearchTree::dataInOrder() {
	return InOrder(root);
}

std::stringstream BinarySearchTree::InOrder(Node* node) {
	//recursively returns contents of root, then left subtree, then right subtree
	std::stringstream buffer;
	if (node->getLeft() != nullptr) {
		buffer << InOrder(node->getLeft()).rdbuf();
	}
	buffer << node->getData() << "\n";
	if (node->getRight() != nullptr) {
		buffer << InOrder(node->getRight()).rdbuf();
	}
	return buffer;
}

Node* BinarySearchTree::getMax() {
	//returns maximum-value node
	cursor = root;
	while (cursor->getRight() != nullptr) {
		cursor = cursor->getRight();
	}
	return cursor;
}

Node* BinarySearchTree::getMin() {
	//returns minimum-value node
	cursor = root;
	while (cursor->getLeft() != nullptr) {
		cursor = cursor->getLeft();
	}
	return cursor;
}