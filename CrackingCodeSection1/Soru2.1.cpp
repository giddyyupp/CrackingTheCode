/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru2.1.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 7:45 PM
 * 
 * 2.1	 Write code to remove duplicates from an unsorted linked list.
     FOLLOW UP
     How would you solve this problem if a temporary buffer is not allowed?

 */
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/LinkedList.cpp"


#include <cstdlib>

using namespace std;

/*
 * 
 */
int main21(int argc, char** argv) {
    
    // test
    LinkedList<int> samhi;
    samhi.insertTail(1);
        samhi.insertTail(1);

    samhi.insertTail(2);
    samhi.insertTail(3);
    samhi.insertTail(4);
    samhi.insertTail(5);
    samhi.insertTail(6);
    samhi.insertTail(5);
    samhi.insertTail(3);
    samhi.insertTail(1);
    
    samhi.printList();
    
    std::cout << std::endl;
    
    samhi.removeDuplicatesV2();
    samhi.printList();


    return 0;
}

