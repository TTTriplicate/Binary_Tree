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
	return abs(calculateHeight(root->getLeft()) - calculateHeight(root->getRight())) < 2;
}

int BinarySearchTree::getHeight() {
	return calculateHeight(root);
}

int BinarySearchTree::calculateHeight(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	else if (node->getLeft() == nullptr && node->getRight() == nullptr) {
		return 1;
	}
	else {
		int leftHeight = calculateHeight(node->getLeft());
		int rightHeight = calculateHeight(node->getRight());
		return  1 + max(leftHeight, rightHeight);
	}
}

int BinarySearchTree::max(int a, int b) {
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
