Incomplete as of 3/06/2019
===

Write a class `IntSet` for modeling sets of integers in the range 0 through 99. A set should be represented internally as an array of type `bool`: The ith array element will be `true` whenever integer `i` is in the set and will be `false` whenever integer `i` is not in the set. Include a no-argument constructor that initializes a set to the so-called “empty set,” i.e., a set whose array representation contains all false values. The class should include the following overloaded operators:

- `+` to perform the union of two set (the union of sets A and B is the set that contains all elements of set A or set B, or both).
	
- `*` to perform the intersection of two sets (the intersection of sets A and B is the set that contains all elements in both set A and set B.)
	
- `-` to form the difference of two sets (the difference of sets A and B is the set containing those elements that are in A but not in B)

- `+=` to add an integer into a set.

- `-=` to delete an integer from a set.

- `==` to determine if two sets are equal. 

- `!` to form the complement of a set (the complement of set A, denoted A-bar, is the set containing all the elements in the universal set that are not in A - the universal set for this problem is the set containing all integers between 0 and 99)

- `<=` to determine if one set is a subset of another set (set A is a subset of set B means that for any element x in A, x is also an element of set B).

- `<<` to display a set in roster notation (for example, {2, 3, 5, 9})

Requirement: The overloaded `+=` and `-=` operators should check for valid integer input (in the range 0-99), or if an add-item is already in the set, or if a delete-item is not in the set. An error message for invalid input should be generated.

Then, write a C++ program that uses the new `IntSet` class. The program should allow the user to repeatedly select from these options:

•	add numbers to a set

•	remove numbers from a set

•	form the union of two sets

•	form the intersection of two sets

•	form the difference of two sets

•	determine if two sets are equal

•	form the complement of an set

•	determine if one set is a subset of another set

•	display a set

The program should allow for up to ten sets to be created during a given program run. Use any stand-alone functions you feel necessary.

Here is output from a sample run of the program (user input in bold):

<pre>      Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
<b>1</b>
Add numbers to which sets (A, B,C, D, E, F, G, H, I, J)?   :<b>A</b>
Enter  number to add:  <b>1</b>
Add another (y or n):   <b>y</b>
      Enter number to add:   <b>3</b>
      Add another (y or n):   <b>y</b>
      Enter number to add:   <b>8</b>
      Add another (y or n):   <b>n</b>

     Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
      <b>9</b>
      Display set (A, B, C, D, E, F, G, H, I, J)?   :<b>A</b>
      {1, 3, 8}

      Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
      <b>1</b>
Add numbers to which sets (A, B,C, D, E, F, G, H, I, J)?   :<b>B</b>
Enter  number to add:  <b>2</b>
Add another (y or n):   <b>y</b>
      Enter number to add:   <b>3</b>
      Add another (y or n):   <b>y</b>
      Enter number to add:   <b>7</b>
      Add another (y or n):   <b>n</b>

     Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
      <b>2</b>
      Remove numbers from which set (A, B, C, D, E, F, G, H, I, J)?  :<b>A</b>
      Enter number to remove: <b>1</b>
      Remove another (y or n):  <b>n</b>

      Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
       <b>3</b>
       Sets union – specify sets to use:
       First set: (A, B, C, D, E, F, G, H, I, J)?   :<b>A</b>
       Second set: (A, B, C, D, E, F, G, H, I, J)?  :<b>B</b>
       Result set: (A, B, C, D, E, F, G, H, I, J)?   :<b>C</b>

       Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
<b>4</b>
Set intersection – specify sets to use:
      First set: (A, B, C, D, E, F, G, H, I, J)?   :<b>A</b>
      Second set: (A, B, C, D, E, F, G, H, I, J)?  :<b>B</b>
      Result set: (A, B, C, D, E, F, G, H, I, J)?   :<b>D</b>

      Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
       <b>5</b>
Set difference – specify sets to use:
      First set: (A, B, C, D, E, F, G, H, I, J)?   :<b>A</b>
      Second set: (A, B, C, D, E, F, G, H, I, J)?  :<b>B</b>
      Result set: (A, B, C, D, E, F, G, H, I, J)?   :<b>E</b>

      Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
      <b>6</b>
Set equality – specify sets to compare:
      First set: (A, B, C, D, E, F, G, H, I, J)?   :<b>A</b>
      Second set: (A, B, C, D, E, F, G, H, I, J)?  :<b>B</b>
      These sets are not equal

      Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
      <b>7</b>
Set complement – specify sets to use:
      Complement set: (A, B, C, D, E, F, G, H, I, J)?   :<b>A</b>
      Result set: (A, B, C, D, E, F, G, H, I, J)?  :<b>F</b>

      Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
      <b>8</b>
Subsets – specify sets to compare:
      First set: (A, B, C, D, E, F, G, H, I, J)?   :<b>A</b>
      Second set: (A, B, C, D, E, F, G, H, I, J)?  :<b>B</b>
      The first set is not a subset of the second

      Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
      <b>9</b>
      Display set (A, B, C, D, E, F, G, H, I, J)?   :<b>B</b>
      {2, 3, 7}

       Select an option:
1	- add numbers to a set
2	-  remove numbers from a set
3	- form the union of two sets
4	- form the intersection of two sets
5	- form the difference of two sets
6	- determine if two sets are equal
7	- form the complement of an set
8	- determine if one set is a subset of another set
9	- display a set
10	– Exit
<b>10</b></pre>
