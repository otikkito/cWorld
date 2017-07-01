/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   helloworld.c
 * Author: otikkito
 *
 * Created on July 1, 2017, 7:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/*
 * 
 */
int main(int argc, char** argv) {


    initscr(); /* Start curses mode 		  */
    printw("Hello World !!!"); /* Print Hello World		  */
    refresh(); /* Print it on to the real screen */
    getch(); /* Wait for user input */
    endwin(); /* End curses mode		  */
    
    return (EXIT_SUCCESS);
}

