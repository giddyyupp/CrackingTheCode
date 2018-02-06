/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <limits.h>

template<typename T>
T findMax(T[]);

template<typename T>
T findMin(T a[]);

int main(){
    
    int aa[11] = {10,9,8,7,66,5,4,3,2,88,0};
    int max = findMax(aa);
    
    std::cout << max << std::endl;
    
    int min = findMin(aa);
    printf("%d\n", min);
    std::cout << min << std::endl;
    
    return 0;
}


template<typename T>
T findMax(T a[]){
    
    T max_elem = INT_MIN;
    int size_ = sizeof(a)/sizeof(a[0]);
    for (T i = 0; i < size_; i++){
        max_elem = a[i] > max_elem ? a[i] : max_elem;
    }
    
    return max_elem;
}

template<typename T>
T findMin(T a[]){
    
    T min_elem = -1000000000000;
    int size_ = sizeof(a)/sizeof(a[0]);

    for (T i = 0; i < size_; i++){
        min_elem = a[i] < min_elem ? a[i] : min_elem;
    }
    
    return min_elem;
}