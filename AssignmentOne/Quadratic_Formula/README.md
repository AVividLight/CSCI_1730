Complete as of 2/3/2019
===

Recall that a quadratic equation is one of the form  , where the coefficients  a, b, and c are real numbers and  . The solutions to a quadratic equation can found using the quadratic formula:
 

Write a program that will prompt for and read the values of the coefficients a, b, and c, and then calculate and display the solutions of the quadratic equation having those coefficients.

Program requirements: 
a)	Use floating point variables to hold the values of a, b, and c.
b)	Your program should generate an error message and force reentry if the user enters a value of zero for a.
c)	Your program should work whether the quadratic equation has two real number roots, one real number root, or two complex number roots.
d)	The function sqrt should be used to calculate the needed square root. To find the square root of a variable x, include this code: sqrt(x) Note: To use this function, you need to add #include <cmath> after the other include statement at the beginning of your code. To find the square root of a variable x, include this code: sqrt(x)

Here are examples of a user’s interaction with the program:
<pre>
Run 1:
Quadratic equation solver:
Enter a: 0
a cannot be zero - reenter
Enter a: 1
Enter b: 3
Enter c: 2
There are two real solutions: -1 and -2
Run 2:
Quadratic equation solver:
Enter a: 1
Enter b: -6
Enter c: 9
There is one real solution: 3
Run 3:
Quadratic equation solver:
Enter a: 1
Enter b: 2
Enter c: 10
There are two complex solutions: -1+3i and –1-3i
</pre>
