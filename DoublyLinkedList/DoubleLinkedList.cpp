/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DoubleLinkedList.h"

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(){
    // create empty head and tail nodes. 
    head = new Node<T>;
    tail = new Node<T>;
    head->next = tail;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = head;
    
    node_count = 0;
}


template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    
    head->next = NULL;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = NULL;
    
    delete head;
    delete tail;    
}


template<typename T>
void DoubleLinkedList<T>:: insertItem(T value){
    
    Node<T>* new_node = new Node<T>;
    new_node->value = value;
    
    if (node_count == 0){ // zero items in the list
        head->next = new_node;
        tail->prev = new_node;
        new_node->next = tail;
        new_node->prev = head;
    }
    else{
        Node<T>* temp_prev = tail->prev;
        temp_prev->next = new_node;
        tail->prev = new_node;
        new_node->next = tail;
        new_node->prev = temp_prev;        
    }
    
    node_count++;
}


template<typename T>
void DoubleLinkedList<T>::deleteItem(T value){
    
    bool found = false;
    
    if (node_count == 0){ // zero items in the list
        std::cout << "List is Empty!!!" << std::endl;
        return;
    }
    else{ // search for the node
        Node<T>* start = head->next;
        while(start != tail){
            if (start->value == value){
                found = true;
                break;
            }
            start = start->next;
        } 
        if (found){
            // now adjust links.
            start->prev->next = start->next;
            start->next->prev = start->prev;
            start->next = NULL;
            start->prev = NULL;
            delete start;
            node_count--;
            std::cout << "Searched Item: " << value << " Is Deleted!!!" << std::endl;
        }
        else{
            std::cout << "Searched Item: " << value << " Not Found!!!" << std::endl;
        }
    }
    
}


template<typename T>
bool DoubleLinkedList<T>::searchItem(T value){
    
}

template<typename T>
void DoubleLinkedList<T>::print(){
    // first seek through last element
    Node<T>* temp = head;
    while(temp->next != tail){
        temp = temp->next;
        std::cout << temp->value << std::endl;
    }
    
    
}
