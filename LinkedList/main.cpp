/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 3, 2018, 1:58 PM
 */

#include <cstdlib>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    LinkedList<int> liste_sam;
    
    liste_sam.insertTail(5);
    liste_sam.insertTail(7);
    liste_sam.insertTail(10);
    liste_sam.insertTail(11);

    liste_sam.printList();
    
    std::cout << std::endl;
    
    liste_sam.deleteNode(5);
    
    liste_sam.printList();
    
    bool found = liste_sam.search(5);
        
    std::cout << found << std::endl;

    return 0;
}

