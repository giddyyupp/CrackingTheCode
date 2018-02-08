/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTreeSam.h
 * Author: sam
 *
 * Created on February 8, 2018, 7:16 PM
 */

#ifndef BSTREESAM_H
#define BSTREESAM_H

#include "../TreeSam/TreeSam.h"
#include "../TreeSam/TreeSam.cpp"


template<typename T>
class BSTreeSam : public TreeSam<T>{
    
public:
    BSTreeSam();
    BSTreeSam(const BSTreeSam& orig);
    virtual ~BSTreeSam();
private:

};

#endif /* BSTREESAM_H */

