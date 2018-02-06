/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.cpp
 * Author: sam
 * 
 * Created on January 31, 2018, 11:02 PM
 */

#include "Vector.h"


template<typename T>
Vector<T>::Vector(int s) {
    sz = s;
}

template<typename T>
Vector<T>::~Vector() {
    if (elem)
        delete[] elem; 
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
    if (i<0 || size()<=i)
        //throw out_of_range{"Vector::operator[]"};
    return elem[i];
}


