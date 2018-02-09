/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTreeSam.cpp
 * Author: sam
 * 
 * Created on February 8, 2018, 7:16 PM
 */

#include <complex>

#include "BSTreeSam.h"

template<typename T>
BSTreeSam<T>::BSTreeSam() {
    
    TreeSam<T>();
}

template<typename T>
BSTreeSam<T>::BSTreeSam(const BSTreeSam& orig) {
}

template<typename T>
BSTreeSam<T>::~BSTreeSam() {
}

// search for next empty slot.
template<typename T>
void BSTreeSam<T>::insert_node(Node<T>* new_node){
    
    Node<T>* temp = TreeSam<T>::root;
    
    while(temp != NULL){
        if(new_node->value > temp->value){
            if(temp->right != NULL)
                temp = temp->right;
            else{ 
                temp->right = new_node;
                new_node->parent = temp;
            }
        }
        else if(new_node->value < temp->value ){
            if(temp->left != NULL)
                temp = temp->left;
            else{
                temp->left = new_node;
                new_node->parent = temp;
            }
        }
        else // equal value
            return;
    }
}

/*
 4.6	 Design an algorithm and write code to find the first common ancestor of two nodes
     in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
     necessarily a binary search tree.
 *  Solution 1: trace back up to hills. over the hills and far away.
 */
template<typename T>
Node<T>* BSTreeSam<T>::findCommonAncestor(T val1, T val2){
    
    Node<T>* node1 = searchNode(val1);
    Node<T>* node2 = searchNode(val2);
    
    Node<T>* temp1 = node1, *temp2 = node2;
    
    std::vector<Node<T>*> list1, list2;
    
    if (node1 == NULL || node2 == NULL){
        return NULL;
    }
    
    while(temp1 != TreeSam<T>::root_root_ptr){
        temp1 = temp1->parent;
        list1.push_back(temp1);
    }
    while(temp2 != TreeSam<T>::root_root_ptr){
        temp2 = temp2->parent;
        list2.push_back(temp2);
    }
    
    // now search
    for(int i = 0; i < list1.size(); i++){
        for(int j = 0; j < list2.size(); j++){
            if(list1[i] == list2[j])
                return list1[i];
        }
    }
    
    return NULL; // no luck
}


template<typename T>
Node<T>* BSTreeSam<T>::searchNode(T val){
    
    Node<T>* temp = TreeSam<T>::root;
    
    while(temp != NULL){
        if(val > temp->value){
            if(temp->right != NULL)
                temp = temp->right;
        }
        else if(val < temp->value ){
            if(temp->left != NULL)
                temp = temp->left;
        }
        else // equal value
            return temp;
    }
    
}

/*
 * 4.5	 Write an algorithm to find the ‘next’ node (e.g., in-order successor) of a given node in
     a binary search tree where each node has a link to its parent.
 */
template<typename T>
Node<T>* BSTreeSam<T>::findSuccessor(Node<T>* node){
    
    Node<T>* temp = node;
    
    if (temp->right != NULL){ // case 1.
        temp = temp->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    else{ //case2.
        temp = temp->parent;
        if (temp->left == node){ // case 2.1 
            return temp;
        }
        else{ // case 2.2 
            while(temp != temp->parent->left) 
                temp = temp->parent;
            return temp->parent;
        }
    }
}


template<typename T>
void BSTreeSam<T>::insertNode(T val){
    
    if (TreeSam<T>::node_count == 0) {
        TreeSam<T>::root = new Node<T>();
        TreeSam<T>::root->left = NULL;
        TreeSam<T>::root->right = NULL;
        TreeSam<T>::root->value = val;
        TreeSam<T>::root_root_ptr->left =TreeSam<T>::root; // dummy assignment!! 
        TreeSam<T>::root->parent = TreeSam<T>::root_root_ptr;
    }
    else{
        Node<T>* new_node = new Node<T>();
        new_node->value = val;
        new_node->left = NULL;
        new_node->right = NULL;

        this->insert_node(new_node);
    }
    
    TreeSam<T>::node_count++;
}


template<typename T>
bool BSTreeSam<T>::deleteNode(T val){
    // first find the node
    // here search for node!
    bool leaf_order = 0; // 1 -> left, 0 -> right
    bool found = false;
    Node<T>* temp = TreeSam<T>::root;
    Node<T>* temp_root = TreeSam<T>::root_root_ptr;
    Node<T>* temp_curr = TreeSam<T>::root;
    
    while(temp != NULL){
        if(val> temp->value){
            temp_root = temp;
            temp = temp->right;
            temp_curr = temp;
            leaf_order = 0;
        }
        else if(val < temp->value ){
            temp_root = temp;
            temp = temp->left;
            temp_curr = temp;
            leaf_order = 1;
        }
        else{ // equal value{
            TreeSam<T>::delete_node(temp_root, temp_curr, leaf_order);
            found = true;
            break;
        }
    }
   
    return found;
}


template<typename T>
bool BSTreeSam<T>::isBalanced(){
    
    int height = 0;
    return is_balanced(TreeSam<T>::getRoot(), &height);
}


/*
 4.1	 Implement a function to check if a tree is balanced. For the purposes of this question,
     a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
     from the root by more than one.
 */
template<typename T>
bool BSTreeSam<T>::is_balanced(Node<T>* root, int* height){
    
    int lh = 0, rh = 0;
    bool is_left_balanced = false;
    bool is_right_balanced = false;
    
    if (root == NULL){
        *height = 0;
        return true;
    }
    
    is_left_balanced = is_balanced(root->left, &lh);
    is_right_balanced = is_balanced(root->right, &rh);
    
    *height = std::max(lh,rh) + 1;
    
    if (std::abs(lh - rh) >= 2)
        return false;
    else 
        return is_right_balanced && is_left_balanced;
    
}