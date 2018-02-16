/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <map>


/*
 * Find this:
 today is friday and tomorrow saturday

 * Using these:

and, tomorrow
friday, and
tomorrow, saturday
today, is
is, friday

 */


int main21312312312311(){
    
    std::vector<std::pair<std::string, std::string>> tuples;
    
    tuples.push_back(std::make_pair("and", "tomorrow" ));
    tuples.push_back(std::make_pair("friday", "and" ));
    tuples.push_back(std::make_pair("tomorrow", "saturday" ));
    tuples.push_back(std::make_pair("today", "is" ));
    tuples.push_back(std::make_pair("is", "friday" ));
    
    // header's head will be seen only once, and also footer's foot will be seen once.
    std::map<std::string, int> maps;
    std::map<std::string, std::string> maps_str;

    for(int i = 0; i < tuples.size(); ++i){
        maps[tuples[i].first]++;
        maps_str[tuples[i].first] = tuples[i].second;
    }
    
    for(int i = 0; i < tuples.size(); ++i){
        maps.erase(tuples[i].second);
    }
    
    // i can start 
    std::string res = "";
    std::map<std::string, int>::iterator it = maps.begin();
    std::string start_ = it->first;
    res.append(start_ + " ") ;
    for(int i = 0; i < tuples.size(); ++i){
        start_ = maps_str[start_];
        res += start_ + " "; 
    }
    
    std::cout << res << std::endl;
    
    return 0;
}
