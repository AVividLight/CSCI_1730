#include "fibonacci_sequence.h"


int Fibonacci_Number::fibonacci_number (const int input)
{
	
	int target = 0;
	int f_0 = 0;
	int f_1 = 1;
	for (int i = 0; i < input - 2; i++)
	{
		
		target = f_0 + f_1;
		f_0 = f_1;
		f_1 = target;
	}
	
	return target;
}