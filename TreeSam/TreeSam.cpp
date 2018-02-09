/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeSam.cpp
 * Author: sam
 * 
 * Created on February 8, 2018, 2:32 PM
 */

#include "TreeSam.h"
#include <queue>

template<typename T>
TreeSam<T>::TreeSam() {
    
    root_root_ptr = new Node<T>();
    root_root_ptr->left = NULL;
    root_root_ptr->right = NULL;
    
    node_count = 0;
}

template<typename T>
TreeSam<T>::TreeSam(const TreeSam& orig) {
}

template<typename T>
TreeSam<T>::~TreeSam() {
}


template<typename T>
void TreeSam<T>::insertNode(T val){
    if (node_count == 0) {
        root = new Node<T>();
        root->left = NULL;
        root->right = NULL;
        root->value = val;
        root_root_ptr->left =root; // dummy assignment!! 
    }
    else{
        Node<T>* new_node = new Node<T>();
        new_node->value = val;
        new_node->left = NULL;
        new_node->right = NULL;

        insert_node(new_node);
    }
    
    node_count++;
}

// search for next empty slot. // level order traverse to find next empty slot
template<typename T>
void TreeSam<T>::insert_node(Node<T>* new_node){
    
    Node<T>* temp;
    std::queue<Node<T>*> search_q;
    search_q.push(root);
    bool left_right_flag = 0; // 0 -> left, 1 -> right
    
    while(!search_q.empty()){
        temp = search_q.front();
        if (temp->left != NULL){
            search_q.push(temp->left);
        }
        else{
            left_right_flag = 0;
            break;
        }            
        if (temp->right != NULL)
            search_q.push(temp->right);
        else{
            left_right_flag = 1;
            break;
        }  
        search_q.pop(); // if both child are full then pop this item.
    }
    
    // now insert correct position!!
    if (left_right_flag)
        temp->right = new_node;
    else
        temp->left = new_node;
    
}


// for simplicity I will implement delete just like in BSTs.
template<typename T>
bool TreeSam<T>::deleteNode(T val){
    
    // here search for node!
    Node<T>* temp;
    std::queue<Node<T>*> search_q;
    search_q.push(root);
    bool found = 0; 
    
    while(!search_q.empty()){
        temp = search_q.front();
        if(temp->value == val){ // delete this
            delete_node(root_root_ptr, temp, 1);
            found = true;
            break;
        }
        if (temp->left != NULL){
            if(temp->left->value == val){
                delete_node(temp, temp->left, 1);
                found = true;
                break;
            }
            else
                search_q.push(temp->left);
        }
        if (temp->right != NULL){
            if(temp->right->value == val){
                delete_node(temp, temp->right, 0);
                found = true;
                break;
            }
            else
                search_q.push(temp->right);
        } 
        search_q.pop(); // if both child are full then pop this item.
    }
    
    return found;
}

/*
 1. if node has no child then just delete it
 2. if node has one child then just replace curr with child.
 3. if node has two child then find successor. successor is the next highest value.
 successor locates in right and go left until hit NULL.
 */
template<typename T>
void TreeSam<T>::delete_node(Node<T>* node_root, Node<T>* node, bool left_child){
    
    if(node->left == NULL && node->right == NULL){
        // obviously below should be ok, but it doesnt update correctly!!
        node = NULL;
        delete node;

        if(left_child == 1)
            node_root->left = node;
        else
            node_root->right = node;
        
        return;
    }
    else if (node->left == NULL){
        // obviously below should be ok, but it doesnt update correctly!!
        Node<T>* temp = node;
        node = node->right;
        delete temp;
        
        if(left_child == 1)
            node_root->left = node;
        else
            node_root->right = node;
    }
    else if (node->right == NULL){
        // obviously below should be ok, but it doesnt update correctly!!
        Node<T>* temp = node;
        node = node->left;
        delete temp;
        
        if(left_child == 1)
            node_root->left = node;
        else
            node_root->right = node;
    }
    else{
        // find successor
        Node<T>* temp = node->right;
        Node<T>* temp_root = node;
        left_child = 0;
        while(temp->left != NULL){
            temp_root = temp;
            temp = temp->left;
            left_child = 1;
        }
        node->value = temp->value;
        delete_node(temp_root, temp, left_child);
    }
    
    
}

template<typename T>
void TreeSam<T>::inOrderTraverse(Node<T>* nodde){
    
    if(nodde == NULL)
        return;
    
    inOrderTraverse(nodde->left);
    
    std::cout << nodde->value << " - ";
    
    inOrderTraverse(nodde->right);
}

template<typename T>
void TreeSam<T>::preOrderTraverse(Node<T>* nodde){
        
    if(nodde == NULL)
        return;
    
    std::cout << nodde->value << " - ";
    
    preOrderTraverse(nodde->left);
    
    preOrderTraverse(nodde->right);
}

template<typename T>
void TreeSam<T>::postOrderTraverse(Node<T>* nodde){
    
    if(nodde == NULL)
        return;
    
    postOrderTraverse(nodde->left);
    
    postOrderTraverse(nodde->right);
    
    std::cout << nodde->value << " - ";
}

template<typename T>
Node<T>* TreeSam<T>::getRoot(){
    
    return root;
}

