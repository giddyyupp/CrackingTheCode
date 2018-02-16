/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <array>


bool findElemInMatrix(const int mat[][5], int row, int col, const int find);


int strCompareSam(std::string str1, std::string str2);
std::string sortChars(std::string str1);

int findInRotatedArray(int rotA[], int val);
int binarySearchRotated(int rotA[], int min, int max, int size, int goo);
int binarySearch(int rotA[], int min, int max, int size, int val); 
int binarySearchIter(int rotA[], int min, int max, int val); 
int binarySearchIterModified(std::string rotA[], int min, int max, std::string val); 

template<typename T>
void mergeTwoArrays(T a1[], T a2[], int size1, int size2);

template<typename T>
void merge(T a[], T aux[], int lo, int mid, int hi, int a_size);

        
        
int main(){
    
//    int row = 5, col = 5;
//    int arr[5][5] = {2 , 3, 5, 7, 10, 4, 9, 15, 2, 21, 6, 14, 17, 23, 89, 19, 25, 28, 31, 33,36, 39, 45, 49, 56};
//    bool res =  findElemInMatrix(arr , row, col, 30);
//    std::cout << res << std::endl;
//   
////    std::vector<std::string> aaaa = {"sam", "asm", "kucuk"};
//    std::vector<std::string> aaaa = {"listen", "nermin", "samhi", "nimren", "silent"};
//    std::sort(aaaa.begin(), aaaa.end(), strCompareSam);
//    int rotA[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
//    int rotA[] = { 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14, 15};
//    int rest = findInRotatedArray(rotA, 10);
    
//    int a1[] = { 3, 5, 11, 0, 0, 0, 0};
//    int a2[] = { 2, 4, 6, 8};
//    mergeTwoArrays<int>(a1, a2, 3, 4);

//    int rotA[] = { 1, 3, 4, 5, 7, 10, 14, 15, 16, 19, 20, 25};
//    int res = binarySearchIter(rotA, 0, sizeof(rotA)/sizeof(int), 1); 
//    std::cout << res << std::endl;
    
    std::string str_arr[] =  {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    int resss = binarySearchIterModified(str_arr, 0, 12, "dad");
    std::cout << resss << std::endl;
    
    return 0;
}

/*
 9.5	 Given a sorted array of strings which is interspersed with empty strings, write a meth-
     od to find the location of a given string.
     Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”, “”] will return 4
     Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
 * 
 */


int binarySearchIterModified(std::string str_arr[], int min, int max, std::string val){
    
    while(min <= max){
        
//        while(min <= max && str_arr[max] == "")
//            max--;
//        if(min > max)
//            return -1;
        
        int mid = (min + max) / 2;
        
        while (str_arr[mid] == "") {
           mid++; // will always find one
        }

        if(val == str_arr[mid]){
            return mid;
        }
        else if(val > str_arr[mid]){
            min = mid + 1;
        }else{
            max = mid - 1;
        }
    }
}


template<typename T>
void merge(T a[], T aux[], int lo, int mid, int hi, int a_size){
    
    int i = lo, j = mid+1;
    memcpy(aux, a, a_size);
    
    for (int k = lo; k <= hi; k++ ){
        if (i > mid) a[k] = aux[j++];
        else if (j > hi) a[k] = aux[i++];
        else if (aux[i] < aux[j]) a[k] = aux[i++]; 
        else a[k] = aux[j++]; 
    }
}

/*
 9.1	 You are given two sorted arrays, A and B, and A has a large enough buffer at the end
     to hold B. Write a method to merge B into A in sorted order.
 */
template<typename T>
void mergeTwoArrays(T a1[], T a2[], int size1, int size2){
    
    int i = size1-1, j = size2-1;
    int place = size1 + size2 -1;
    
    while(j >= 0){ // 
        if (i < 0) a1[place--] = a2[j--];
        else if (a1[i] > a2[j]){ a1[place--] = a1[i--];}
        else a1[place--] = a2[j--]; // a1[i] < a2[i]
    }
}


int findInRotatedArray(int rotA[], int val){
    
    // find rot point first
    int goo = 1;
    if (rotA[0] < val)
        goo = 0;
    int rotPoint = binarySearchRotated(rotA, 0, 12, 12, goo); // sizeof(rotA)/sizeof(int)
    std::cout << rotPoint << std::endl;
    // now call regular binary search. 
    int ress;
    // now call regular binary search. 
    if (rotA[0] > val || rotPoint == 0){
        ress = binarySearch(rotA, rotPoint, 12, 12, val);
    }
    else{
        ress = binarySearch(rotA, 0, rotPoint, 12, val);
    }
    std::cout << ress << std::endl;
    
    return ress;

        
}

int binarySearchRotated(int rotA[], int min, int max, int size, int goo){
    
    int mid = min + (max - min)/2; 
    
    if (mid >= size-1)
        return size-1;
    if(mid <= 0)
        return 0;
    
    if(rotA[mid] < rotA[mid-1])
        return mid;
    else{
        if (goo)
            return binarySearchRotated(rotA, mid+1, max, size, goo);
        else
            return binarySearchRotated(rotA, min, mid-1, size, goo);
    }
    
}

int binarySearch(int rotA[], int min, int max, int size, int val){
    
    int mid = min + (max - min)/2; 
    
    if(mid < 0 || mid > size-1)
        return -1; // not found 
    
    if(rotA[mid] == val)
        return mid;
    else if (rotA[mid] < val){
        return binarySearch(rotA, mid+1, max, size, val);
    }
    else{
        return binarySearch(rotA, min, mid-1, size, val);
    }
    
}

int binarySearchIter(int rotA[], int min, int max, int val){
    
    while(min <= max){
        
        int mid = (min + max) >> 1; 
        
        if (val == rotA[mid]){
            return mid;
        }
        else if (val < rotA[mid]){
            max = mid-1;
        }
        else{
            min = mid+1;
        }
    }
    
}


int strCompareSam(std::string str1, std::string str2){
    std::string res1 = sortChars(str1);
    std::string res2 = sortChars(str2);

    int res = res1.compare(res2);
    
    return res;
}

std::string sortChars(std::string str){
    
    std::sort(str.begin(), str.end());
    return str;
}


/*
 9.6	 Given a matrix in which each row and each column is sorted, write a method to find
     an element in it.

 */
bool findElemInMatrix(const int mat[][5], int row, int col, const int find){
    
    int r = row-1;
    int c = 0;
    
    while(r >= 0 && c < col){
        
        if(mat[r][c] == find)
            return true;
        if (mat[r][c] > find)
            r--;
        else{
            c++;
        }
    }
    
    return false;
}