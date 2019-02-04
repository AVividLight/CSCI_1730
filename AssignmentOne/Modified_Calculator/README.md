Complete as of 2/3/2019
===
NOTE: Contains modified calculator with GCD function. See Euclids\_GCD\_Method for function in isolation.
---

6. Euclid’s method for finding the greatest common divisor (GCD) of two positive integers is given by the following algorithm:
Divide the larger number by the smaller and retain the remainder.
Divide the smaller number by the remainder, again retaining the remainder.
Continue dividing the prior remainder by the current remainder until the remainder is zero, at which point the last nonzero remainder is the greatest common divisor.

For example, find the GCD of 72 and 114:
114/72 = 1 with remainder 42
72/42 = 1 with remainder 30
42/30 = 1 with remainder 12
30/12 = 2 with remainder 6
12/6 = 2 with remainder 0
So, the GCD of 72 and 114 is 6, the last nonzero remainder.

Using Euclid’s method, write a C++ function, gcd, that will take in two positive integers, determine the GCD of the integers, and return the result.

Then, modify the fraction calculator problem from problem 3 to include your gcd function and use it to produce reduced fraction results. That is, after you calculate the numerator and denominator of a fraction arithmetic operation, find their GCD and then divide each by the GCD to obtain the reduced fraction numerator and denominator.


A sample run:

<pre>Enter first fraction: 2/4
Enter operation: -
Enter second fraction: 5/6
Difference = 1/-3
Continue (y or n)? y
Enter first fraction: 2/4
Enter operation: +
Enter second fraction: 5/6
Sum = 4/3
Continue (y or n)? n

--------------------------------
Process exited after 105.3 seconds with return value 0
Press any key to continue . . .</pre>
