Complete as of 2/3/2019
===

5. Given a positive real number n, and an approximation for its square root, approx, a closer approximation to the actual square root, new-approx, can be obtained using the formula:

new_approx = ((n / approx) + approx) / 2


Using this information, write a program that prompts the user for a positive number and an initial approximation to the square root of the number, and then approximates the actual square root of the number accurate to 0.00001. 

Hint: Using the initial approximation as the first value of approx, repeatedly calculate a new-approx, using the above formula, until the absolute value of the difference between the new-approx and approx is less than or equal to 0.00001. If the difference is greater than 0.00001, then calculate another new-approx, using its previous value as the value of approx. 

Note: The function fabs should be used to calculate the needed absolute value. To find the absolute value of a variable x, include this code: fabs(x) Note: To use this function, you need to add #include <cmath> after the other include statement at the beginning of your code. 


A sample run:

<pre>Enter n: <b>5</b>
Enter first approximation: <b>2</b>
The square root of 5 = 2.23607</pre>
