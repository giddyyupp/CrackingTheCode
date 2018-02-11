/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fresher.h
 * Author: sam
 *
 * Created on February 9, 2018, 11:02 PM
 */

#ifndef FRESHER_H
#define FRESHER_H

#include "./Employee.h"

class Fresher : public Employee{
 
public:
    Fresher();
    Fresher(std::string name_);
    ~Fresher();
};

#endif /* FRESHER_H */

