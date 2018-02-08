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
 * 
 * 3.3	 Imagine a (literal) stack of plates. If the stack gets too high, it might topple. There-
     fore, in real life, we would likely start a new stack when the previous stack exceeds
     some threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
     Stacks should be composed of several stacks, and should create a new stack once
     the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
     behave identically to a single stack (that is, pop() should return the same values as it
     would if there were just a single stack).
     FOLLOW UP
     Implement a function popAt(int index) which performs a pop operation on a specific
     sub-stack.

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

