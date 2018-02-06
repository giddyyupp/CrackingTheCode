/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <map>
#include <tuple>
#include "LinkedList.h"


template<typename T>
LinkedList<T>::LinkedList(){
    
    head = new Node<T>;
    head->next = NULL;
    node_count = 0;
    min_node = head;
}


template<typename T>
LinkedList<T>::~LinkedList(){
    head = NULL;
}


template<typename T>
void LinkedList<T>::insertTail(T elementVal){
    
    // first seek through last element
    Node<T>* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    //create node
    Node<T>* insert = new Node<T>;
    insert->value = elementVal;
    insert->next = NULL;

    // now insert
    temp->next = insert; 
    
    node_count++;
}


template<typename T>
void LinkedList<T>::insertHead(T elementVal){
    
    // get head
    Node<T>* temp = head;
    //create node
    Node<T>* insert = new Node<T>;
    insert->value = elementVal;
    
    if (temp->next == NULL){ // empty list
        insert->next = NULL;
        min_node = insert;
    }
    else{
        temp = temp->next;
        insert->next = temp;
        if(min_node->value > elementVal){
            min_node = insert;            
        }
    }
    // now insert
    head->next = insert;
    node_count++;
}


// deletes first occurence of given value!!
template<typename T>
void LinkedList<T>::deleteNode(T elementVal){
    
    if (node_count == 0){
        std::cout << "List is Empty!!!" << std::endl;
        return;
    }
    
    bool found = false;
    // search for elementVal
    Node<T>* temp = head;
    while(temp->next != NULL){
        if (temp->next->value == elementVal){
            found = true;
            break;
        }
        temp = temp->next;
    }
    // now temp is our prev node of deleteNode
    // check whether we found it or not
    if (!found){
        std::cout << "Element not Found" << std::endl;
        return;
    }
    // else update 
    else{
        Node<T>* next = temp->next->next;
        Node<T>* curr = temp->next;

        temp->next->next = NULL;
        temp->next = next;

        delete curr;
    }
    node_count--;
}


// deletes first occurence of given value!!
template<typename T>
void LinkedList<T>::deleteFront(){
    
    if (node_count == 0){
        std::cout << "List is Empty!!!" << std::endl;
        return;
    }
    Node<T>* next, *curr;
    
    // delete 1. node
    if (node_count == 1){ // if there is only 1 item in the stack.
        next = NULL;
    }
    else{
        next = head->next->next;
    }
        
    curr = head->next;
    head->next = next;
    curr->next = NULL;
    delete curr;
    node_count--;
}


template<typename T>
bool LinkedList<T>::search(T elementVal){
    
    bool found = false;
    // search for elementVal
    Node<T>* temp = head;
    while(temp->next != NULL){
        if (temp->next->value == elementVal){
            found = true;
            break;
        }
        temp = temp->next;
    }
    
    return found;
}


template<typename T>
void LinkedList<T>::printList(){
    // first seek through last element
    Node<T>* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        std::cout << temp->value << "-";
    }
    std::cout << std::endl;
}

template<typename T>
bool LinkedList<T>::empty(){
    
    if (node_count == 0)
        return true;
    else
        return false;
}


template<typename T>
void LinkedList<T>::removeDuplicatesV1(){

    Node<T>* temp = head;

    if(node_count < 2) // listede 1 ya da 0 eleman varsa dup yoktur.
        return;
    // v1: hashmap e ekleme.
    std::map<T, int> mapsam;
    
    while(temp->next != NULL){
        T val = temp->next->value;
        mapsam[val]++;
        temp = temp->next;
    }
    
    for( auto& sm_pair : mapsam )
        while (sm_pair.second > 1){
            deleteNode(sm_pair.first);    
            sm_pair.second--;
        }
}


template<typename T>
void LinkedList<T>::removeDuplicatesV2(){

    Node<T>* temp = head;
    Node<T>* temp2 = head;
    Node<T> *prev, *curr;
    bool deleted = false;
  
    // v2: iki tur atarak silelim.
    while(temp->next != NULL){
        deleted = false;
        T val = temp->value;
        temp2 = temp;
//        temp2 = temp->next;
        while(temp2->next != NULL){
            if(temp2->next->value == val){
                // delete this node!
                prev = temp2;
                curr = temp2->next;
                temp2->next = curr->next;
                curr->next = NULL;
                delete curr;                
            }
            else
                temp2 = temp2->next;
        }
        temp = temp->next;
    }
}


template<typename T>
Node<T>* LinkedList<T>::getMinNode(){
    return min_node;
}


template<typename T>
Node<T>* LinkedList<T>::getFront(){
    
    if (this->node_count == 0)
        return NULL;
    else
        return this->head->next;
    
    
}
   