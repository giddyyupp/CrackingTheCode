/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 8, 2018, 2:32 PM
 */

#include <cstdlib>
#include "TreeSam.h"
#include "TreeSam.cpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    TreeSam<int> sam_tree;
    
    sam_tree.insertNode(3);
    sam_tree.insertNode(4);
    sam_tree.insertNode(5);
    sam_tree.insertNode(6);
    sam_tree.insertNode(7);
    sam_tree.insertNode(8);
    sam_tree.insertNode(31);
    sam_tree.insertNode(7);
    sam_tree.insertNode(90);
    
    sam_tree.inOrderTraverse(sam_tree.getRoot());
    std::cout << std::endl;

    sam_tree.postOrderTraverse(sam_tree.getRoot());
    std::cout << std::endl;
    
    sam_tree.preOrderTraverse(sam_tree.getRoot());
    std::cout << std::endl;

    sam_tree.deleteNode(6);
    
    sam_tree.preOrderTraverse(sam_tree.getRoot());
    std::cout << std::endl;
    
    
    return 0;
}

