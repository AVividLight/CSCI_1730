Incomplete as of 3/28/2019
===

Vectors are math quantities that have both magnitude and direction. This problem involves the use of two-dimensional vectors – here are the math details:

- A two-dimensional vector is a directed line segment from the origin of the xy-plane to a point, (a,b). This vector is denoted `<a,b>`.
- Vector addition/subtraction: Two vectors can be added or subtracted resulting in a vector: 
`<a,b> + <c,d> = <a+c,b+d>`  or  `<a,b> – <c,d> = <a–c,b–d>`
- Vector dot product:  Two vectors can be multiplied resulting in a number – this operation is called the dot product of two vectors: `<a,b> * <c,d> = ac+bd`
- Vector/scalar multiplication: A vector can be multiplied by a scalar (a number) resulting in a vector; for any scalar r, `<a,b>*r = <ra, rb>`
- Equality of vectors: `<a,b> = <c,d>` means a = c and b = d.

In the last two assignments, you wrote programs that modeled complex numbers. Once again, here are the math details:

- A complex number is a number of the form `a + bi` where `a` and `b` are real numbers and `i` is the imaginary unit, `sqrt(-1)`.
- Complex number addition/subtraction: `(a+bi)+-(c+di) = (a+-c)+(b+-d)i`
- Complex number multiplication: `(a+bi)*(c+di) = (ac-bd)+(ad+bc)i`
- Complex number division: `(a+bi)/(c+di) = (ac+bd)/(c^2 + d^2) + (bc-ad)/(c^2 + d^2)i`
- Equality of complex numbers: `a+bi = c+di` means `a = c` and `b = d`.

Notice that both two-dimensional vectors and complex numbers essentially are defined by two numbers. Some of the arithmetic performed on each are the same (addition and subtraction), as is the meaning of equality; the other arithmetic operations are different.

Write a C++ program that will model both two-dimensional vectors and complex numbers using derived classes. Start with a base class, `Pairs`, which should model a pair of floating point numbers and include overloaded addition, subtraction, and is-equal-to operators in addition to appropriate constructors. Then, include two derived classes, `Complex` and `Vect`. Both classes will inherit their data from the base `Pairs` class. 

- The `Complex` class should include overloaded multiplication and division operators in addition to appropriate constructors. It should also include overloaded friend insertion and extraction operators. (Note: You can use the Complex class you wrote for the last assignment and modify it slightly for this assignment.) 
- The `Vect` class should include overloaded multiplication operators in addition to appropriate constructors. Note that it will need two overloaded multiplication operators – one to handle the dot product and a second to handle scalar multiplication. It should also include overloaded friend insertion and extraction operators.

Note: The assignment operator of your base `Pairs` class will not be inherited in your derived classes. To avoid problems that might develop because of this, either:

- include these statements within your Complex and Vect class definitions:
      using `Pairs::operator =`;
- or:  overload the assignment operator `=` in your derived classes.


To exercise your new collection of classes, use this main program:
<pre>int main()
{
   int sel;
   do {
      cout << "Select an option - (1) perform complex number actions\n";
      cout << "                   (2) perform vector actions\n";
      cout << "                   (3) exit\n";
      cin >> sel;
      if(sel == 1)
         cActions();
      else if(sel == 2)
         vActions();
      else if (sel == 3)
         cout << "Bye...\n";
      else
         cout << "Invalid input - try again\n";
   } while (sel != 3);
   char ch; cin >> ch;
   return 0;
}</pre>

You will need to write the stand-alone functions `cActions` and `vActions` – here is what each does:

- `cActions` – this function contains an array of 26 complex numbers and will repeatedly prompt the user to select one of four options:

1.	Enter a complex number
2.	Display a complex number
3.	Perform arithmetic or equality comparisons of complex numbers
4.	Exit the function


	When the user selects options 1 or 2, the function asks where the number is to be stored or read from in the array, and then completes the selected action using that array location.

	When the user selects option 3, the function will ask for the operation to be used. If the operation selected is an arithmetic operator, the function will next ask for the array locations of the numbers to be combined using the operator, as well as the array location of where the result should be stored.

	If the operation selected is the is-equal-to operator, the function will only ask for the array locations of the numbers to be compared and will display the result of the comparison.

	In all cases, the chosen operation is then performed.

- `vActions` – this function contains an array of 26 vectors and will repeatedly prompt the user to select one of four options: 


1.	Enter a vector
2.	Display a vector
3.	Display a scalar
4.	Perform arithmetic or equality comparisons of vectors
5.	Exit the function


	When the user selects options 1 or 2, the function asks where the vector is to be stored or read from in the array, and then completes the selected action using that array location. 

	When the user selects option 3, the function will display the value of a scalar variable that is used to hold the result of a dot product, or the previous value of a scalar used to perform a vector-scalar product. 

	When the user selects option 4, the function will ask for the operation to be used.

	If the operation selected is addition or subtraction, the function will next ask for the array locations of the vectors to be combined using the operator, as well as the array location of where the result should be stored.
 
	If the operation selected is dot product, the function will next ask for the array locations of the vectors to be combined using the operator, but will not ask for the result location, but will store the result in the scalar variable.

	If the operator selected is vector-scalar multiplication, the function will ask for the array location of the vector to be multiplied and the scalar value and the location of the result vector. 

	In all cases, the chosen operation is then performed.

To see how this program will work, copy `S:\Coursework\Liu\a5-2.exe` or the overloaded assignment operator version `S:\Coursework\Liu\a5-2 overload=.exe` to your own folder to run the program.


A sample run of the program:

<pre>Select an option - (1) perform complex number actions
                             (2) perform vector actions
                             (3) exit
1
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
1
Enter a complex number in a+bi or a-bi form: 1+2i
Where do you want to store this (enter A-Z): A
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
2
Which one do you want to display (enter A-Z): A
1+2i
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
1
Enter a complex number in a+bi or a-bi form: 3+4i
Where do you want to store this (enter A-Z): B
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
3
Enter an operation:   +   -   *   /   =  *
Enter first number (enter A-Z): A
Enter second number (enter A-Z): B
Enter result location (enter A-Z): C
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
2
Which one do you want to display (enter A-Z): C
-5+10i
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
3
Enter an operation:   +   -   *   /   =  /
Enter first number (enter A-Z): A
Enter second number (enter A-Z): B
Enter result location (enter A-Z): C
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
2
Which one do you want to display (enter A-Z): C
0.44+0.08i
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
3
Enter an operation:   +   -   *   /   =  =
Enter first number (enter A-Z): A
Enter second number (enter A-Z): B
1+2i does not equal 3+4i
Select an option:
    (1) Enter a complex number
    (2) Display a complex number
    (3) Perform arithmetic or equality check
    (4) Exit
4
Bye...
Select an option - (1) perform complex number actions
                   (2) perform vector actions
                   (3) exit
2
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
1
Enter vector in <a,b> form: <1,2>
Where do you want to store this (enter A-Z): A
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
2
Which one do you want to display (enter A-Z): A
<1,2>
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
1
Enter vector in <a,b> form: <3,4>
Where do you want to store this (enter A-Z): B
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
4
Enter an operation:   +   -   . (dot prod)   * (scalar prod)   =  -
Enter first vector (enter A-Z): A
Enter second vector (enter A-Z): B
Enter result location (enter A-Z): C
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
2
Which one do you want to display (enter A-Z): C
<-2,-2>
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
4
Enter an operation:   +   -   . (dot prod)   * (scalar prod)   =  .
Enter first vector (enter A-Z): A
Enter second vector (enter A-Z): B
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
3
Scalar = 11
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
4
Enter an operation:   +   -   . (dot prod)   * (scalar prod)   =  =
Enter first vector (enter A-Z): A
Enter second vector (enter A-Z): B
<1,2> does not equal <3,4>
Select an option:
    (1) Enter a vector
    (2) Display a vector
    (3) Display scalar
    (4) Perform arithmetic or equality check
    (5) Exit
5
Bye...
Select an option - (1) perform complex number actions
                             (2) perform vector actions
                             (3) exit
3
Bye...</pre>