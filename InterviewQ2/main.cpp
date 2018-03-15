/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 25, 2018, 11:39 AM
 */

#include <cstdlib>
#include "NaryTree.h"
#include "NaryTree.cpp"

void calculate_probs(int sum, double curr_prob);

std::array<double, 22> probs;
std::array<int, 10 > cardValues;

/* My google software development interview question 2. 
 * but i missed this simple question. damn!!!
 */
int main(int argc, char** argv) {
    
    probs.fill(0.0);
    
    for (int i = 0; i < 10; ++i){
        cardValues[i] = i + 1;
    }
    
    calculate_probs(0, 0.1);
    
    for (int i = 0; i < 22; ++i){
        std::cout << probs[i] << std::endl;
    }

    return 0;
}


void calculate_probs(int sum, double curr_prob){
    
    if (sum > 21)
        return;
    if (sum  >= 17){
        probs[sum] += curr_prob;
        return;
    }
    if (sum > 0)
        probs[sum] += curr_prob;
    for(int j = 0; j < 10; ++j)
        calculate_probs(sum + cardValues[j], curr_prob*0.1);
}

// results from rust:
//[(1.0,0.1),(2.0,0.11),(3.0,0.121),(4.0,0.1331),
//        (5.0,0.14641),
//        (6.0,0.161051),(7.0,0.17715609999999998),(8.0,0.19487171),
//        (9.0,0.214358881),(10.0,0.23579476910000002),(11.0,0.15937424601),
//        (12.0,0.165311670611),(13.0,0.1708428376721),
//        (14.0,0.17582712143931),(15.0,0.180099833583241),(16.0,0.1834688169415651),
//        (17.0,0.18571059863572162),(18.0,0.16799498863572163),(19.0,0.14850781763572163),
//        (20.0,0.12707192953572163),(21.0,0.10349245262572163)]
//0.7327777870686082