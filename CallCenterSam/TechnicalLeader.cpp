/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TechnicalLeader.h"

/* Null, because instance will be initialized on demand. */
TechnicalLeader* TechnicalLeader::m_p_instance = 0;

/* Static access method. */
TechnicalLeader* TechnicalLeader::getInstance(){
    
    if (m_p_instance == 0)
        m_p_instance = new TechnicalLeader;
    
    return m_p_instance;
}

TechnicalLeader::TechnicalLeader(){
}


TechnicalLeader::~TechnicalLeader(){
    
}
    