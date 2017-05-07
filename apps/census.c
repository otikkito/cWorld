/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   census.c
 * Author: otikkito
 *
 * Created on May 6, 2017, 5:31 PM
 * 
 * https://docs.python.org/2/library/os.html  ->converting file to a easy format
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINESIZE 1000

/*Global variables*/


/*
 * 
 */
int main(int argc, char** argv) {

    FILE *fp;
    char line[MAXLINESIZE];
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL){
        fprintf(stdout, "Current working dir: %s\n", cwd);
    }
    else
       perror("getcwd() error");
    
    fp=fopen("../text-data-files/census-dist-male-first.txt","r");
    if (fp == NULL){
        perror("Unable to open:../text-data-files/census-dis-male-first.txt");
        exit(EXIT_FAILURE);
    }
    while(fgets(line,MAXLINESIZE,fp)){
        printf("%s",line);
    }
    fclose(fp);
    return (EXIT_SUCCESS);
}

