Complete as of 2/20/2019
===

When tossing one die, results of 1 through 6 are possible results. So, when tossing a pair of dice, sums of 2 through 12 are possible results. If the dice are fair, it can be shown that the probability of tossing each of these sums is:

	2 or 12: 1/36 = 2.8%
	3 or 11: 1/18 = 5.6%
	4 or 10: 1/12 = 8.3%
	5 or 9: 1/9 = 11.1%
	6 or 8: 5/36 = 13.9%
	7: 1/6 = 16.7% 

Write a C++ program that will repeatedly simulate tossing a fair pair of dice a number of times specified by the user (any number between 1 and 100,000), and calculate and display the total number of each sum produced along with its percentage of the total tosses (the relative frequency approximation of probability). 

Your program should be modular and must contain these functions:

- `rollDie` – this function will receive an array and the number of tosses and will simulate tossing one die the specified number of times, storing the toss results in the array. 
- `findSum` – this function will receive the number of tosses, two arrays holding the toss results for two dice, and a third array, and will calculate the toss sums, storing these in the third array.
- `tossCount` – this function will receive the number of tosses, an array of toss sums, and an array of counters for the possible sums, and will examine the toss sums array and count the toss sum totals. 
- `display` – this function will receive the number of tosses and an array of counters for the possible sums, and display the total number of tosses, and the total number of each of the possible sums, along with the probability of each possible sum.


Your function main should repeatedly obtain a number of tosses from the user and then call the other functions to handle the simulations, until the user elects to exit the program.

Notes and suggestions:

- In `rollDie`, use the rand function to simulate each die toss. Remember to include an appropriate  call to srand in main.
- Functions `tossCount` and `display` both receive “an array of counters for the possible sums”. As noted above, the toss sums will be values 2 through 12. So, use an integer array of size 13, with all elements initialized to 0, for the toss sums counter array. Then, to count a sum of value k (k between 2 and 12), increment element k of the toss sums counter array.
- In `display`, the probability of a given sum is the percentage of tosses that produced that sum.
- In `display`, use the tab escape sequence `\t`  to produce evenly spaced columns of numbers.

Here is output from a sample run of the program (user input in bold):

<pre>Enter number of tosses : <b>5000</b>
Total number of tosses = 5000
        Toss    Count   Probability
        2       131     2.62
        3       270     5.4
        4       427     8.54
        5       549     10.98
        6       708     14.16
        7       826     16.52
        8       692     13.84
        9       575     11.5
        10      422     8.44
        11      264     5.28
        12      136     2.72
Do another simulation? (y or n): <b>y</b>
Enter number of tosses: <b>25000</b>
Total number of tosses = 25000
        Toss    Count   Probability
        2       707     2.828
        3       1411    5.644
        4       2041    8.164
        5       2760    11.04
        6       3497    13.988
        7       4122    16.488
        8       3545    14.18
        9       2861    11.444
        10      2025    8.1
        11      1371    5.484
        12      660     2.64
Do another simulation? (y or n): <b>n</b></pre>