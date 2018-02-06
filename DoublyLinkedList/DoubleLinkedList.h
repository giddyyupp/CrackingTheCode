/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoubleLinkedList.h
 * Author: sam
 *
 * Created on February 3, 2018, 3:59 PM
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <cstdio>
#include <stdio.h>
#include <iostream>


template<typename T>
struct Node{
    Node* prev;
    Node* next;
    T value;
};

template<typename T>
class DoubleLinkedList{
    
    public:
        DoubleLinkedList<T>();
        ~DoubleLinkedList<T>(); 
        void insertItem(T value);
        void deleteItem(T value);
        bool searchItem(T value);
        
        void print();
        
    private:
        Node<T>* head;
        Node<T>* tail;
        int node_count;
    
};


#endif /* DOUBLELINKEDLIST_H */

