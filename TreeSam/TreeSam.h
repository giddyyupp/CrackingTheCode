/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeSam.h
 * Author: sam
 *
 * Created on February 8, 2018, 2:32 PM
 * 
 * Sam's implementation of Tree Class. This is not a BST!!!
 */

#ifndef TREESAM_H
#define TREESAM_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>


template<typename T>
struct Node{
    T value;
    Node* left;
    Node* right;
    Node* parent; // for finding successor's
};

template<typename T>
class TreeSam {
public:
    TreeSam();
    TreeSam(const TreeSam& orig);
    virtual ~TreeSam();
    
    virtual void insertNode(T val);
    virtual bool deleteNode(T val);
    
    virtual void inOrderTraverse(Node<T>* nodde);
    virtual void preOrderTraverse(Node<T>* nodde);
    virtual void postOrderTraverse(Node<T>* nodde);
    
    virtual Node<T>* getRoot();
    
protected:
    virtual void insert_node(Node<T>* new_node);
    virtual void delete_node(Node<T>* node_root, Node<T>* node, bool left_child);
    Node<T>* root;
    //I need this shit, since delete is not working correctly!!
    Node<T>* root_root_ptr; // dummy ptr points to root. 
    int node_count;

};

#endif /* TREESAM_H */

