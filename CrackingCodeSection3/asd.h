/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   asd.h
 * Author: sam
 *
 * Created on February 11, 2018, 7:09 PM
 */

#ifndef ASD_H
#define ASD_H

#include <iostream>

using namespace std;

class Shape {
  public:
        int edge_length;
        virtual int circumference () {
                std::cout << "Circumference of Base Class\n";
                return 0;
        }
};

class Triangle: public Shape {
  public:
	   int circumference () {
		      cout<< "Circumference of Triangle Class\n";
		      return 3 * edge_length;
	   }
};

#endif /* ASD_H */

