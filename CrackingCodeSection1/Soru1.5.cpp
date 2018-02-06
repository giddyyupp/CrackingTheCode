/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru1.5.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 2:56 PM
 * 
 * 1.5	 Write a method to replace all spaces in a string with ‘%20’.
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

std::string replaceSpace(const std::string& str);
std::string replaceSpaceAmele(const std::string& str);

/*
 * 
 */
int main5(int argc, char** argv) {
    // test 
    std::string str = "ola ola lalal land";
    std::string res = replaceSpaceAmele(str);
    
    std::cout << res << std::endl;

    return 0;
}


std::string replaceSpace(const std::string& str){
    
    std::string res;
    
    for(int i = 0; i < str.length(); i++){
        
        if (str[i] == ' '){
            res += '%';
            res += '2';
            res += '0';
        }
        else{
            res += str[i];
        }
    }
    
    return res;
}


std::string replaceSpaceAmele(const std::string& str){
    
    char* res;
    int new_index = 0;
    
    for(int i = 0; i < str.length(); i++){
        
        if (str[i] == ' '){
            res[new_index++] = '%';
            res[new_index++] = '2';
            res[new_index++] = '0';
        }
        else{
            res[new_index++] = str[i];
        }
    }
    res[new_index] = '\0';
    
    std::string rest(res);
    return rest;
}


