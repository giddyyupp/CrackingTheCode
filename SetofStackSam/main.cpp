/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 6, 2018, 12:53 PM
 */

#include <cstdlib>
#include "./SetofStackSam.h"
#include "./SetofStackSam.cpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    SetofStackSam<int> stackSam(3);
    
    stackSam.push(1);
    stackSam.push(2);
    stackSam.push(3);
    stackSam.push(4);
    stackSam.push(5);
    stackSam.push(6);
    stackSam.push(7);
    stackSam.push(8);

    stackSam.print();
    std::cout<<std::endl;
    
    stackSam.pop();
    stackSam.print();
    std::cout<<std::endl;
    
    stackSam.popAt(1);
    stackSam.popAt(0);

    stackSam.print();
    std::cout<<std::endl;

    return 0;
}

