/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.h
 * Author: sam
 *
 * Created on January 31, 2018, 11:02 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {
private:
     T* elem; // elem points to an array of sz elements of type T
     int sz;
public:
     Vector(int s);                    // constructor: establish invariant, acquire resources
     ~Vector() ;      // destructor: release resources
     // ... copy and move operations ...
     T& operator[](int i);
     const T& operator[](int i) const;
     int size() const { return sz; }
};


#endif /* VECTOR_H */

