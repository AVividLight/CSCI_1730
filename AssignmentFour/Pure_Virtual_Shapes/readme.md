Incomplete as of 4/23/2019
===

Write a C++ program that uses virtual functions to input, calculate, and display some quantities associated with a variety of 2- and 3-dimensional objects. Design an abstract base class `Shape` from which you will derive classes `Rectangle`, `Circle`, `Triangle`, `Box`, `Can`, `Cone`, and `Ball`. The class `Shape` should contain `pure virtual functions` `Display`, `GetDimensions`, `Area`, `Perimeter`, and `Volume`. For each of the derived classes, write `member functions` `Display`, `GetDimensions`, `Area`, `Perimeter`, and `Volume` that will do the following:

- `Display` - output the type and dimensions for an object of the class.
- `GetDimensions` - get the dimensions for an object of the class.
- `Perimeter` - Calculate and display the perimeter of an object of a 2-dimensional shape class; do nothing for an object of a 3-dimensional shape class.
- `Area` - Calculate and display the area of an object of a 2-dimensional shape class; calculate and display the surface area for an object of a 3-dimensional shape class.
- `Volume` - Calculate and display the volume of an object of a 3-dimensional shape class; do nothing for an object of a 2-dimensional shape class.

Include appropriate constructors and any other member functions that you think are necessary. 

Write a program driver that will allocate an array of 20 pointers to class `Shape` and then repeatedly prompt the user, up to a maximum 20 times, to enter a shape type, dynamically allocate memory for an appropriate shape object, and then prompt for and read the appropriate dimensions for the shape. After the input of shapes is complete, the program should then loop through the pointer array contents and display the shape type, dimensions, area, perimeter and/or volume for each of the input shape objects.

Formulas for the cone calculations:

Dimensions: Height and base radius (h and r); Surface area = `pi * r^2 + pi * r * sqrt(h^2 + r^2)`; Volume = `1/3 * pi * r^2 * h`.

If you need any other formulas for the other shapes, let me know.

To see how this program will work, copy `S:\Coursework\Liu\a5-3.exe` to your own folder to run the program.



A sample run (user input is in bold):

<pre>It is time to enter your shape selection and dimensions.
Enter the number of the shape type:
   1 - Rectangle
   2 - Circle
   3 - Triangle
   4 - Box
   5 - Can
   6 - Cone
   7 - Ball
=> 
<b>1</b>
Input for Rectangle - enter length and width (separated by space): 
<b>1 3</b>

Select another shape? (y or n): 
<b>y</b>
It is time to enter your shape selection and dimensions.
Enter the number of the shape type:
   1 - Rectangle
   2 - Circle
   3 - Triangle
   4 - Box
   5 - Can
   6 - Cone
   7 - Ball
=> 
<b>4</b>
Input for Box - enter length, width, and height (separated by space): 
<b>5 2 1</b>

Select another shape? (y or n): 
<b>y</b>
It is time to enter your shape selection and dimensions.
Enter the number of the shape type:
   1 - Rectangle
   2 - Circle
   3 - Triangle
   4 - Box
   5 - Can
   6 - Cone
   7 - Ball
=> 
<b>7</b>
Input for Ball - enter radius: 
<b>3</b>

Select another shape? (y or n): 
<b>n</b>
Next, a display of your selected shapes, dimensions. and other data


Shape = Rectangle  Length = 1.0 Width = 3.0
Area = 3.0
Perimeter = 8.0


Shape = Box  Length = 5.0 Width = 2.0
 Height = 1.0
Surface area = 34.0
Volume = 10.0


Shape = Ball  Radius = 3.0
Surface area = 113.097335544
Volume = 113.097335544</pre>
