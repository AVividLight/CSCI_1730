Incomplete as of 2/8/2019
===

Write a C++ program that lets the user play the game of Rock, Paper, Scissors against the computer. The program should work as follows.

a) The program first determines the computer’s play in the game, as follows: A random number in the range of 1 through 3 is generated. If the number is 1, then the computer has chosen “rock”. If the number is 2, then the computer has chosen “paper”. If the number is 3, then the computer has chosen “scissors”. 

b) The program then prompts the user to enter her “rock”, “paper”, or “scissors” choice and then reads it, using the same number scheme as above. 

c) The program then displays both choices (in words) and the result of the play. A winner is selected according to the following game rules:

- If one player chooses rock and the other player chooses scissors, then rock wins. (The rock smashes the scissors.)
- If one player chooses scissors and the other player chooses paper, then scissors wins. (Scissors cuts paper.)
- If one player chooses paper and the other player chooses rock, then paper wins. (Paper covers rock.)
- If both players make the same choice, that play is a tie.

The program should repeatedly ask the user if she wants to play again and continues play (i.e., repeats steps 1-3, above) until she selects to end the game. After the user decides to end play, the program should display the overall results of the game – that is, how many times the user won, how many times the computer won, and how many ties there were.

Your program should be modular and must contain the following functions:

- Function `main` will be the program driver – it will repeatedly call the following functions to get the user’s play selection, randomly generate the computer’s play selection, determine the winner of a play, and tally the results. The repetition should continue until the user selects to exit the program, at which time it will call a function to display the final results.
- `getCompSelection` – this function will use the rand function to determine the computer’s play selection and return it.
- `getUserSelection` – this function will prompt for and read the user’s play selection and return it.
- `playResults` – this function will take the computer’s and user’s play selections, as well as counters for determining the total play results, and will determine the play result and display it, and will also increment the counters appropriately.
- `finalResults` – this function will take the total play results counters and generate the final display.

Extra code needed:
-
a) You need to add these to your #includes list:

	#include <cstdlib>
	#include <ctime>

b) You need to include this call to the `srand` function after your variable declarations in main in order to “seed” the rand function:

	srand(time(NULL));

Here is the output from a sample run of the program (user input in bold):

<pre>It's time to play ROCK, PAPER, SCISSORS!
What is your play?
Rock (1), Paper (2), Scissors (3): <b>1</b>
You played rock and I played scissors
You win.

Play again? (y or n): <b>y</b>
What is your play?
Rock (1), Paper (2), Scissors (3): <b>3</b>
You played scissors and I played scissors
The play was a tie.

Play again? (y or n): <b>y</b>
What is your play?
Rock (1), Paper (2), Scissors (3): <b>2</b>
You played paper and I played scissors
I win.

Play again? (y or n): <b>y</b>
What is your play?
Rock (1), Paper (2), Scissors (3): <b>2</b>
You played paper and I played rock
You win.

Play again? (y or n): <b>n</b>
Final results of our match:
You won 2 time.
I won 1 time.
There were 1 ties.
Bye, bye...</pre>
