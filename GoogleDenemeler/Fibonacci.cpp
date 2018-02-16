/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <vector>

int findFibonacci(int n);
int findFibonacciIter(int n);

int main(){
    
    
    for ( int i = 0; i < 11; i++ ) {
        printf("%d, ", findFibonacciIter(i));
    }
    //int aa = findFibonacci(9);
    //printf("%d", aa);
    
    return 0;
}

int findFibonacci(int n){
    
    static std::vector<int> fib_table;
    
    if (n <= 1)
        return n;
    else if(n >= fib_table.size())
        fib_table.resize(n+1);

    if (fib_table[n] == 0){
        fib_table[n] = findFibonacci(n-1) + findFibonacci(n-2); 
    }
    else
        return fib_table[n];

}

int findFibonacciIter(int n){
    
    std::vector<int> fib_table(n+1);
    
    if (n <= 1)
        return n;
    
    fib_table[0] = 0;
    fib_table[1] = 1;
    
    for(int i = 2; i <= n; ++i){
        fib_table[i] = fib_table[i-1] + fib_table[i-2];
    }
    
    return fib_table[n];
}