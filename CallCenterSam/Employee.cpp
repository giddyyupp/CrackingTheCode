/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.cpp
 * Author: sam
 * 
 * Created on February 9, 2018, 10:58 PM
 */

#include "Employee.h"

int Employee::employee_count = 0;

Employee::Employee() {
    Employee::employee_count++;
    free = true;
    id = Employee::employee_count;
}

Employee::Employee(std::string name_) {
    Employee::employee_count++;
    name = name_;
    id = Employee::employee_count;
}

Employee::~Employee() {
}


bool Employee::isFree(){
    return free;
}

void Employee::setFree(bool free_){
    free = free_;
}

void Employee::setName(std::string new_name){
    name = new_name;
}

int Employee::getEmployeeCount(){
    
    return Employee::employee_count;
}

std::string Employee::getName(){
    return name;
}

int Employee::getID(){
    return id;
}
