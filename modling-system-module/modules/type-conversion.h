/*type-conversion.h*/


/*Include*/

/*Conversion, rates, constants
ref:https://kb.iu.edu/d/ackw  // need to find a industry source .I think ISO source would suffice.
ref:https://en.wikipedia.org/wiki/Kibibyte
kilobyte kb
kibibyte kiB
*/


//TODO work on the function and variable nameing convention.
/*function prototype*/
struct binary-digit_t integer_to_binary(int);
int binary_to_integer(struct binary-digit_t);
string binary-digit_to_string(struct binary-digit_t);
