#include <stdio.h>
#include <float.h>

int main(){
	
	double d;
	float f;
	
	d=1.0/3.0;
	f=1.0/3.0;
	printf("%4f %12f %16f\n",d,d,d);
	printf("%4f %12f %16f\n",f,f,f);
	printf("The value for FLT_DIG is %d the value for DBL_DIG is %d\n",FLT_DIG,DBL_DIG);
}