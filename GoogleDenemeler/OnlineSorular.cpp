/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>


// justify strings
void justStr(std::vector<std::string> &str_vec, int K);

/*
 Implement a void function F that takes pointers to two arrays of integers (A and B) and a size N as parameters.
 It then populates B where B[i] is the product of all A[j] where j != i.

For example: If A = {2, 1, 5, 9}, then B would be {45, 90, 18, 10}.
 */
void multArr(int* A, int* B , int size);



int main123123311(){
    
    std::vector<std::string> aaa = {"This","is","an","example","of","text","justification"};
    justStr(aaa, 16);
    
    int A[] = {2, 1, 5, 9};
    int B[4] = {0};
    multArr(A, B, 4);
    
    
    return 0;
}

void multArr(int* A, int* B , int size){
    
    int mult = 1;
    for(int i = 0; i < size; ++i){
        mult *= A[i];
    }
    
    for(int i = 0; i < size; ++i){
       B[i] = mult/ A[i]; 
    }
    
    for(int i = 0; i < size; ++i){
       std::cout << B[i] << " "; 
    }
    
}


void justStr(std::vector<std::string> &str_vec, int K){
    
    std::string line = "\"";
    int index = 0;
    
    while(index < str_vec.size()){
        if(line.size() <= K+1){
            line = line + str_vec[index] + " ";
            if (line.size() > K+1){// eger son ekledigimiz overflow yaptiysa bunu discard edelim.
                line = line.substr(0, line.size()-(str_vec[index].length()+2)); // remove last two spaces!!
                line += ",\"";
                std::cout << line << std::endl;
                line = "\"";
                index--;
            }
            else{
            }
            index++;
        }
        else{
        }
    }
    
    line = line.substr(0, line.size()-1);
    line +=  ",\"";
    std::cout << line << std::endl;
}