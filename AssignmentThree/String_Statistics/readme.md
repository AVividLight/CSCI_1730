Complete as of 3/11/2019
===

Write a C++ program that will read in one or more lines of text and then determine the following:

- The number of uppercase letters in the text.
- The number of lowercase letters in the text.
- The number of digits in the text.
- The number of whitespace characters (i.e., blanks or newlines) in the text. 
- The number of other, non-letter, non-digit, non-whitespace characters in the text.
- After reading the text, the program should display the text followed by a display of all of the above statistics.

Suggestions and hints:

- Use a string variable to read the text into (since you do not know in advance how much text will be input). 
- The getline function can be used to read in more than one line into a string variable. To do this, specify a special terminating character as a “flag” to indicate input termination as the third parameter to getline when it is called to read.  For example,  getline(cin,text,'@');  will read text into the string variable text until a '@' character is encountered.
- You may assume that the text to be entered does not contain the '@' character.

Output from a sample run of the program (user input is one line in bold):

<pre><b>A string is a joy forever! Enter 3 or 4 words: Am I a palindrome? Hello friends# Is this a valid 
English sentence@</b>

A string is a joy forever! Enter 3 or 4 words: Am I a palindrome? Hello friends# Is this a valid 
English sentence

There were 113 total characters.
There were 7 upper case letters.
There were 78 lower case letters.
There were 2 digits.
There were 22 white space characters.
There were 4 other characters.</pre>
