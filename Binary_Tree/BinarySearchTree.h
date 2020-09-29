#pragma once
#include "Node.h"
#include <sstream>

class BinarySearchTree
{
private:
	Node* root;
	void insert(int data);
	bool checkBalance();
	int getHeight();
	//I chose std::stringstreams to allow main to determine output format
	//Not a data strucure's job to define how data is output, just stored
	std::stringstream inOrder();
	std::stringstream preOrder();
	std::stringstream postOrder();
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(int data);
	std::stringstream dataInOrder();
	std::stringstream dataPreOrder();
	std::stringstream dataPostOrder();
	bool isBalanced();
};

