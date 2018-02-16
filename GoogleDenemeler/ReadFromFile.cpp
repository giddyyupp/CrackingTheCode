/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>

int sumFromFile(std::string fileName);

int mainqeqeqq(){
    
    std::string fName = "./asd.txt";
    printf("%4d\n", sumFromFile(fName));
    
    return 0;
}

int sumFromFile(std::string fileName){
    
    int sum = 0;

    try{
        std::ifstream ifs(fileName.c_str());
        std::string line;
        while(getline(ifs, line))
            sum+= atoi(line.c_str());
        
    }
    catch(std::exception const & ex){
        std::cout << ex.what() << std::endl;
    }
    
    return sum;
}


