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


    std::cout << "Tree 1 in Post Order:\n" << tree1.dataPostOrder().str() << std::endl << std::endl;
    std::cout << "Tree 1 in Pre Order:\n" << tree1.dataPreOrder().str() << std::endl << std::endl;
    std::cout << "Tree 1 In Order:\n" << tree1.dataInOrder().str() << std::endl << std::endl;

    std::cout << "Min value in tree 1: " << tree1.getMin()->getData() << std::endl;
    std::cout << "Max value in tree 1: " << tree1.getMax()->getData() << std::endl;

    std::cout << "Height of tree 1: " << tree1.getHeight() << std::endl;
    std::string treeBalance = tree1.isBalanced() ? "Tree 1 is balanced" : "Tree 1 is not blanced";
    std::cout << treeBalance << std::endl << std::endl;


    std::cout << "Tree 2 in Post Order:\n" << tree2.dataPostOrder().str() << std::endl << std::endl;
    std::cout << "Tree 2 in Pre Order:\n" << tree2.dataPreOrder().str() << std::endl << std::endl;
    std::cout << "Tree 2 In Order:\n" << tree2.dataInOrder().str() << std::endl << std::endl;

    std::cout << "Min value in tree 2: " << tree2.getMin()->getData() << std::endl;
    std::cout << "Max value in tree 2: " << tree2.getMax()->getData() << std::endl;

    std::cout << "Height of Tree 2: " << tree2.getHeight() << std::endl;
    treeBalance = tree2.isBalanced() ? "Tree 2 is balanced" : "Tree 2 is not blanced";
    std::cout << treeBalance << std::endl << std::endl;

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
