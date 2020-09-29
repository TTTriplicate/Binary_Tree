#pragma once
class Node
{
private:
	int data;
	Node* left;
	Node* right;
public:
	Node();
	Node(int data);
	~Node();
	int getData();
	Node* getLeft();
	void setLeft(Node* newLeft);
	Node* getRight();
	void setRight(Node* newRight);
	bool operator<(const Node toCompare);
	bool operator>(const Node toCompare);
	bool operator==(const Node toCompare);
};

