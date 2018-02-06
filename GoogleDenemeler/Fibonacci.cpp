/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>

int findFibonacci(int n);

int mainnnwqeq(){
    
    
    for ( int i = 0; i < 11; i++ ) {
        printf( "%d, ", findFibonacci(i) );
    }
    //int aa = findFibonacci(9);
    //printf("%d", aa);
    
    return 0;
}

int findFibonacci(int n){
    
    if (n <= 1)
        return n;
    else
        return findFibonacci(n-1) + findFibonacci(n-2); 
}

