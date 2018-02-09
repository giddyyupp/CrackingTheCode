/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 9, 2018, 3:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>


int mergeNumbers(int i, int j, int num1, int num2);
void printBinary(std::string num);
void printNextSmallestLargest(int num);
std::string convertBinaryRep(int num);
int convertIntRep(std::string num);
int findConvertBits(int num1, int num2);
int findOnesInNumber(int res);
int swapEvenOddBits(int num);


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int num1 = 1024, num2 = 21;
    int i = 2, j = 6;
    
    std::cout << mergeNumbers(i, j, num1, num2) << std::endl;
    
    printBinary("3.72");
    
    std::string aaa = convertBinaryRep(2);
    
    printNextSmallestLargest(12);
    
    int a = findConvertBits(8, 7);
    
    std::cout << a <<std::endl;
    
    a = swapEvenOddBits(8);
    
    std::cout << a <<std::endl;
    
    return 0;
}


/*
 5.1	 You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
     method to set all bits between i and j in N equal to M (e.g., M becomes a substring of
     N located at i and starting at j).
     EXAMPLE:
     Input: N = 10000000000, M = 10101, i = 2, j = 6
     Output: N = 10001010100
 */

int mergeNumbers(int i, int j, int num1, int num2){
    
    int mask = ~0; // all 1 mask
    
    int zeros_after_j = mask - ((1 << j) - 1);
    int ones_after_i = ((1 << i) - 1);
    
    mask = zeros_after_j | ones_after_i;
    return (mask & num1) | (num2 << i);
}


/*
 5.2	 Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary rep-
     resentation. If the number can not be represented accurately in binary, print “ERROR”
 
 */

void printBinary(std::string num){
    
    std::string delim = ".";
    int decimal_part;
    float fraction_part;
    std::string temp = num;
    int frac_counter = 0;
    
    size_t pos = 0;
    std::string token;
    while ((pos = temp.find(delim)) != std::string::npos) {
        token = temp.substr(0, pos);
        decimal_part = atoi(token.c_str());
        temp.erase(0, pos + delim.length());
    }
        
    fraction_part = atof(num.c_str()) - decimal_part;
    
    // higher part
    while (decimal_part != 0){
        std::cout << decimal_part%2;
        decimal_part = decimal_part / 2;
    }
    std::cout << ".";

    // lower part
    while (fraction_part != 0){
        if (frac_counter > 32){ std::cout << std::endl << "ERROR"; return; }
        fraction_part *= 2;
        if (fraction_part >= 1.0){
            std::cout <<  "1";
            fraction_part -= 1.0;
        }
        else{
            std::cout <<  "0";
        }
        frac_counter++;
    }
    
}

void printNextSmallestLargest(int num){
    
    bool largest_not_found = true;
    bool smallest_not_found = true;

    int largest_num, smallest_num;
    std::string orj_num, largest_str, smallest_str;
    std::string bin_num = convertBinaryRep(num);
    orj_num = bin_num;
    
    if (num == 0){ // just break. 
        largest_num = 1;
        return;
    }
    // for largest, start from LSB then find first "0" and swap with right "1".
    // if "0" is in the first place then just shift number 1 left. 
    if(bin_num[bin_num.length()-1] == '0'){
        largest_num = num << 1;
        largest_not_found = false;
    }
    
    for(int i = bin_num.length()-2; largest_not_found && i > 0; i--){
        if(bin_num[i] == '0' && bin_num[i+1] == '1'){ // check prev is 1
            // now swap them and break!!
            bin_num[i] = '1';
            bin_num[i+1] = '0';
            break;
        }
    }
    // now print finally!!
    if(largest_not_found)
        std::cout << "Largets Num: "<< convertIntRep(bin_num) << std::endl;
    else
        std::cout << "Largets Num: "<< largest_num << std::endl;
   
    // for smallest, start from LSB, then find first "1" which has "0" on his right and swap 
    
    for(int i = orj_num.length()-1; i > 1; i--){
        if(orj_num[i] == '1' && orj_num[i+1] == '0'){ // check prev is 1
            // now swap them and break!!
            orj_num[i] = '0';
            orj_num[i+1] = '1';
            smallest_not_found = false;
            break;
        }
    }
    
    if(smallest_not_found)
        std::cout << "Smallest Num Cant be found: " << std::endl;
    else
        std::cout << "Smallest Num: "<< convertIntRep(orj_num) << std::endl;
    
    
}

/*helper*/
std::string convertBinaryRep(int num){
    
    std::string ret = "";
    int cnt = 0;
    // higher part
    while (num != 0){
        ret = std::to_string(num%2) + ret;
        num = num / 2;
        cnt++;
    }
    while (cnt < 32){// put zeros!! 32 bit rep
        ret = '0' + ret;
        cnt++;
    }
    
    return ret;
}

/*helper*/
int convertIntRep(std::string num){
    
    int ret = 0;
    int j = 0;
    // higher part
    for(int i = num.length()-1; i >= 0 ; i--){
        ret += pow (2, j)*(int((num[i]))-48);
        j++;
    }
    return ret;
}


/*
 5.5	 Write a function to determine the number of bits required to convert integer A to
     integer B.	
     Input: 31, 14
     Output: 2
 */
int findConvertBits(int num1, int num2){
    
    int res = num1 ^ num2;
    int cnt = 0;
    
    cnt = findOnesInNumber(res);
    
    return cnt;
    
}

/* helper */
int findOnesInNumber(int res){
    
    int cnt = 0;
    while(res > 0){
        if (res & 1 == 1)
            cnt++;
        res = res >> 1;
    }
    
    return cnt;
}

/*
 5.6	 Write a program to swap odd and even bits in an integer with as few instructions as
     possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).
 */
int swapEvenOddBits(int num){
    
    return ( ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1) );
}