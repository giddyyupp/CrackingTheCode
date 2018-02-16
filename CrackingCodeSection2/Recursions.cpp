/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include <iostream>
#include <vector>

/*
 Recursions!!
 */

int nthFibo(int n);

void runMaze(int N);
void start(int x, int y, int N, double &path_count);

template<typename T>
std::vector<T> findSubs(std::vector<T> set);

void findAllPermutations(std::string str);
void runPermute(std::string str_orj, std::string &str_out, bool index_arr[], std::vector<std::string> &res );

void printParanthesisMain(int N);
void printParanthesis(int &openCount, int &closeCount, int N, std::string &merge);

void fillArea(int x, int y, int colorNew, int colorOld, int dim1, int dim2, int* screen);

void PlaceQueen(int row);
bool check(int row);
int columnForRow[8];

int mainrec(){
    
    /* part 8 recursion tests*/
    
//    int nn = nthFibo(8);
//    std::cout << nn << std::endl;
    
//    std::vector<int> set{1,2,3};
//    std::vector<int> res = findSubs(set);
//    for(int i = 0; i < res.size(); i++){
//        std::cout << res[i] << " ";
//    }
    
    runMaze(25);
    
//    findAllPermutations("sam");
//    printParanthesisMain(3);
    
//    PlaceQueen(7);
//    std::cout << " ";

    
    
    return 0;
}


/*
 8.1	 Write a method to generate the nth Fibonacci number.
 */
int nthFibo(int n){
    
    if (n <= 1)
        return n;
    else
        return nthFibo(n-1) + nthFibo(n-2);
}


/*
 8.2	 Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can
     only move in two directions: right and down. How many possible paths are there for
     the robot?
     FOLLOW UP
     Imagine certain squares are “off limits”, such that the robot can not step on them.
     Design an algorithm to get all possible paths for the robot.
 */
void runMaze(int N){
    
    int maze[N][N];
    double res = 0;
    
    start(0,0,N,res);
    
    std::cout << "Toplam Path Count: " << res << std::endl;
    
}

void start(int x, int y, int N, double &path_count){
    
    if (x == N-1 && y == N-1){
        path_count++;
        return;
    }
    else if(x == N-1){
        start(x, y+1, N, path_count);
    }
    else if(y == N-1){
        start(x+1, y, N, path_count);
    }
    else{
        start(x+1, y, N, path_count);
        start(x, y+1, N, path_count);
    }
    
}

/*
    8.3	 Write a method that returns all subsets of a set.
 */
template<typename T>
std::vector<T> findSubs(std::vector<T> set){
    
    std::vector<T> res;
    int max_subset = 1 << set.size(); // 2^n subset max
    
    for(int i = 0; i < max_subset ; i++){
        int k = i ;
        int index = 0;
        while(k > 0){
            if ((k & 1) > 0){
                res.push_back(set[index]);
            }
            k = k >> 1;
            index++;
        }
    }
    
    return res;
}

/* 
 8.4	 Write a method to compute all permutations of a string. 
 */

void findAllPermutations(std::string str){
    
    std::vector<std::string> res;
    std::string str_out = "";
    bool index_arr[3] = {0};
    
    runPermute(str, str_out, index_arr, res);
    
    for (int i = 0; i < res.size(); i++){
        std::cout << res[i] << std::endl;
        
    }
}


void runPermute(std::string str_orj, std::string &str_out, bool index_arr[], std::vector<std::string> &res){
    
    if (str_out.size() == str_orj.size()){
        res.push_back(str_out);
        return;
    }
    else{
        for(int i = 0; i < str_orj.size(); i++){
            if(index_arr[i] == 0){
                str_out.push_back(str_orj[i]);
                index_arr[i] = 1;
                runPermute(str_orj, str_out, index_arr, res);
            }
            else{
                continue;
            }
        }
        
    }
    
    
}


/*
 8.5	 Implement an algorithm to print all valid (e.g., properly opened and closed) combi-
     nations of n-pairs of parentheses.
     EXAMPLE:
     input: 3 (e.g., 3 pairs of parentheses)
     output: ()()(), ()(()), (())(), ((()))
 
 */
void printParanthesisMain(int N){
   
    std::vector<std::string> res;
    std::string merge = "";
    int open_cnt = 0, close_cnt = 0;
    
    printParanthesis(open_cnt, close_cnt, N, merge);

}

void printParanthesis(int &openCount, int &closeCount, int N, std::string &merge){
   
    /*book's solution is not working???*/
//    if (openCount > N || closeCount > N) return; // invalid state
//    
//    if (openCount == N && closeCount == N) {
//        std::cout << merge << std::endl; // found one, so print it
//    } 
//    else {
//        if (openCount < N) { // try a left paren, if there are some available
//            merge.append("(");
//            openCount++;
//            printParanthesis(openCount, closeCount, N, merge);
//        }
//        if (closeCount > openCount) { // try a right paren, if there’s a matching left
//            merge.append(")");
//            closeCount++;
//            printParanthesis(openCount, closeCount, N, merge);
//        }
//    }	

      
    if(openCount == N && closeCount == N){
//        res.push_back(merge);
        std::cout << merge << std::endl;
//        merge = "";
        return;
    }
    else{ 
        if(openCount < N){
            merge.append("(");
            openCount++;
            printParanthesis(openCount, closeCount, N, merge);
        }
        if(closeCount < openCount) {
            merge.append(")");
            closeCount++;
            printParanthesis(openCount, closeCount, N, merge);
        }
    }
}

/*
8.6	 Implement the “paint fill” function that one might see on many image editing pro-
     grams. That is, given a screen (represented by a 2-dimensional array of Colors), a
     point, and a new color, fill in the surrounding area until you hit a border of that color.

 */

//void fillArea(int x, int y, int colorNew, int colorOld, int dim1, int dim2, int screen[][]){
//    
//    if(x >= dim1 || y >= dim2 || x < 0 || y < 0)
//        return; // border checks
//    
//    if(screen[x][y] == colorOld){ // if this pixel has old color then update and call neighbours. 
//        screen[x][y] == colorNew;
//        fillArea(x+1, y, colorNew, colorOld, dim1, dim2); // right
//        fillArea(x-1, y, colorNew, colorOld, dim1, dim2); // left
//        fillArea(x, y+1, colorNew, colorOld, dim1, dim2); // up
//        fillArea(x, y-1, colorNew, colorOld, dim1, dim2); // down
//    }
//    
//}


bool check(int row) {
   for (int i = 0; i < row; i++) {
       int diff = std::abs(columnForRow[i] - columnForRow[row]);
       if (diff == 0 || diff == row - i) return false;
   }
   return true;
}

void PlaceQueen(int row){
    if (row == 8) {
        //print_arr(columnForRow);
        return;
    }
    for (int i = 0; i < 8; i++) {
        columnForRow[row]=i;
        if(check(row)){
            PlaceQueen(row+1);
        }
    }
}