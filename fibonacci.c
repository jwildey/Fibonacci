/**
 *  Fibonnaci Program
 *
 *  \file       fibonacci.c
 *  \brief      Fibonacci Program
 *  \author     Josh Wildey
 *
 *  Fibonnaci Program for Application Question
 */


// INCLUDES
#include <stdio.h>


/**
*  \brief Is Prime
*
*  This function checks if a number is prime or not.  If it is prime
*  then this function will return 0.  If it is not prime, this function
*  will return the first integer after the number 2 that the input is
*  divisible by.
*  
*  \param n Number to check if prime
*  \return 0 - prime, or first number that input is divisible by
*/
int isPrime(int n)
{
	int i = 0;  // counter for FOR loop
	
	// Check divisibility
	for (i = 2; i <= n/2; i++)
	{
		// If divisible by a number then it is not prime
		if (n % i == 0)
		{
			// Return the number it is divisible by
			return i;
		}
	}

	// Otherwise return 0 indicating that it is prime
	return 0;
}

/**
*  \brief Fibonnaci Function
*
*  This function will print a Fibonnaci sequence of length n, F(n), with the
*  following modifications:
*     - print "Buzz" when F(n) is divisible by 3
*     - print "Fizz" when F(n) is divisible by 5
*     - print "FizzBuzz" when F(n) is prime
*     - print value of F(n) otherwise
*
*  \param n Length of fibonnaci series
*  \return 0 - No Error
*/
int fibonnaci(int n)
{
	int first = 0;      // first number of fibonnaci series initialized to 0
	int second = 1;     // second number of fibonnaci series initialized to 1
	int next = 0;       // variable for the next (3rd) number in the series
	int cnt = 0;        // counter for FOR loop

	// Fibonnaci Series FOR LOOP
	for (cnt = 0; cnt < n; cnt++)
	{
		// First 2 terms of the fibonnaci series are 0, 1
		if (cnt <= 1)
		{
			next = cnt;
		}
		// Otherwise its the sum
		else
		{
			next = first + second;
			first = second;
			second = next;
		}

		// Switch case for isPrime results
		switch(isPrime(next))
		{
			// Print 'Buzz' when F(n) is divisible by 3 
			case 3:
				printf("%d: Buzz\n", next);
				break;
			// Print 'Fizz' when F(n) is divisible by 5
			case 5:
				printf("%d: Fizz\n", next);
				break;
			// Print 'FizzBuzz' when F(n) is prime
			case 0:
				printf("%d: FizzBuzz\n", next);
				break;
			// Print value of F(n) otherwise
			default:
				printf("%d\n", next);
				break;
		}
	} // END Fibonnaci FOR LOOP

	return 0;
}

/**
*   \brief Main function
*
*   This is the main function that calls the fibonnaci function
*   and tests its functionality.
*
*   \return 0 - No Error
*/
int main()
{
	printf("Testing Fibonnaci function with 4\n");
	fibonnaci(4);

	printf("Testing Fibonnaci function with 6\n");
	fibonnaci(6);

	printf("Testing Fibonnaci function with 47\n");
	fibonnaci(47);

	scanf("%d");

	return 0;
}