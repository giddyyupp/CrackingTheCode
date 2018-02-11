/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductManager.h
 * Author: sam
 *
 * Created on February 9, 2018, 11:38 PM
 */

#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include "Employee.h"

class ProductManager : public Employee{
    
private:
    static ProductManager* m_pm;
    ProductManager();
    
public:
    static ProductManager* getInstance();
    
};



#endif /* PRODUCTMANAGER_H */

