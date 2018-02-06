/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SetofStackSam.h
 * Author: sam
 *
 * Created on February 6, 2018, 12:53 PM
 */

#ifndef SETOFSTACKSAM_H
#define SETOFSTACKSAM_H
#include <vector>

#include "../StackSam/StackSam.h"
#include "../StackSam/StackSam.cpp"

template<typename T>
class SetofStackSam{
    
public:
    SetofStackSam(int max_item_count);
    ~SetofStackSam();
    
    void push(T val);
    void pop();
    void popAt(int index);
    Node<T>* top(int index);
    void print();

    std::vector<StackSam<T>*> stack_list;
    std::vector<int> stack_list_element_count;
    
private:
    int self_max_item_count = 3;
    int self_curr_stack_elem_count = 0;
    int self_stack_count = 0;
    
};



#endif /* SETOFSTACKSAM_H */

