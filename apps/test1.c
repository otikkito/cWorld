#include <stdio.h>
#include <strings.h>

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



tokenizestring(char * string){
    printf("This is the string: %s",string);
}