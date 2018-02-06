/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 3, 2018, 3:59 PM
 */

#include <cstdlib>
#include <string.h>
#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"

using namespace std;

/*
 * 
 */
int mainn(int argc, char** argv) {
    
//    DoubleLinkedList<int> liste_sam;
//    
//    liste_sam.insertItem(5);
//    liste_sam.insertItem(7);
//    liste_sam.insertItem(10);
//    liste_sam.insertItem(11);
//
//    liste_sam.print();
//    
//    std::cout << std::endl;
//    
//    liste_sam.deleteItem(5);
//    
//    liste_sam.print();
//    std::cout << std::endl;
//    
//    liste_sam.deleteItem(5);
//    liste_sam.deleteItem(7);
//    liste_sam.deleteItem(12);
//    liste_sam.deleteItem(11);
//    liste_sam.deleteItem(10);
//    liste_sam.deleteItem(5);
//
//    liste_sam.print();
//    std::cout << std::endl;
//     
//    
//    bool found = liste_sam.searchItem(5);
//        
//    std::cout << found << std::endl;
    
    // string
    DoubleLinkedList<std::string> liste_sam_str;
    
    liste_sam_str.insertItem("a");
    liste_sam_str.insertItem("b");
    liste_sam_str.insertItem("b");
    liste_sam_str.insertItem("b");

    liste_sam_str.print();
    
    std::cout << std::endl;
    
    liste_sam_str.deleteItem("b");
    
    liste_sam_str.print();
    std::cout << std::endl;
    
    liste_sam_str.deleteItem("b");
    liste_sam_str.deleteItem("a");
    
    liste_sam_str.print();
    std::cout << std::endl;
    
    

    return 0;
}

