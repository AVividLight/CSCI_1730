Complete as of 3/2/2019
===
Create a class, called Complex, for modeling complex numbers, a + bi, and some complex number arithmetic/comparison operations. 

Here is what should be included within this class:

- Include a no-argument constructor (to initialize a complex number to 0+0i). 
- Include public member functions to perform these complex number tasks:
	- Addition of complex numbers
	- Subtraction of complex numbers
	- Multiplication of complex numbers
	- Division of complex numbers
	- User input of a complex number
	- Display of a complex number
	- Conversion of a real number, r, to a complex number, r + 0i
	- Check for equality of two complex numbers

Then, write a C++ program that will use the Complex class to repeatedly do one of the following tasks:

a)	Perform a complex number arithmetic operation. For this option, the program will ask the user to enter a complex number, an arithmetic operation (+,  –, *, /), and a second complex number, and will then calculate and display the result of performing the arithmetic operation on the two input complex numbers.

b)	Determine if a complex number is a solution of a quadratic equation. For this option, the program will prompt for and read in the real number coefficients, a, b, and c, of a quadratic equation, ax2+bx+c=0. Next, it will prompt for and read in a complex number, z. Then, it will determine if z is a solution of the quadratic equation. 

Note: When checking for equality of two complex numbers, do not use the “is equal to” operator on the float values - instead, determine if the absolute value of the float values are smaller than a threshold value (something small, like 0.000001).

- To extract input of a complex number a + bi from keyboard, do the following:
   double    a, b; 
   char i;
   cin >>a >> b >> i;     

Complex Number Review:

A complex number is a number of the form  a + bi  where a and b are real numbers and  i  is the imaginary unit,  `i = sqrt(-1)`.

•	Addition/Subtraction: `(a+bi)+-(c+di) = (a+-c)+(b+-d)i`
•	Multiplication: `(a+bi)*(c+di) = (ac-bd)+(ad+bc)i`
•	Division: `(a+bi)/(c+di) = (ac+bd)/(c^2+d^2)+(bc-ad)/(c^2+d^2)i`

Here is output from a sample run of the program:

<pre>Select an option - (1) perform complex number arithmetic
                   (2) check for quadratic equation solution
                   (3) exit
1
Enter a complex number a+bi: 2+3i
Enter an operation (+, -, *, /): +
Enter a complex number a+bi: 4-8i
2+3i + 4-8i = 6-5i

Select an option - (1) perform complex number arithmetic
                   (2) check for quadratic equation solution
                   (3) exit
1
Enter a complex number a+bi: 2+9i
Enter an operation (+, -, *, /): -
Enter a complex number a+bi: 4+5i
2+9i - 4+5i = -2+4i

Select an option - (1) perform complex number arithmetic
                   (2) check for quadratic equation solution
                   (3) exit
1
Enter a complex number a+bi: 4+2i
Enter an operation (+, -, *, /): *
Enter a complex number a+bi: 4-2i
4+2i * 4-2i = 20+0i

Select an option - (1) perform complex number arithmetic
                   (2) check for quadratic equation solution
                   (3) exit
1
Enter a complex number a+bi: 4+8i
Enter an operation (+, -, *, /): /
Enter a complex number a+bi: 1-1i
4+8i / 1-1i = -2+6i

Select an option - (1) perform complex number arithmetic
                   (2) check for quadratic equation solution
                   (3) exit
2
Enter the coefficients of a quadratic equation: 1 -2 5
Enter a complex number a+bi: 1+2i
The complex number: 1+2i is a solution of the quadratic equation

Select an option - (1) perform complex number arithmetic
                   (2) check for quadratic equation solution
                   (3) exit
2
Enter the coefficients of a quadratic equation: 1 -2 5
Enter a complex number a+bi: 2+3i
The complex number: 2+3i is not a solution of the quadratic equation

Select an option - (1) perform complex number arithmetic
                   (2) check for quadratic equation solution
                   (3) exit
3</pre>
