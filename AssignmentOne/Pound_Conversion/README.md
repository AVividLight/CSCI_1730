Complete as of 1/16/2019
===

Note: Rebuilt to specifications: _Do not use structs or functions, std::string, etc_
-

Before the 1950’s, Great Britain used a monetary system based on pounds, shillings, and pence. There were 20 shillings to a pound, and 12 pence to a shilling. The notation for this old system used the pound sign, £, and two decimal points, so that, for example, £5.2.8 meant 5 pounds, 2 shillings, and 8 pence. We'll call this system old-pounds. The new monetary system, introduced in the 1950’s, consists of only pounds and pence, with 100 pence to a pound (like U.S. dollars and cents). We’ll call this system decimal-pounds. So, £5.2.8 in the old-pounds is £5.13 in decimal-pounds. 

Write a program that asks the user to enter two money amounts expressed in old-pounds and will then add the two amounts and display the answer both in old-pounds and in decimal-pounds. 

Program requirements: 
a)	Read the numbers into integer variables and then make use of the integer division and remainder (%) operators to do the needed arithmetic for both calculations of the old-pounds sum as well as the decimal-pounds equivalent.
b)	To read in the old-pound amounts, make use of the fact that the extraction operator (>>) can be chained to read in more than one quantity at once. For example:

`cin >> pound >> dot >> shill >> dot >> pence;`

will read an old-pound amount into integer variables pound, shill, and pence, and read the "dots" into the character variables dot and dot. 

Here is an example of a user’s interaction with the program (user input is bold):

><pre>Enter first old-pound amount: <b>5.10.11</b>
>Enter second old-pound amount: <b>3.19.5</b>
>Old-pound total = 9.10.4
>Decimal-pound total = 9.51</pre>
