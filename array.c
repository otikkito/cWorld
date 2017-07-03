#include <stdio.h>
#include <stdlib.h>

/*Reference:
 https://www.tutorialspoint.com/cprogramming/c_arrays.htm
 * type arrayName [ arraySize ];
 * type name[size1][size2]  Row column
 */
int main(){
    
    int i;
    int intarray[50];
    
    for(i = 0; i < 50; i++){
        intarray[i] = rand();
    }
    printf("intarray: %d\n", intarray[10]);
    
    return EXIT_SUCCESS;
}