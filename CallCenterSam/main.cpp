/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 9, 2018, 10:57 PM
 */

#include <cstdlib>
#include "CallCenter.h"
#include "Employee.h"
#include "Fresher.h"
#include "TechnicalLeader.h"
#include "ProductManager.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    CallCenter* samCenter = new CallCenter();

    Fresher* samhi = new Fresher("samhi");
    Fresher* samhi2 = new Fresher("samhi2");
    Fresher* samhi3 = new Fresher("samhi3");

    TechnicalLeader* nemka = TechnicalLeader::getInstance();
    ProductManager* nemke = ProductManager::getInstance();
    
    nemka->setName("Nemkaaa");
    nemke->setName("Nemkeewrwrrw");
    samhi->setFree(false);
    samhi2->setFree(false);
    samhi3->setFree(false);

    nemka->setFree(true);

    samCenter->addEmployee(samhi);
    samCenter->addEmployee(samhi2);
    samCenter->addEmployee(samhi3);

    samCenter->setTL(nemka);
    samCenter->setPM(nemke);

    Employee* cevabci = samCenter->getCallHandler();
    
    std::cout << cevabci->getID() << std::endl;


    return 0;
}

