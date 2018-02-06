/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.h
 * Author: sam
 *
 * Created on February 3, 2018, 1:59 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdio>
#include <stdio.h>
#include <iostream>

template<typename T>
struct Node{
    T value;
    Node* next;
};

template<typename T>
class LinkedList{
    
public:
    LinkedList();
    ~LinkedList();
    
    void insertTail(T elementVal);
    void insertHead(T elementVal);
    void deleteNode(T elementVal);
    void deleteFront();
    
    bool search(T elementVal);
    void printList();
    bool empty();
    
    // remove duplicates soru2.1
    void removeDuplicatesV1();
    void removeDuplicatesV2();
    // Soru3.2 min node
    Node<T>* getMinNode();
    Node<T>* getFront();

    
private:
    Node<T>* head;
    int node_count; 
    
    // min node
    Node<T>* min_node;
    
};


#endif /* LINKEDLIST_H */

