/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 8, 2018, 7:16 PM
 */

#include <cstdlib>
#include "BSTreeSam.h"
#include "BSTreeSam.cpp"

using namespace std;

/*
 4.3	 Given a sorted (increasing order) array, write an algorithm to create a binary tree with
     minimal height.
 */
void createMinHeightBT(BSTreeSam<int> &tree_sam, int* arr, int min_ind, int max_ind){
    
    if (max_ind < min_ind)
        return;
    
    int mid = (max_ind + min_ind)/2;
    tree_sam.insertNode(arr[mid]);
    createMinHeightBT(tree_sam, arr, min_ind, mid-1); // left tree
    createMinHeightBT(tree_sam, arr, mid+1, max_ind); // right tree
}

/*
 4.4	 Given a binary search tree, design an algorithm which creates a linked list of all the
     nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).
 */
template<typename T>
void soru4_4(BSTreeSam<T> &tree_sam){
    
    Node<T>* root = tree_sam.getRoot();

    if (root == NULL){
        return; // empty tree return!!
    }
    
    Node<T>* temp;
    std::queue<Node<T>*> search_q;
    int curr_count = 1, next_count = 0;
    std::vector<std::vector<int>> items; // vector or linked list!!
    
    // push root
    search_q.push(root); 
    
    // print root!
    std::cout << search_q.front()->value << " - ";
    std::cout <<  std::endl;
    
    // now get all nodes!!
    while(!search_q.empty()){
        temp = search_q.front();
        if (temp->left != NULL){
            search_q.push(temp->left);
            next_count++;
        }
        if (temp->right != NULL){
            search_q.push(temp->right);
            next_count++;
        }
        search_q.pop(); // pop this node
        curr_count--; // since we popped decrement value.
        if(curr_count == 0){ // here we have all new level node inside queue
            curr_count = next_count;
            next_count = 0;
            std::queue<Node<T>*> tmp_q = search_q; //copy the original queue to the temporary queue
            // now print
            while (!tmp_q.empty()){
                std::cout << tmp_q.front()->value << " - ";
                tmp_q.pop();
            } 
            std::cout <<  std::endl;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    BSTreeSam<int> sam_bst;
    
    sam_bst.insertNode(13);
    sam_bst.insertNode(3);
    sam_bst.insertNode(4);
    sam_bst.insertNode(1);
    sam_bst.insertNode(34);
    sam_bst.insertNode(89);
    sam_bst.insertNode(45);
    sam_bst.insertNode(50);

//    sam_bst.inOrderTraverse(sam_bst.getRoot());
//    std::cout << std::endl;
//
//    sam_bst.postOrderTraverse(sam_bst.getRoot());
//    std::cout << std::endl;
//    
//    sam_bst.preOrderTraverse(sam_bst.getRoot());
//    std::cout << std::endl;
//    
//    sam_bst.deleteNode(45);
//    
//    sam_bst.inOrderTraverse(sam_bst.getRoot());
//    std::cout << std::endl;
//    
//    bool res = sam_bst.isBalanced();
//    
//    std::cout << res << std::endl;
    
//    soru4_4(sam_bst);
    
    // soru 4.5:
    std::cout << sam_bst.findSuccessor(sam_bst.searchNode(3))->value << std::endl;
    
    // soru 4.6:
//    std::cout << sam_bst.findCommonAncestor(34, 4)->value << std::endl;

        
//    BSTreeSam<int> sam_bst_min;
//    int array_sam[] = {1,2,3,4,5,6,7};
//    createMinHeightBT(sam_bst_min, &array_sam[0], 0, 6);
//    
//    sam_bst_min.inOrderTraverse(sam_bst_min.getRoot());
//    std::cout << std::endl;

    return 0;
}

