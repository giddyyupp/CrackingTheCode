/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ProductManager.h"

ProductManager* ProductManager::m_pm = 0;

ProductManager* ProductManager::getInstance(){
    
    if (m_pm == 0)
        m_pm = new ProductManager;
    
    return m_pm;
}

ProductManager::ProductManager(){
    
}