/****************************************************************
*FILE NAME: type-conversion.h
*
*
*
*PURPOSE: provide the public interface for the conversion of different types
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
*ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
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
*//*type-conversion.h*/


/*Include*/

/*Conversion, rates, constants
ref:https://kb.iu.edu/d/ackw  // need to find a industry source .I think ISO source would suffice.
ref:https://en.wikipedia.org/wiki/Kibibyte
kilobyte kb
kibibyte kiB
*/



/*function prototype*/
struct binary-digit_t integer_to_binary(int);
int binary_to_integer(struct binary-digit_t);
string binary-digit_to_string(struct binary-digit_t);
