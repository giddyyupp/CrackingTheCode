/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 4, 2018, 11:46 AM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
void sort(T* array, T* aux, int lo, int hi);

template<typename T>
void merge(int lo, int mid, int hi, T* array, T* aux);


/*
 * 
 */
int main(int argc, char** argv) {

    // lets create a reverse sorted list
    int array[1024], aux[1024];
    for (int i = 1023; i >= 0; i--)
        array[i] = 1023-i;
    
    for (int i = 1023; i >= 0; i--)
        aux[i] = 0;
    
    // print original list list
    for (int i = 0; i < 1024; i++)
        std::cout << array[i] << " ";
    
    sort(array, aux, 0, 1023);
    
    // print sorted list
    for (int i = 0; i < 1024; i++)
        std::cout << array[i] << " ";
    
    return 0;
}

template<typename T>
void sort(T* array, T* aux, int lo, int hi){
    
    if (hi <= lo)
        return;
    
    int mid = lo + (hi - lo) / 2;
    
    sort(array, aux, lo, mid);
    sort(array, aux, mid+1, hi);
    merge(lo, mid, hi, array, aux);
}


template<typename T>
void merge(int lo, int mid, int hi, T* array, T* aux){
    
    int ii = lo, jj = mid+1, k = lo;
//    memcpy(&aux[lo], &array[lo], hi-lo); // copy a to aux, duzelt
    for (int i = lo; i <= hi; i++){
        aux[i] = array[i];
    }
    
    for (int k = lo; k <= hi; k++){
        if (ii > mid) array[k] = aux[jj++]; // left array is over, copy from right
        else if (jj > hi) array[k] = aux[ii++]; // right array is over, copy from left
        else if (aux[jj] < aux[ii]) array[k] = aux[jj++];
        else array[k] = aux[ii++];
    }
}
