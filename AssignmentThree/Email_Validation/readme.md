Incomplete as of 3/13/2019
===

Write a C++ program that repeatedly prompts for and reads an e-mail address and then determines and displays whether the address is valid or invalid. For purposes of this program, an e-mail address is valid if it satisfies these conditions:

- The address cannot contain blanks. For example, john smith@minneapolis.edu is not a valid e-mail address.
- The @ character must occur exactly once. For example, baz.cs.dpu.edu and bar@cs@dpu are not valid e-mail addresses.
- The @ character cannot be the first character of the address. For example, @cs.dpu.edu is not a valid e-mail address.
- Every occurrence of the dot character (.)must have a non-@, non-dot character on both sides. For example, bar@cs. , .ed@comcast.net, and bar@.depaul, joe..smith@bob.com are not valid e-mail addresses.

After reading an email address, the program should display it. If the address is valid, a message should be displayed stating that it is. For invalid addresses, the program should generate an error message for each of the above conditions that was violated. 
 
Suggestions and hints:

- Use string class strings in your program. 
- Write a separate bool-valued function to check each of the four invalidity checks given above. Each should receive the email address via a parameter and then return true if the email address is invalid according to the particular invalidity conditions. 
- Use a bool array of size four to store the results of calling each of these invalidity check functions.
- If you have buffering problems when repeatedly reading strings and chars, make use of the function call cin.ignore(80,’\n’) to clear the buffer at appropriate times.

Output from a sample run of the program (user input is one line in bold):

<pre>Enter the address: <b>john smith@minneapolis.edu</b>
You entered: john smith@minneapolis.edu  
Not valid – contains a blank
Enter another (y or n)? <b>y</b>
Enter the address: <b>baz.cs.dpu.edu</b>
You entered: baz.cs.dpu.edu
Not valid – not exactly one ‘@’
Enter another (y or n)? <b>y</b>
Enter the address: <b>bar@cs@dpu</b>
You entered: bar@cs@dpu
Not valid – not exactly one ‘@’
Enter another (y or n)? <b>y</b>
Enter the address: <b>@cs.dpu.edu</b>
You entered: @cs.dpu.edu
Not valid – ‘@’ is first character
Enter another (y or n)? <b>y</b>
Enter the address: <b>bar@cs.</b>
      You entered: bar@cs.
Not valid – a dot is first or last, or preceded or followed by @ or .
      Enter another (y or n)? <b>y</b>
Enter the address: <b>.ed@comcast.net</b>
You entered: .ed@comcast.net
Not valid – a dot is first or last, or preceded or followed by @ or .
Enter another (y or n)? <b>y</b>
Enter the address: <b>bar@.depaul</b>
You entered: bar@.depaul
Not valid - a dot is first or last, or preceded or followed by @ or .
Enter another (y or n)? <b>y</b>
Enter the address: <b>joe..smith@bob.com</b>
You entered: joe..smith@bob.com
Not valid - a dot is first or last, or preceded or followed by @ or .
Enter another (y or n)? <b>n</b></pre>