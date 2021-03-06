/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTreeSam.h
 * Author: sam
 *
 * Created on February 8, 2018, 7:16 PM
 */

#ifndef BSTREESAM_H
#define BSTREESAM_H

#include "../TreeSam/TreeSam.h"
#include "../TreeSam/TreeSam.cpp"
#include <algorithm>
#include <math.h>


template<typename T>
class BSTreeSam : public TreeSam<T>{
    
public:
    BSTreeSam();
    BSTreeSam(const BSTreeSam& orig);
    virtual ~BSTreeSam();
    
    void insertNode(T val);
    bool deleteNode(T val);
    
    Node<T>* searchNode(T val);
    Node<T>* findSuccessor(Node<T>* node);
    
    Node<T>* findCommonAncestor(T val1, T val2);
    
    bool isBalanced();

protected:
    void insert_node(Node<T>* new_node);
    bool is_balanced(Node<T>* root, int* height);

};

#endif /* BSTREESAM_H */

