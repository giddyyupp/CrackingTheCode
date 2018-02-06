/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru1.6.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 3:15 PM
 * 
 * 1.6	 Given an image represented by an NxN matrix, where each pixel in the image is 4
     bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void rotate90Degree(int* image, int N);

/*
 * 
 */
int main6(int argc, char** argv) {
    // test
    int N = 4;
    int image[N*N];
    
    for (int i = 0; i < N*N; i++) //init
            image[i] = i;
            
    for (int i=0;i<N;i++){ //init
        for (int j=0;j<N; j++){ //init
            std::cout << image[i*N+j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
   
    // rotate90Degree
    rotate90Degree(&image[0], N);
    
    /// print res
    for (int i=0;i<N;i++){ //init
        for (int j=0;j<N; j++){ //init
            std::cout << image[i*N + j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

/*
 0 1 2 3 
4 5 6 7 
8 9 10 11 
12 13 14 15 
 * transpose:
0 4 8 12
1 5 9 13 
2 6 10 14 
3 7 11 15 
 
 */

void rotate90Degree(int* image, int N){

    int temp = 0;
    
    // transpose first inplace
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int new_ind = j*N + i;
            int old_ind = i*N + j;
            temp = image[old_ind];
            image[old_ind]= image[new_ind];
            image[new_ind] = temp;
        }
    }
    // print transpose
    for (int i=0;i<N;i++){ //init
        for (int j=0;j<N; j++){ //init
            std::cout << image[i*N + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    // now swap inplace
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N/2; j++){
            temp = image[j*N + i];
            image[j*N + i] = image[(N-1-j)*N + i];
            image[(N-1-j)*N + i] = temp;
        }
    }
    
    // print swap
    for (int i=0;i<N;i++){ //init
        for (int j=0;j<N; j++){ //init
            std::cout << image[i*N + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
}

