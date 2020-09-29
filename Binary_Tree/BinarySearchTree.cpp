#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
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
	return abs(getHeight(root->getLeft()) - getHeight(root->getRight())) < 2;
}

int BinarySearchTree::getHeight(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	else if (node->getLeft() == nullptr && node->getRight() == nullptr) {
		return 1;
	}
	else {
		int leftHeight = getHeight(node->getLeft());
		int rightHeight = getHeight(node->getRight());
		return  1 + max(leftHeight, rightHeight);
	}
}

std::stringstream BinarySearchTree::dataPostOrder() {
	return PostOrder(root);
}

std::stringstream BinarySearchTree::PostOrder(Node* node) {
	std::stringstream buffer;

	if (node->getLeft() != nullptr) {
		buffer << PostOrder(node->getLeft()).rdbuf();
	}
	if (node->getRight() != nullptr) {
		buffer << PostOrder(node->getRight()).rdbuf();
	}
	buffer << node->getData();
	return buffer;
}