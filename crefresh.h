/****************************************************************
*FILE NAME: crefresh.h
*
*
*
*PURPOSE: 
* 
*
*FILE REFERENCES:
*
*NAME		I/O		Description
*----           ---             -----------
*
*EXTERNAL VARIABLE:
*SOURCE: <         >
*
*NAME	  TYPE    	I/O		Description
*----     ----          ---             -----------
*
*EXTERNAL REFERENCES:
*
*Name		Description
*----   	-----------
*
*ABNORMAL ERMINATION CONDITIONS, ERROR AND WARINGING MESSAGES:
*
*ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
*
*NOTES:
*
*REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
*
*DEVELOPMENT HISTORY:
*
*Date		Author		Change ID	Release		Description of Change
*----   	------  	---------   -------     ---------------------
*
*ALGORITHM (PDL)
*/
/*
*Here is the header for the c refresher. I need to find documentation on what
*the header file is used for.
*Some of the stuff that I think goes in a header: Data types that will be used 
*in the implementation,
*/

struct datastruct{

	int age;
	char name[50];
	char c;
};

/*Test that that two struct datastruct have the same name*/
int myfunction(struct datastruct a, struct datastruct b);
int simpleFunction(struct datastruct *a, struct datastruct *b);

