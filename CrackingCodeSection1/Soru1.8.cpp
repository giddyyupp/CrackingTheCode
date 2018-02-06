/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru1.8.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 5:06 PM
 * 
 * 1.8	 Assume you have a method isSubstring which checks if one word is a substring of
     another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
     only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).

 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

bool isRotated(const std::string& str1, const std::string& str2);

using namespace std;

/*
 * 
 */
int main8(int argc, char** argv) {
    // test
    std::string str1 = "waterbottle";
    std::string str2 = "erbottlewat"; // qweqeqqweq
    
    bool res = isRotated(str1, str2);
    std::cout << res << std::endl;
    
    return 0;
}


bool isRotated(const std::string& str1, const std::string& str2){
    
    // size check
    if (str1.length() != str2.length())
        return false;
    
    bool rotated = false;
    std::string appended = str2 + str2;
    
    if (appended.find(str1) != std::string::npos) {
        std::cout << "found!" << '\n';
        rotated = true;
    }
    else{
        std::cout << "Not found!" << '\n';
        rotated = false;
    }
    
    return rotated;    
}
