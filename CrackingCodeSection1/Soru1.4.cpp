/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru1.4.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 1:55 PM
 * 
 * 1.4	 Write a method to decide if two strings are anagrams or not.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

bool isAnagram(const std::string& str1, const std::string& str2);

/*
 * 
 */
int main4(int argc, char** argv) {
    // test1 anagram
    std::string str1 = "samhie";
    std::string str2 = "amsihe";
    bool res = isAnagram(str1, str2);
    std::cout << res << std::endl;
    
    // test2 not anagram
    std::string str11 = "osman";
    std::string str22 = "samet";
    res = isAnagram(str11, str22);
    std::cout << res << std::endl;
    
    return 0;
}

bool isAnagram(const std::string& str1, const std::string& str2){
    
    bool isAna = true;
    std::map<char, int> ana_map;
    
//    std::string at = str1;
//    std::sort(at.begin(), at.end());
    
    if (str1.length() != str2.length())
        return false;
    
    // insert chars from str1
    for(int i = 0; i < str1.length(); i++){
        ana_map[str1[i]]++;
    }
    // now remove chars from map using str2
    for(int i = 0; i < str2.length(); i++){
        ana_map[str2[i]]--;
        if (ana_map[str2[i] < 0]){ // if any item in the map goes to negative!! early check.
            isAna = false;
            break;
        }
    }
    // final check 
    for(int i = 0; i < str1.length(); i++){
         if(ana_map[str1[i]] > 0)
             isAna = false;
    }
    
    return isAna;
}

