/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on February 26, 2018, 10:51 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Accumul
{
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &s){

      char ch;
      std::string res;
      
      for(int i = 0; i < s.size(); ++i){
         ch = s[i];
         res += std::toupper(ch);
         for(int j = 0; j < i; ++j){
            res += ch;         
         }
         res += '-';
      }
      
      return res;
}


class DivSeven
{
public:
    static std::pair <long long, long long> seven(long long m);
};

std::pair <long long, long long> DivSeven::seven(long long m){

  std::pair <long long, long long> res;
  int step_num = 0;
  
  std::string number_m = std::to_string(m);
  int num_len = number_m.size();
  int last_number = 0;
  long long upper_part = 0;
  
  
  while(number_m.size() > 2){
  
      last_number = std::stoi(&number_m[num_len-1]); // get last number
      number_m.pop_back(); // remove last number
      
      // calculate 
      upper_part = stoll(number_m);
      upper_part -= 2*last_number;
      number_m = std::to_string(upper_part);
  
      step_num++;
      num_len--;
  }
  
  
  res.first = stoll(number_m);
  res.second = step_num;
  return res;

}


int mod256WithoutMod(int number)
{
//  if (number < 256 && number > -256)
//    return number;
    
  if (number < 0)
    while (number <= -256)
        number += 256;
  else
    while (number - 256 >= 0)
        number -= 256;
  
  
  return number;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
//    cout << Accumul::accum("abcd") <<endl;
//    cout << DivSeven::seven(1603).first <<endl;
    
    cout << mod256WithoutMod(258) << endl;

    return 0;
}

