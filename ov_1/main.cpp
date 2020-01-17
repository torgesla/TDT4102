//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
/* isFib(n):
	a, b = 0, 0
	while(b < n):
		temp = b
		b += a
		a = temp
	return b == n */
int maxOfTwo(int a, int b)
{
	if (a > b)
	{
		cout << "A is greater than B" << endl;
		return a;
	}
	else
	{
		cout << "B is greater than A" << endl;
		return b;
	}
}
int fibonacci(int n)
{
	int a = 0;
	int b = 1;
	cout << "Fibonacci number:";
	for (int x = 0; x < n + 1; x++)
	{
		cout << x << " " << b << "\n";
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----\n";
	return b;
}
int squareNumberSum(int n)
{
	int totalSum = 0;
	for (int i = 0; i < n; i++)
	{
		totalSum += pow(i, 2);
		cout << pow(i, 2) << "\n";
	}
	cout << "Total: " << totalSum << "\n";
	return totalSum;
}
void triangleNumberBelow(int n)
{
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":\n";
	while (acc < n)
	{
		cout << acc << "\n";
		acc += num;
		num++;
	}
}
bool isPrime(int n)
{
	for (int j = 2; j < n; j++)
	{
		if (n % j == 0)
		{
			return false;
		}
	}
	return true;
}
void naivePrimeNumberSearch(int n)
{
	for (int number = 2; number < n; number++)
	{
		if (isPrime(number))
		{
			cout << number << " is prime\n";
		}
	}
}
int findGreatestDivisor(int n)
{
	for (int divisor = n - 1; divisor > 0; divisor--)
	{
		if (n % divisor == 0)
		{
			return divisor;
		}
	}
}
int main()
{
	//	Oppgave a)
	/*cout << "Oppgave a)\n";
	cout << maxOfTwo(5, 6) << "\n"; */

	// Oppgave b)
	/* cout << "Oppgave b)\n";
	cout << fibonacci(3) << "\n"; */

	// Oppgave c)
	/* cout << "Oppgave c)\n";
	squareNumberSum(3); */

	// Oppgave d)
	/* triangleNumberBelow(100); */

	// Oppgave e)
	/* cout << isPrime(12) << "\n"; */

	// Oppgave f)
	/* naivePrimeNumberSearch(100); */

	// Oppgave g)
	/* cout << findGreatestDivisor(25) << "\n"; */

	keep_window_open();
}