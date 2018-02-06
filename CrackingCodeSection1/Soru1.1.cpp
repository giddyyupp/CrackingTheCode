/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 11:56 AM
 * 
 * 1.1	 Implement an algorithm to determine if a string has all unique characters. What if you
     can not use additional data structures?

 */

#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <tuple>


using namespace std;

bool hasUniqueChar(const std::string& str);
bool hasUniqueCharMap(const std::string& str);
bool hasUniqueCharBit(const std::string& str);

/*
 * 
 */
int main1(int argc, char** argv) {
    
    // test
    std::string adsda = "alai";
    bool aha = hasUniqueChar(adsda);
    std::cout << aha << std::endl;
    
    bool aha2 = hasUniqueCharMap(adsda);
    std::cout << aha2 << std::endl;
    
    bool aha3 = hasUniqueCharBit(adsda);
    std::cout << aha3 << std::endl;

    

    return 0;
}

bool hasUniqueChar(const std::string& str){
    
    bool isUnique = true;
    int asci_arr[128];
    memset(asci_arr, 0, 128*sizeof(int));
    
    for(int i = 0; i < str.length(); i++){
        asci_arr[int(str[i])]++;
        if (asci_arr[int(str[i])] > 1){
            isUnique = false;
            break;
        }
    }
    
    return isUnique;
}

bool hasUniqueCharMap(const std::string& str){
    
    bool isUnique = true;
    bool res = true;

    std::map<char, int> ch_int_map;
    
    for(int i = 0; i < str.length(); i++){
        res =  std::get<1>(ch_int_map.insert(std::make_pair(str[i], 1)));
        if (!res){
            isUnique = false;
            break;
        }
    }
    
    return isUnique;
}


bool hasUniqueCharBit(const std::string& str){
    
    bool isUnique = true;
    int checker = 0;
    
    for(int i = 0; i < str.length(); i++){
        int val = str[i] - 'a';
        if ((checker & (1 << val)) > 0){
            isUnique = false;
            break;
        }
        checker |= (1 << val);
    }
    
    return isUnique;
}






