Incomplete as of 2/4/2019
===
1. Write a C++ program that can be used to calculate and display the area and the perimeter of three different two-dimensional geometric shapes: a circle, a rectangle, and a triangle. 

Your program should be modular and must contain the following functions:
•	Function main will be the program driver – it will repeatedly display a menu of shapes to the user asking the user to select one and then call the appropriate functions to prompt the user for input of dimension(s), read the dimension(s), calculate the area and perimeter, and display the results. The repetition should continue until the user selects to exit the program.
•	Three overloaded getDim functions that will ask the user to enter the needed shape dimension(s) from the user and return the dimension(s) to main.
•	Three overloaded area functions that will take in the shape dimension(s) and calculate and return the shape area.
•	Three overloaded perimeter functions that will take in the shape dimension(s) and calculate and return the shape perimeter.
•	One display function that will take a shape indicator value and the shape area and perimeter values and display the labeled results.

Note: Your program should use Heron’s formula (given below) for finding the area of a triangle (the formula uses the triangle’s side lengths instead of the base and the height to find the area).

Note: Your program should also include a global named constant PI initialized to 3.141592654 that will be needed by your circle area and perimeter functions.

Area and Perimeter Formulas:
>Circle: A=pi\*r^2		P=2pi\*r		 	 	where r is the circle radius.

>Rectangle: A=l\*w		P=2l+2w 	 		 	where l and w are the rectangle length and width.

>Triangle: A=sqrt(s(s-a)(s-b)(s-c))		where s= (a+b+c)/2			P=a+b+c 	 	 
		where a, b, and c are the lengths of the sides of the triangle.

Here is the output from a sample run of the program (user input in bold):

<pre>AREA/PERIMETER CALCULATOR
Select a shape:
Circle (1)  Rectangle (2)  Triangle (3) Exit (4)
Enter selection => 1
Enter circle radius: 10
Circle area = 314.159 and perimeter = 62.8319

AREA/PERIMETER CALCULATOR
Select a shape:
Circle (1)  Rectangle (2)  Triangle (3) Exit (4)
Enter selection => 2
Enter rectangle length: 3.5
Enter rectangle width: 4.5
Rectangle area = 15.75 and perimeter = 16

AREA/PERIMETER CALCULATOR
Select a shape:
Circle (1)  Rectangle (2)  Triangle (3) Exit (4)
Enter selection => 3
Enter 1st side of triangle: 3
Enter 2nd side of triangle: 4
Enter 3rd side of triangle: 5
Triangle area = 6 and perimeter = 12

AREA/PERIMETER CALCULATOR
Select a shape:
Circle (1)  Rectangle (2)  Triangle (3) Exit (4)
Enter selection => 4
Bye...</pre>