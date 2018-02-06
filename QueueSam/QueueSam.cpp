/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "QueueSam.h"
#include "../StackSam/StackSam.cpp"

template<typename T>
QueueSam<T>::QueueSam(){

    stack1 = new StackSam<T>();
    stack2 = new StackSam<T>();
}

template<typename T>
QueueSam<T>::~QueueSam(){
    delete stack1;
    delete stack2;
}

template<typename T>
void QueueSam<T>::insertQ(T elem){
    
    stack1->push(elem);
}

template<typename T>
T QueueSam<T>::deleteQ(){
    
    while(!(stack1->empty())){
        stack2->push(stack1->top());
        stack1->pop();
    }
    T ret = stack2->top();
    stack2->pop();
    
    while(!(stack2->empty())){
        stack1->push(stack2->top());
        stack2->pop();
    }
    
    return ret;
}

template<typename T>
void QueueSam<T>::printQ(){
    
    while(!(stack1->empty())){
        stack2->push(stack1->top());
        stack1->pop();
    }
    
    stack2->print();
    
    while(!(stack2->empty())){
        stack1->push(stack2->top());
        stack2->pop();
    }
}