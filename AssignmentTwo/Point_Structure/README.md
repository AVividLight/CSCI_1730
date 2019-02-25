Incomplete as of 2/24/2019
===


Create a Point structure for modeling points in the xy-plane. Then, write a menu-driven C++ program that uses variables of type  Point to perform a variety of tasks involving points in the xy plane. 

Your program should be modular and must contain these functions:

- `dist` this function will receive two Points and calculate and return the distance between the Points.
- `slope` this function will receive two Points and calculate and return the slope of the line connecting two Points, if it exists. This function should have a bool reference parameter that will return a value to the user indicating whether the slope is defined or not.
- `midPoint` this function will receive two Points and calculate and return the midpoint of the line segment between two Points.
- `equation` this function will receive two Points and display the equation of the line passing through two Points.
- `collinear` this function will receive three Points and determine if three Points are collinear. If the Points are collinear, this function should return true; otherwise, it should return false. 
- `readPt` this function will read a single point entered by the user in standard point “format” (for example “(4,3)”) into a Point variable and then return the Point.
- `showPt` this function will receive a Point and then display the Point in standard point “format” (for example “(4,3)”).


Your function main should repeatedly display a menu of the above point manipulation tasks, read the user’s task selection, and then call the appropriate function(s) from above to perform the selected task and display the result, until the user selects to exit the program.

Notes and suggestions:

- When the slope is not defined, function slope can return any value for the slope – the bool parameter will be set appropriately so that the calling function will know not to use the returned value.
- In function collinear, use function slope to determine its result. When checking for equality of two slopes, do not use the “==” operator on the float values - instead, determine if the absolute value of the float values are smaller than a threshold value (something small, like 0.000001).


Algebra Topics Review:

- Slope of the line between `(a, b)` and `(c, d)`, `m = (d-b)/(c-a)` provided `a != c`; slope undefined for vertical lines.
- Distance between `(a, b)` and `(c, d)`: `D = sqrt ((c-a)^2) + (d-b)^2)`
- Midpoint between `(a, b)` and `(c, d)`: `M = [((a+c)/2), ((b+d)/2)]`
- The equation of a non-vertical line passing through `(a, b)` and `(c, d)` is given by `y = mx+(b-ma)` where `m` is the slope of the line.
- The equation of a vertical line passing through `(a, b)` and `(c, d)` is given by `x = a` where the slope of the line is undefined.

Here is output from a sample run of the program (user input in bold):

<pre>POINTLAND
What do you want to do?
1 - Find distance between two points
2 - Find slope
3 - Find a midpoint
4 - Find an equation of a line
5 - Determine if three points are collinear
6 - Exit
Selection => 1
Enter point 1: (1,1)
Enter point 2: (4,5)
Distance = 5

POINTLAND
What do you want to do?
1 - Find distance between two points
2 - Find slope
3 - Find a midpoint
4 - Find an equation of a line
5 - Determine if three points are collinear
6 - Exit
Selection => 2
Enter point 1: (2,3)
Enter point 2: (3,5)
Slope = 2

POINTLAND
What do you want to do?
1 - Find distance between two points
2 - Find slope
3 - Find a midpoint
4 - Find an equation of a line
5 - Determine if three points are collinear
6 - Exit
Selection => 3
Enter point 1: (1,2)
Enter point 2: (3,4)
MidPoint = (2,3)

POINTLAND
What do you want to do?
1 - Find distance between two points
2 - Find slope
3 - Find a midpoint
4 - Find an equation of a line
5 - Determine if three points are collinear
6 - Exit
Selection => 4
Enter point 1: (0,2)
Enter point 2: (1,5)
Equation: y = 3x+2

POINTLAND
What do you want to do?
1 - Find distance between two points
2 - Find slope
3 - Find a midpoint
4 - Find an equation of a line
5 - Determine if three points are collinear
6 - Exit
Selection => 5
Enter point 1: (0,0)
Enter point 2: (1,1)
Enter point 3: (2,3)
Points are not collinear

POINTLAND
What do you want to do?
1 - Find distance between two points
2 - Find slope
3 - Find a midpoint
4 - Find an equation of a line
5 - Determine if three points are collinear
6 - Exit
Selection => 5
Enter point 1: (0,2)
Enter point 2: (3,4)
Enter point 3: (6,6)
Points are collinear


POINTLAND
What do you want to do?
1 - Find distance between two points
2 - Find slope
3 - Find a midpoint
4 - Find an equation of a line
5 - Determine if three points are collinear
6 - Exit
Selection => 6</pre>
