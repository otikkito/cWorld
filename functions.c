/*
https://www.tutorialspoint.com/cprogramming/c_functions.htm
*/

/*
A function is a group of statements that together perform a task. Every
C program has at least one function, which is main(), and all the most
trivial programs can define additional functions.

You can divide up your code into separate functions. How you divide up
your code among different functions is up to you, but logically the
division is such that each function performs a specific task.

A function declaration tells the compiler about a function's name,
return type, and parameters. A function definition provides the actual
body of the function.

The C standard library provides numerous built-in functions that your
program can call. For example, strcat() to concatenate two strings,
memcpy() to copy one memory location to another location, and many more
functions.

A function can also be referred as a method or a sub-routine or a
procedure, etc.*/

/*The general form of a function definition in C programming language
is as follows −
-----------------------------------------------------
return_type function_name( parameter list ) {
   body of the function
}
-----------------------------------------------------
A function definition in C programming consists of a function header
and a function body. Here are all the parts of a function −

    Return Type − A function may return a value. The return_type is the
data type of the value the function returns. Some functions perform the
desired operations without returning a value. In this case, the return_type is the keyword void.

    Function Name − This is the actual name of the function. The function name and the parameter list together constitute the function signature.

    Parameters − A parameter is like a placeholder. When a function is invoked, you pass a value to the parameter. This value is referred to as actual parameter or argument. The parameter list refers to the type, order, and number of the parameters of a function. Parameters are optional; that is, a function may contain no parameters.

    Function Body − The function body contains a collection of statements that define what the function does.
*/
