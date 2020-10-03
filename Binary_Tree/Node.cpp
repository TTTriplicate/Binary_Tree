/*
Class: Node
Purpose: nodes for a binary search tree
*/
#include "Node.h"

Node::Node() {
	left = nullptr;
	right = nullptr;
}

Node::Node(int inputData) {
	data = inputData;
	left = nullptr;
	right = nullptr;
}

Node::~Node() {
	//this will delete any subtree of a deleted node
	delete right;
	delete left;
}

int Node::getData() {
	return data;
}

Node* Node::getLeft() {
	return left;
}

Node* Node::getRight() {
	return right;
}

void Node::setLeft(Node* newLeft) {
	left = newLeft;
}

void Node::setRight(Node* newRight) {
	right = newRight;
}

//overloaded comparators for ease of use in BST
bool Node::operator<(const Node& toCompare) {
	return data < toCompare.data;
}
bool Node::operator>(const Node& toCompare) {
	return data > toCompare.data;
}
bool Node::operator==(const Node& toCompare) {
	return data == toCompare.data;
}