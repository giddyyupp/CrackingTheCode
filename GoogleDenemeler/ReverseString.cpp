/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on January 31, 2018, 9:52 PM
 */


#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>

std::string reverseString_v1(std::string str);
std::string reverseString_v2(std::string str);

using namespace std;

/*
 * 
 */
int mainnn(int argc, char** argv) {

    std::string aaa = "Deneme 1 2 3 4~~!!!";
    
    std::string rever = reverseString_v1(aaa);
    printf("%s\n", rever.c_str());
    
    rever = reverseString_v2(aaa);
    printf("%s\n", rever.c_str());
    
    return 0;
}

std::string reverseString_v1(std::string str){
    
    int str_size = str.length()-1;
    char *ch_array = &str[0];
    
    for(int i = 0; i < str_size / 2; i++){
        char temp = ch_array[i];
        ch_array[i] = ch_array[str_size-i];
        ch_array[str_size-i] = temp;        
    }
    
    std::string res(ch_array);
    return res;    
}

std::string reverseString_v2(std::string str){
    
    int str_size = str.length()-1;
    char* ch_arr = &str[0];
    
    for (int i = str_size; i > str_size/2; i--){
        char temp = ch_arr[i];
        ch_arr[i] = ch_arr[str_size-i];
        ch_arr[str_size-i] = temp;
    }
    std::string res(ch_arr);
    
    return res;
}

