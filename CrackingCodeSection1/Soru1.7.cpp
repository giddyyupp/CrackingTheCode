/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soru1.7.cpp
 * Author: sam
 *
 * Created on February 5, 2018, 4:37 PM
 * 
 * 1.7	 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
     column is set to 0.

 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

void clearZeroFromMatrix(int* matrix, int M, int N);

/*
 * 
 */
int main7(int argc, char** argv) {
    // test
    int M = 5, N = 4;
    int matrix[M*N];
     
    for (int i = 0; i < M*N; i++) //init
            matrix[i] = i;
    
    matrix[10] = 0;
            
    for (int i=0;i<M;i++){ //init
        for (int j=0;j<N; j++){ //init
            std::cout << matrix[i*N+j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    clearZeroFromMatrix(&matrix[0], M, N);
    
    for (int i=0;i<M;i++){ //init
        for (int j=0;j<N; j++){ //init
            std::cout << matrix[i*N+j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}


void clearZeroFromMatrix(int* matrix, int M, int N){
    
    std::vector<std::tuple<int,int>> zero_indices;
    
    // first pass mark 0 indices
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (0 == matrix[i*N + j])
                zero_indices.push_back(std::make_tuple(i , j));
        
        
    // now clear zeros!!
    for (int i = 0; i < zero_indices.size(); i++){
        int row = std::get<0>(zero_indices[i]);
        int col = std::get<1>(zero_indices[i]);
        
        for (int i = 0; i < M; i++) // update rows
            matrix[i*N + col] = 0;
        for (int j = 0; j < N; j++) // update cols
            matrix[row*N + j] = 0;
    }
    
}