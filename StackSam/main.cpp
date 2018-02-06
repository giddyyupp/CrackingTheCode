/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 6, 2018, 11:54 AM
 */

#include <cstdlib>

#include "StackSam.h"
#include "StackSam.cpp"

using namespace std;

/*
 * 
 */
int main(){
    
    StackSam<int> samhii;
    
    samhii.top();

    samhii.push(1);
    samhii.push(3);
    samhii.push(4);
    samhii.push(55);
    samhii.push(5123121);
    samhii.push(35434543);
    samhii.push(212331231);
    samhii.push(423131314);
    
    samhii.print();
    
    Node<int>* toppp =samhii.top();

    std::cout << "Top Value: " << toppp->value << std::endl;
    
    samhii.pop();


    samhii.print();

    return 0;
}
