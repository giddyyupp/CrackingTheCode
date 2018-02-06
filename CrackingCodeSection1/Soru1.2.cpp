/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru1.2.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 1:30 PM
 * 
 * 1.2 Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
five characters, including the null character.)
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


std::string reverseStr(std::string& str);

/*
 * 
 */
int main2(int argc, char** argv) {
       // test
    std::string olalala = "deneme1 samet";
    std::string res = reverseStr(olalala);
    
    std::cout << olalala << std::endl;

    return 0;
}


std::string reverseStr(std::string& str){
    
    int str_size = str.length() - 1;
    char *ch_array = &str[0];
    
    for(int i = 0; i < str_size/2; i++ ){
        char temp = ch_array[i];
        ch_array[i] = ch_array[str_size-i];
        ch_array[str_size-i] = temp;
    }
    
    std::string res(ch_array);
    return res;
}



