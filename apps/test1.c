#include <stdio.h>
#include <strings.h>
#include <ctype.h>

/*Function prototype*/
tokenizestring(char * string);


struct strings{
    char string1[50];
    float float1[50];
    float float2[50];
    int   integer;
};

int main(){

	char string[] = "JAMES          3.318  3.318      1\n";
        tokenizestring(string);
        
	return 0;
}


/*
 char string[] = "JAMES          3.318  3.318      1\n";
 */
tokenizestring(char * string){
    printf("This is the string: %s",string);
    //Break up each word and put it into a string
    int i;
    int membernum=1;
    int j;
    //temp1[WORDSIZE];
    for(i=0; i <strlen(string);i++){
        j=isblank(string[i]);  //isblank is returning the wrong return codes need to check into that
        printf("%c \n",string[i]);
        if(isblank(string[i]) != 0){
            printf("%c \n",string[i]);
        }
        if(isblank(string[i])){
            membernum++;
            
        }
        
    }
    
    
}