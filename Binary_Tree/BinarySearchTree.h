#pragma once
#include "Node.h"
#include <sstream>

class BinarySearchTree
{
private:
	Node* root;
	Node* cursor;

	bool checkBalance();

	std::stringstream InOrder(Node* node);
	std::stringstream PreOrder(Node* node);
	std::stringstream PostOrder(Node* node);

	int calculateHeight(Node* node);
	int max(int a, int b);

public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(int data);

	//I chose std::stringstreams to allow main to determine output format
	//Not a data strucure's job to define how data is output, just stored
	std::stringstream dataInOrder();
	std::stringstream dataPreOrder();
	std::stringstream dataPostOrder();

	Node* getMax();
	Node* getMin();

	bool isBalanced();
	int getHeight();
};

