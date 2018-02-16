/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 16, 2018, 12:49 PM
 */

#include <cstdlib>
#include <iostream>

/*
 QuickSort
 */
template<typename T>
void sort(T arr[], int lo, int hi);
template<typename T>
int partition(T arr[], int lo, int hi);

template<typename T>
void swap(T arr[], int ind1, int ind2);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    // lets create a reverse sorted list
    int array[1024];
    for (int i = 1023; i >= 0; i--)
        array[i] = 1023-i;
    
    sort<int>(array, 0, 1023);
    
    // print sorted list
    for (int i = 0; i < 1024; i++){
        std::cout << array[i] << " ";
        if (array[i] != i){
            std::cout << "ERRORR!!! ";
            return 1;
        }
    }

    return 0;
}

template<typename T>
void sort(T arr[], int lo, int hi){
    if(hi <= lo)
        return;
    
    int part = partition<T>(arr, lo, hi);
    sort(arr, lo, part-1);
    sort(arr, part+1, hi);
}

template<typename T>
int partition(T arr[], int lo, int hi){
    
    int low= lo; int high = hi+1;
    int part_val = arr[lo];
    
    while(1){
        while(arr[++low] < part_val) if (low == hi) break;
        while(arr[--high] > part_val) if (high == lo) break;
        if (low >= high) break;
        swap(arr, low, high);
    }
    // finally place partition element
    swap(arr, lo, high);
    return high;
}

template<typename T>
void swap(T arr[], int ind1, int ind2){
    
    T temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
    
    
}
