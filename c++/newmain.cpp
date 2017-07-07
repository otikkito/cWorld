/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: otikkito
 *
 * Created on June 27, 2017, 2:05 PM
 */

#include <cstdlib>
#include <iostream> //Allows for standard input and output
#include <string>

using namespace std;

/*Function prototype*/

int add(int a, int b);

/*
 * 
 */
int main(int argc, char** argv) {
    
    int a,b,c;
    
    string mystring = "This is a string\n";
    cout << "Hello, World!\n" ;
    cout  << mystring << endl;
    cout << mystring.size() << "\n";
    a=3;
    b=5;
    
    c= add(3,5);
    cout << "The value of c is : "  << c << endl;
    
    
    return EXIT_SUCCESS;
}

int add(int a, int b){
    return a+b;
}