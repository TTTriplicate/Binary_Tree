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
void readTree(BinarySearchTree& tree);

int main()
{
    BinarySearchTree tree1, tree2;

    plantTree(tree1, "./tree1.txt");
    plantTree(tree2, "./tree2.txt");


    std::cout << "Tree 1 traversal and stats:" << std::endl;
    readTree(tree1);

    std::cout << "Tree 2 traversal and stats:" << std::endl;
    readTree(tree2);

    return 0;
}

void plantTree(BinarySearchTree& tree, std::string file) {
    //reads data into a binary search tree from a specified file
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

void readTree(BinarySearchTree& tree) {
    //outputs all traversals, tree height, and tree balance to console
    std::cout << "Tree in Post Order:\n" << tree.dataPostOrder().str() << std::endl << std::endl;
    std::cout << "Tree in Pre Order:\n" << tree.dataPreOrder().str() << std::endl << std::endl;
    std::cout << "Tree In Order:\n" << tree.dataInOrder().str() << std::endl << std::endl;

    std::cout << "Min value in tree: " << tree.getMin()->getData() << std::endl;
    std::cout << "Max value in tree: " << tree.getMax()->getData() << std::endl;

    std::cout << "Height of tree: " << tree.getHeight() << std::endl;
    std::string treeBalance = tree.isBalanced() ? "Tree is balanced" : "Tree is not balanced";
    std::cout << treeBalance << std::endl << std::endl;
}