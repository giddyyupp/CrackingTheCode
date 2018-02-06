/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "./SetofStackSam.h"

template<typename T>    
SetofStackSam<T>::SetofStackSam(int max){
//    first_stack = new StackSam<T>();
    self_max_item_count = max;
    stack_list.push_back(new StackSam<T>());
    stack_list_element_count.push_back(0);
//    self_stack_count++;
}


template<typename T>
SetofStackSam<T>::~SetofStackSam(){
    for (int i = 0; i < stack_list.size(); i++)
        stack_list[i]->~StackSam<T>();
}

template<typename T>    
void SetofStackSam<T>::pop(){
    
    if (stack_list_element_count[self_stack_count] <= 0){
        std::cout << "This stack is empty!! " << std::endl;
    }
    else{
        stack_list[self_stack_count]->pop();
        stack_list_element_count[self_stack_count]--;
    }
}

template<typename T>    
void SetofStackSam<T>::popAt(int index){
    
    if (stack_list_element_count[index] <= 0){
        std::cout << "This stack is empty!! " << std::endl;
    }
    else{
        stack_list[index]->pop();
        stack_list_element_count[index]--;
    }
}


template<typename T>    
void SetofStackSam<T>::push(T val){
    if (self_curr_stack_elem_count == self_max_item_count){
        // create new stack
        stack_list.push_back(new StackSam<T>());
        self_curr_stack_elem_count= 1;
        self_stack_count++;
        stack_list[self_stack_count]->push(val);
        stack_list_element_count.push_back(self_curr_stack_elem_count);
    }
    else{
        stack_list_element_count[self_stack_count]++;
        // insert current stack
        self_curr_stack_elem_count++;
        stack_list[self_stack_count]->push(val);
    }
}


template<typename T>    
Node<T>* SetofStackSam<T>::top(int index){
    
//    Node<T>* top = this->ola->getFront(); 
//    if (top == NULL){
//        std::cout<< "Stack Empty!!" << std::endl;
//        return NULL;
//    }
//    else
//        return top;
}

template<typename T>    
void SetofStackSam<T>::print(){
    
    for (int i = 0; i < stack_list.size(); i++)
        stack_list[i]->print();
}