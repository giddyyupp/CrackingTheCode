/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TechnicalLeader.h
 * Author: sam
 *
 * Created on February 9, 2018, 11:18 PM
 */

#ifndef TECHNICALLEADER_H
#define TECHNICALLEADER_H

#include "Employee.h"
#include <iostream>

class TechnicalLeader : public Employee {

private:
    /* Here will be the instance stored. */
    static TechnicalLeader* m_p_instance;

    /* Private constructor to prevent instancing. */
    TechnicalLeader();

public:
    /* Static access method. */
    static TechnicalLeader* getInstance();
    

    ~TechnicalLeader();
    
};



#endif /* TECHNICALLEADER_H */

