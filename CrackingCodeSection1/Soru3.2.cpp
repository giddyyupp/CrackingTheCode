/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru3.2.cpp
 * Author: sam
 *
 * Created on February 6, 2018, 11:13 AM
 * 
 * 3.2	 How would you design a stack which, in addition to push and pop, also has a function
     min which returns the minimum element? Push, pop and min should all operate in
     O(1) time. 

 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "../LinkedList/LinkedList.h"
#include "../LinkedList/LinkedList.cpp"

using namespace std;

/*
 * 
 */
int main32(int argc, char** argv) {
    
    // test
    LinkedList<int> samhi;
    samhi.insertHead(1111); // O(1) insertion
    samhi.insertHead(1212311);
    samhi.insertHead(212321);
    samhi.insertHead(31231);
    samhi.insertHead(3);
    samhi.insertHead(52131);
    samhi.insertHead(612321);
    samhi.insertHead(52123113);
    samhi.insertHead(312321);
    samhi.insertHead(1213131);
    
    samhi.printList();
    std::cout << std::endl;
    
    samhi.deleteFront(); // O(1) deletion
    samhi.printList();
    std::cout << std::endl;
    
    Node<int>* node_min = samhi.getMinNode(); // // O(1) get min node
    std::cout << "Min Value: " << node_min->value <<  std::endl;

    return 0;
}

