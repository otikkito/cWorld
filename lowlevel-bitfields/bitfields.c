/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bitfields.c
 * Author: otikkito
 *
 * Created on July 1, 2017, 4:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Function prototype*/
void Ex_12507(unsigned char a);

/*Referance:
 https://users.cs.cf.ac.uk/Dave.Marshall/C/node13.html
 */
/*
 * 
 */


struct packed_struct {
		 unsigned int f1:1;
		 unsigned int f2:1;
		 unsigned int f3:1;
		 unsigned int f4:1;
		 unsigned int type:4;
		 unsigned int funny_int:9;
} pack;
/*"Here the packed_struct contains 6 members: Four 1 bit flags f1..f3, a 4 bit 
 * type and a 9 bit funny_int. "*/

struct DISK_REGISTER  {
     unsigned ready:1;
     unsigned error_occured:1;
     unsigned disk_spinning:1;
     unsigned write_protect:1;
     unsigned head_loaded:1;
     unsigned error_code:8;
     unsigned track:9;
     unsigned sector:5;
     unsigned command:5;
};


int main(int argc, char** argv) {

    system("cat /etc/redhat-release");
    pack.f1 = true;
    unsigned char a;
    a = 3;
    printf("The size of unsigned char is: %d \n",sizeof(a));
    Ex_12507(a);
    return (EXIT_SUCCESS);
}

void Ex_12507(unsigned char a){
    /*Convert integer to binary*/
   
}