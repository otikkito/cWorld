#include <stdio.h>
#include <stdlib.h> //atoi
#include <strings.h>


int main(){
	
	printf("Welecome to the atoi example.\n");
	printf("Ex.1 : %d\n",atoi("5555"));
	printf("Ex.2 : %d\n",atoi("5555aq"));
	printf("Ex.3 : %d\n",atoi("55gth55"));
	printf("Ex.4 : %d\n",atoi("rgf555fgf"));
	
	return 0;
	
}

/*
[root@kitosrhellaptop-server Strings]# ./a.out 
Welecome to the atoi example.
Ex.1 : 5555
Ex.2 : 5555
Ex.3 : 55
Ex.4 : 0
*/
