Complete as of 2/25/2019
===

Create a class `Elevator` that will simulate the operation of an elevator. Here are the details:

- Assume that for a given elevator, it must keep track of its current floor position. 
- Assume that an elevator will initially start on the first floor. 
- An elevator should be able to service a request to move to a specified floor. In servicing a request, the elevator should display a summary of its floor movement. 
- An elevator should also be able to return its current floor position to other program modules. 

Using your Elevator class, write a C++ program that will use the Elevator class to simulate the operation of three elevators traveling between the 1st and 10th floors of a building, from the perspective of a person waiting for an elevator on the first floor. Use an array to model the three elevators. The program should repeatedly do the following tasks:

- Display the current positions of each of the three elevators.
- Ask the user to choose one of the elevators to use (i.e., like pushing the “up” button for one of the elevators – we assume here that each elevator has its own “up” button).
- If the chosen elevator is not on the first floor, the driver should give the elevator a request to come to the first floor.
- Ask the user which floor she wants (i.e., like pushing the “floor number” button inside the elevator). 
- Send the chosen elevator a request to move to the selected floor.

Here is output from a sample run of the program (user input in bold):

<pre>Elevator Status
A       B       C
1       1       1
Which elevator do you want (1=A, 2=B, 3=C, or other to exit)? <b>1</b>
Which floor do you want? <b>3</b>
Starting at floor 1
  Going up - now at floor 2
  Going up - now at floor 3
Stopping at floor 3

Elevator Status
A       B       C
3       1       1
Which elevator do you want (1=A, 2=B, 3=C, or other to exit)? <b>3</b>
Which floor do you want? <b>5</b>
Starting at floor 1
  Going up - now at floor 2
  Going up - now at floor 3
  Going up - now at floor 4
  Going up - now at floor 5
Stopping at floor 5

Elevator Status
A       B       C
3       1       5
Which elevator do you want (1=A, 2=B, 3=C, or other to exit)? <b>2</b>
Which floor do you want? <b>4</b>
Starting at floor 1
  Going up - now at floor 2
  Going up - now at floor 3
  Going up - now at floor 4
Stopping at floor 4

Elevator Status
A       B       C
3       4       5
Which elevator do you want (1=A, 2=B, 3=C, or other to exit)? <b>3</b>
Starting at floor <b>5</b>
  Going down - now at floor 4
  Going down - now at floor 3
  Going down - now at floor 2
  Going down - now at floor 1
Stopping at floor 1
Which floor do you want? <b>6</b>
Starting at floor <b>1</b>
  Going up - now at floor 2
  Going up - now at floor 3
  Going up - now at floor 4
  Going up - now at floor 5
  Going up - now at floor 6
Stopping at floor 6

Elevator Status
A       B       C
3       4       6
Which elevator do you want (1=A, 2=B, 3=C, or other to exit)? <b>9</b></pre>