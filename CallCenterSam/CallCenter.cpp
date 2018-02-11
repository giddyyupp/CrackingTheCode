/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CallCenter.cpp
 * Author: sam
 * 
 * Created on February 9, 2018, 11:46 PM
 */

#include <vector>

#include "CallCenter.h"

CallCenter::CallCenter() {
}


CallCenter::CallCenter(const CallCenter& orig) {
}


CallCenter::~CallCenter() {
}


void CallCenter::addEmployee(Employee* emp){
    fresher_list.push_back(emp);
}

Employee* CallCenter::getCallHandler(){
    // first search for free emp
    for(int i = 0; i < fresher_list.size(); i++){
        if (fresher_list[i]->isFree())
            return fresher_list[i];
    }
    if (m_tl->isFree())
        return m_tl;
    
    if (m_pm->isFree())
        return m_pm;
    
    return NULL;
}

void CallCenter::setTL(Employee* tl){
    m_tl = tl;
}

void CallCenter::setPM(Employee* pm){
    m_pm = pm;
}
