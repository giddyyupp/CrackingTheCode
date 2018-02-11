/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 11, 2018, 6:49 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>

#include "asd.h"

using namespace std;

/*
 * 13.1	 Write a method to print the last K lines of an input file using C++.
 */
void printLastKLines(std::string file_name, int K);

/*
 * 
 */
int main(int argc, char** argv) {
    
    printLastKLines("./last_k.txt", 5);
    
    Shape * x = new Shape();
    x->circumference(); // prints “Circumference of Base Class”
    Shape *y = new Triangle();
    y->circumference(); // prints “Circumference of Triangle Class”


    return 0;
}


void printLastKLines(std::string file_name, int K){
    
    std::ifstream in_file(file_name.c_str());
    std::string line;
    std::queue<std::string> k_finder;   
    int counter = 0;
    
    while(getline(in_file, line)){
        
        if (counter < K){
            k_finder.push(line);
        }
        else{
            k_finder.push(line);
            k_finder.pop();
        }
        counter++;
    }
    
    for(int i = 0; i < 5; i++){
        
        std::cout << k_finder.front() << std::endl;
        k_finder.pop();
    }
}




