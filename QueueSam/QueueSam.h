/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueSam.h
 * Author: sam
 *
 * Created on February 6, 2018, 10:00 PM
 * 
 * 
 * 3.5	 Implement a MyQueue class which implements a queue using two stacks.
 */

#ifndef QUEUESAM_H
#define QUEUESAM_H

#include <iostream>
#include "../StackSam/StackSam.h"


template<typename T>
class QueueSam{
    
public:
    QueueSam();
    ~QueueSam();
    void insertQ(T elem);
    T deleteQ();
    void printQ();
        
private:
    StackSam<T>* stack1;
    StackSam<T>* stack2;

};



#endif /* QUEUESAM_H */

