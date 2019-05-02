Incomplete as of 5/02/2019
===

Write a class `LinkList`, which implements a sorted linked list of `floats`. The class should have member functions that handle the following tasks:

- Initialize a new linked list to being empty.
- Add a float value to the list – this function should add the value to the list so that the list is always in sorted order from smallest to largest value.
- Display the list.
- Find a float value in the list and return the position number of the value in the list (assume position number counting starts with one). If the value is not found, this function should return zero.
- Find the nth link in the list and return the address of the link. If the list does not have an nth  link, or if the list is empty, this function should return NULL.
- Delete the nth link in the list. If n is more than the number of links in the list, delete nothing, and give the user an error message.
- Show these list statistics:
	- the total number of values in the list
	- the mean value
	- the median value. Note: If there are an odd number of values in the list, the median is the middle value; otherwise, it is the average of the two middle values.

Note: The structure you create to represent the nodes of your linked list should contain only two member variables: a variable to store a floating-point number and a pointer to the structure.

Note: The LinkList class you create should contain only one member variable: one pointer to the structure for holding the address of the first item in the linked list.

Using your LinkList class, write a C++ program that creates one LinkList object and then repeatedly offers the user these options for working on this linked list:

- Add a value to the list – the value is added so that the list is sorted from smallest to largest.
- Search for a value in the list – if found, displays the position number of the value in the list; if not found, displays a message indicating this.
- Display the nth value in the list – if there is no nth value, display a message indicating this.
- Delete the nth value in the list – if there is no nth value, display a message indicating this.
- Display list statistics (count, mean, median).
- Display the entire list.
- Exit the program.

Note: To see how this program works, copy S:\Coursework\Liu\a6-2.exe to your own folder to run the program.

Here is a sample run of the program (user input is in bold):
<pre>LINKED LIST MANAGER

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>1</b>

Enter data value to add: <b>3.14159</b>

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>6</b>
3.14159

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>1</b>

Enter data value to add: <b>-3.14159</b>

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>1</b>

Enter data value to add: <b>7.128</b>

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>1</b>

Enter data value to add: <b>-7.128</b>

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>1</b>

Enter data value to add: <b>1.14159</b>

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>1</b>

Enter data value to add: <b>1.73</b>

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>1</b>

Enter data value to add: </b>-1.73</b>

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>6</b>
-7.128
-3.14159
-1.73
1.14159
1.73
3.14159
7.128


Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>2</b>

Enter data value to search for: <b>5</b>
5 is not in the list

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>2</b>

Enter data value to search for: <b>1.73</b>
1.73 is in position 5

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>3</b>

Enter position number to find: <b>6</b>
Value of position 6 is 3.14159

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>4</b>

Enter item position number to delete: <b>5</b>

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>6</b>
-7.128
-3.14159
-1.73
1.14159
3.14159
7.128


Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>5</b>
LIST STATISTICS
Number of items in list = 6
Average = -0.0980683
Median = -0.294205

Make a selection:
1 - Add a value (a decimal number)
2 - Search for a value
3 - Find the nth value
4 - Delete the nth value
5 - Display list statistics (count, mean, median)
6 - Display the list
7 - Exit the program
=> <b>7</b></pre>
