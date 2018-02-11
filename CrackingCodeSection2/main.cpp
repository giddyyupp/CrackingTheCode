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
#include <queue>
#include <map>



/* part 5*/
int mergeNumbers(int i, int j, int num1, int num2);
void printBinary(std::string num);
void printNextSmallestLargest(int num);
std::string convertBinaryRep(int num);
int convertIntRep(std::string num);
int findConvertBits(int num1, int num2);
int findOnesInNumber(int res);
int swapEvenOddBits(int num);

/* part 6*/
int nthFibo(int n);
template<typename T>
std::vector<T> findSubs(std::vector<T> set);
int findkthPrimeFactor(int k);
int findkthPrimeFactorBruteForce(int k);
int findSmallestInQueues(std::queue<int> &q3, std::queue<int> &q5, std::queue<int> &q7);


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    /* part 5 tests*/
    /*int num1 = 1024, num2 = 21;
    int i = 2, j = 6;
    
    std::cout << mergeNumbers(i, j, num1, num2) << std::endl;
    
    printBinary("3.72");
    
    std::string aaa = convertBinaryRep(2);
    
    printNextSmallestLargest(12);
    
    int a = findConvertBits(8, 7);
    
    std::cout << a <<std::endl;
    
    a = swapEvenOddBits(8);
    
    std::cout << a <<std::endl;*/
    
    /* part 6 tests*/
    
//    int nn = nthFibo(8);
//    std::cout << nn << std::endl;
    
//    std::vector<int> set{1,2,3};
//    std::vector<int> res = findSubs(set);
//    for(int i = 0; i < res.size(); i++){
//        std::cout << res[i] << " ";
//    }
    
    int asdadas =  findkthPrimeFactor(14);
    std::cout << asdadas << std::endl;
    
    int asdf = findkthPrimeFactorBruteForce(14);
    std::cout << asdf << std::endl;

    
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


/*
 8.1	 Write a method to generate the nth Fibonacci number.
 */
int nthFibo(int n){
    
    if (n <= 1)
        return n;
    else
        return nthFibo(n-1) + nthFibo(n-2);
}


/*
    8.3	 Write a method that returns all subsets of a set.
 */
template<typename T>
std::vector<T> findSubs(std::vector<T> set){
    
    std::vector<T> res;
    int max_subset = 1 << set.size(); // 2^n subset max
    
    for(int i = 0; i < max_subset ; i++){
        int k = i ;
        int index = 0;
        while(k > 0){
            if ((k & 1) > 0){
                res.push_back(set[index]);
            }
            k = k >> 1;
            index++;
        }
    }
    
    return res;
}

int findSmallestInQueues(std::queue<int> &q3, std::queue<int> &q5, std::queue<int> &q7){
    
    int min = 0;
    int q_index = 1;
    
    if(q3.front() < q5.front() && q3.front() < q7.front()){
        min = q3.front();
        q_index = 3;
    }
    else if(q5.front() < q7.front() && q5.front() < q3.front()){
        min = q5.front();
        q_index = 5;
    }
    else{
        min = q7.front();
        q_index = 7;
    }

    
    switch(q_index){
        case 3:
            q3.push(min * 3);
            q5.push(min * 5);
            q7.push(min * 7);
            q3.pop();
            break;
        case 5:
            q5.push(min * 5);
            q7.push(min * 7);
            q5.pop();
            break;
        case 7:
            q7.push(min * 7);
            q7.pop();
            break;
        default:
            break;
    }
    
    return min;
}


int findkthPrimeFactor(int k){
    
    int smallest = 0;
    int counter = 1;
    std::vector<int> nums;
    std::queue<int> q3, q5, q7;
    
    q3.push(3); q5.push(5); q7.push(7); 
    
    nums.push_back(1);
    
    while(counter < k){
        
        smallest = findSmallestInQueues(q3,q5,q7);
        nums.push_back(smallest);
        
        counter++;
    }
    
    return smallest;
}

int findkthPrimeFactorBruteForce(int k){
    
    int counter = 0;
    std::vector<int> nums;
    std::map<int, int> m_sam;
    int fr = 0;
    int res = 0;
    
    nums.push_back(1);
    
    while (counter < 2 * k - 1){ // to be guarenteed
        fr= nums[counter];
        nums.push_back(fr*3); nums.push_back(fr*5); nums.push_back(fr*7);
        counter++;
    }
    
    std::pair<std::map<int,int>::iterator,bool> ret;
    for(int i = 0; i < nums.size(); i++){
        ret = m_sam.insert ( std::pair<int,int>(nums[i], nums[i]) );
    }
    counter = 0;
    // showing contents:
    std::map<int,int>::iterator it = m_sam.begin();
    for (it=m_sam.begin(); it!=m_sam.end() ; ++it, counter++){
        //std::cout << it->first << " => " << it->second << '\n';
        if (counter == k-1){
            res = it->first;
            break;
        }
    }
    
    return res;
    
    
    
}