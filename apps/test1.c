#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>

#define WORDSIZE 50


//https://sourceware.org/bugzilla/buglist.cgi?bug_status=UNCONFIRMED&bug_status=NEW&bug_status=ASSIGNED&bug_status=SUSPENDED&bug_status=WAITING&bug_status=REOPENED&list_id=33073&product=glibc&query_format=advanced
//https://www.merriam-webster.com/dictionary/double%20entendre
//https://en.wikipedia.org/wiki/Natural_language_processing
//https://www.coursera.org/learn/natural-language-processing

/*Function prototype*/
void tokenizestring(char * string);
int isblank_k(int c);


struct strings{
    char string1[50];
    float float1;
    float float2;
    int   integer;
}string;

int main(){

	char string[] = "JAMES          3.318  3.318      1\n";
        tokenizestring(string);
        
	return 0;
}


/*
 char string[] = "JAMES          3.318  3.318      1\n";
 * man isblank
 * TODO Need to modify or create another function that can have variable word sizes
 * RETURN VALUE
       The  values returned are nonzero if the character c falls into the tested class, and
       a zero value if not.

 */
void tokenizestring(char * string){
    printf("This is the string: %s",string);
    //Break up each word and put it into a string
    int i;
    int membernum=1;
    int j;
    int count;
    char c;
    char word[WORDSIZE];
    
    memset(&word[0],0, strlen(word));
    for(i=0; i < strlen(string);i++){  //need to fix strlen it returns size_t
        if(isblank(string[i]) == 0){  
            printf("%c \n",string[i]);
            
        }
        //char string[] = "JAMES          3.318  3.318      1\n";
        if((isblank(string[i])) == 0){//if it is a character print it to the console and put it in one of the member of the structure
            switch(membernum){
                case 1:
                    word[i] = c;
                    continue;
                case 2://need to modify to read in a float
                    //string.float1[i] = c;
                    break;
                case 3: //need to modify to read in a float
                    //string.float2[i] = c;
                    break;
                case 4: //need to modify to read in a integer
                    //string.int[i] = c;
                    break;
            }
            membernum++;
            
        }
        
    }
    
    printf("word: %s \n",word);
}
/*
 blanks that are in c:
 * man ascii
 * returns The  values returned are 1 if the character c falls into the tested class, and
       a zero value if not.
 * if it is blank return 1 and if it is not blank return 0
 */
int isblank_k(int c){
    if((c == atoi(" ")) || (c == atoi("\t"))){
        return 1;
    }
    return 0;
}