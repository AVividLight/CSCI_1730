Complete as of 1/23/2019
===

Write a program that implements a four-function (+, –, *, /) calculator for fractions. The program should prompt for and read the first fraction, an arithmetic operator, and a second fraction, perform the required calculation, display the result, and then ask if the user wants to continue. The result should be displayed as a fraction - it does not need to be in reduced form. 

Program requirements: 
a)	Write a program that does not make use of any floating point data nor variables. Read the numerator and denominator of each fraction into separate integer variables (using the same technique given in the first problem). Then produce the numerator and denominator of the resulting fraction using basic fraction arithmetic. For example, a/b + c/d = (ad+bc)/bd.
b)	Make use of a switch statement to organize the calculations associated with the different arithmetic operations.
c)	Use a do loop to control the calculator repetition. 

Here is an example of a user’s interaction with the program:

<pre>Enter first fraction: 1/2
Enter operation: +
Enter second fraction: 1/3
Sum = 5/6
Continue (y or n)? y
Enter first fraction: 1/2
Enter operation: -
Enter second fraction: 1/3
Difference = 1/6
Continue (y or n)? y
Enter first fraction: 1/2
Enter operation: /
Enter second fraction: 1/3
Quotient = 3/2
Continue (y or n)? n

--------------------------------
Process exited after 56.37 seconds with return value 0
Press any key to continue . . .</pre>
