/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 6, 2018, 9:59 PM
 */

#include <cstdlib>
#include <iostream>

#include "QueueSam.h"
#include "QueueSam.cpp"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    QueueSam<int> samQ;
    samQ.insertQ(4);
    samQ.insertQ(1);
    samQ.insertQ(2);
    samQ.insertQ(6);
    samQ.insertQ(0);
    
    samQ.printQ();
    std::cout<< std::endl;
    
    samQ.deleteQ();
    
    samQ.printQ();
    std::cout<< std::endl;

    return 0;
}

