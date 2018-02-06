/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru1.3.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 1:39 PM
 * 
 * 1.3	 Design an algorithm and write code to remove the duplicate characters in a string
     without using any additional buffer. NOTE: One or two additional variables are fine.
     An extra copy of the array is not.
     FOLLOW UP
     Write the test cases for this method.
 * 
 * Test Cases:
1.	  String does not contain any duplicates, e.g.: abcd
2.	  String contains all duplicates, e.g.: aaaa
3.	  Null string
4.	  Empty string
5.	  String with all continuous duplicates, e.g.: aaabbb
6.	  String with non-contiguous duplicates, e.g.: abababa


 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

std::string removeDuplicateChar(std::string& str);

/*
 * 
 */
int main3(int argc, char** argv) {
    
    //test
    std::string  sam = "aaabbb";
    removeDuplicateChar(sam);
    
    std::cout << sam <<std::endl;
    

    return 0;
}

std::string removeDuplicateChar(std::string& str){
    
    // checks
    if (str.empty()) return str;
    if (str.length() < 2) return str;
    
    char curr;
    
    for (int i = 0; i < str.length(); i++){
        curr = str[i];
        for(int j = i+1; j < str.length();){
            if (curr == str[j]){
                str.erase(str.begin()+ j);
            }
            else
                j++;
        }
    }
    return str;
}


