/*
Binary_Tree.cpp
Author: Chris Sousa
A Binary Tree implementation for 
algorithmic analysis
*/
#include <iostream>
#include "BinarySearchTree.h"
#include <fstream>

int main()
{
    BinarySearchTree tree;

    std::fstream fileIn;

    fileIn.open("./tree1.txt");

    int next;

    while (fileIn >> next) {
        std::cout << "next int: " << next << std::endl;
        tree.insert(next);
    }

    std::stringstream readTree;
    readTree << tree.dataPostOrder().rdbuf();

    std::cout << readTree.str() << std::endl;

    std::cout << tree.getHeight() << std::endl;
    std::cout << tree.isBalanced();
}
       