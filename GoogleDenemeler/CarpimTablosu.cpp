/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>

void carpimTablosu(int n);

int mainnnsada(){
    
    carpimTablosu(11);
    
    return 0;
}

void carpimTablosu(int n){
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            
            printf("%4d ", i*j);
        }
        printf("\n");
    }
    
}