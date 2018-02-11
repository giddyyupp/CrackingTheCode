/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CallCenter.h
 * Author: sam
 *
 * Created on February 9, 2018, 11:46 PM
 */

#ifndef CALLCENTER_H
#define CALLCENTER_H

#include "Employee.h"
#include <vector>


class CallCenter {
public:
    CallCenter();
    CallCenter(const CallCenter& orig);
    virtual ~CallCenter();
    
    void addEmployee(Employee* emp);
    Employee* getCallHandler();
    
    void setTL(Employee* tl);
    void setPM(Employee* tl);

    std::vector<Employee*> fresher_list;
    
private:
    Employee* m_tl;
    Employee* m_pm;
};

#endif /* CALLCENTER_H */

