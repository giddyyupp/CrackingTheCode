/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "StackSam.h"
#include "../LinkedList/LinkedList.cpp"


template<typename T>    
StackSam<T>::StackSam(){
    this->ola = new LinkedList<T>();
}

template<typename T>
StackSam<T>::~StackSam(){
    this->ola->~LinkedList();
}

template<typename T>    
void StackSam<T>::pop(){
    this->ola->deleteFront();
}

template<typename T>    
void StackSam<T>::push(T val){
    this->ola->insertHead(val);
}

template<typename T>    
Node<T>* StackSam<T>::top(){
    
    Node<T>* top = this->ola->getFront(); 
    if (top == NULL){
        std::cout<< "Stack Empty!!" << std::endl;
        return NULL;
    }
    else
        return top;
}

template<typename T>    
Node<T>* StackSam<T>::minValue(){
    
    return this->ola->getMinNode();
}

template<typename T>    
void StackSam<T>::print(){
    
    this->ola->printList();
}

template<typename T>    
bool StackSam<T>::empty(){
    
    return this->ola->empty();
}


