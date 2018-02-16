/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackSam.h
 * Author: sam
 *
 * Created on February 6, 2018, 11:54 AM
 */

#ifndef STACKSAM_H
#define STACKSAM_H

#include "../LinkedList/LinkedList.h"

template<typename T>
class StackSam{
    public:
        StackSam();
        virtual ~StackSam();
        
        void pop();
        void push(T val);
        Node<T>* top();
        Node<T>* minValue();  
        void print();
        bool empty();
        
        LinkedList<T>* ola;
};



#endif /* STACKSAM_H */

