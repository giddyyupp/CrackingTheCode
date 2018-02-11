/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: sam
 *
 * Created on February 9, 2018, 10:58 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
    
public:
    Employee();
    Employee(std::string name_);
    ~Employee();
    
    void setName(std::string new_name);
    std::string getName();
    void setID(int id_);
    int getID();


    bool isFree();
    void setFree(bool free_);
    
    int getEmployeeCount();

protected:
    std::string name;
    int id;
    bool free;
    static int employee_count;

};

#endif /* EMPLOYEE_H */

