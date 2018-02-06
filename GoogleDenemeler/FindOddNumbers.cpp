/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <stdio.h>
#include <iostream>

void printOddNumbers(int max);

int mainqweeqweqqweqweq(){
    
    printOddNumbers(100);
    return 0;
}

void printOddNumbers(int max){
    
    for (int i = 1; i < max; i++){
        if (i%2 == 1)
            printf("%d ", i);
    }
    
    printf("\n");

    for (int i = 1; i < max; i+=2){
        printf("%d ", i);
    }
}