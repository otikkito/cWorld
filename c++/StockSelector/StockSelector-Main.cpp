/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StockSelector-Main.cpp
 * Author: otikkito
 *
 * Created on July 28, 2017, 2:39 PM
 */
/*Notes
 I need to find a data feed that I can use to populate this class and an api to 
 * interface it.
 */
/*Preprocessor includes*/
#include <cstdlib>
#include <iostream>
#include <string>

/*Name space*/
using namespace std;

/*Class declaration*/
class StockSelector{
    string ticker_symbol;
    
public:
    void update_ticker_symbol(string ticker);
    void display_stock();
};

/*Class functions*/

void StockSelector::update_ticker_symbol(string ticker){
    ticker_symbol = ticker;
    
}

void StockSelector::display_stock(){
    cout << ticker_symbol << endl;
}
/*
 * 
 */
int main(int argc, char** argv) {

    StockSelector s;
    s.update_ticker_symbol("rht");
    s.display_stock();
    return 0;
}

