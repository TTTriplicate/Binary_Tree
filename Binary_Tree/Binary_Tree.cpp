/*
Binary_Tree.cpp
Author: Chris Sousa
A Binary Tree implementation for 
algorithmic analysis
*/
#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"


void plantTree(BinarySearchTree& tree, std::string file);

int main()
{
    BinarySearchTree tree1, tree2;

    plantTree(tree1, "./tree1.txt");
    plantTree(tree2, "./tree2.txt");


    std::cout << tree1.dataPostOrder().str() << std::endl << std::endl;
    std::cout << tree1.dataPreOrder().str() << std::endl << std::endl;

    std::cout << tree1.getHeight() << std::endl;
    std::cout << tree1.isBalanced() << std::endl << std::endl;


    std::cout << tree2.dataPostOrder().str() << std::endl << std::endl;
    std::cout << tree2.dataPreOrder().str() << std::endl << std::endl;


    std::cout << tree2.getHeight() << std::endl;
    std::cout << tree2.isBalanced() << std::endl << std::endl;


}

void plantTree(BinarySearchTree& tree, std::string file) {
    std::fstream fileIn;
    try {
        fileIn.open(file);

        int next;
        while (fileIn >> next) {
            tree.insert(next);
        }
        fileIn.close();
    }
    catch (std::exception e) {
        std::cerr << e.what();
        fileIn.close();
    }
}
