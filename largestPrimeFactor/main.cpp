/**
* ProjectEuler Problem 3: Largest Prime Factor
*
* Find the largest prime factor of the number 600851475143.
*/

#include <iostream>
#include <cmath>


/*************************************************************************
* Function that takes in two integers, a and b, and returns their greatest
* common denominator.
*/
int gcd(long a, long b) {

	long c = a / b; // Quotient
	long r = a % b; // Remainder

	if (r != 0) { // If our remainder isn't zero

		// Recursively call gcd(b, r) until our condition is met (found gcd)
		return gcd(b, r); // Recurse
	}

	// Otherwise we return b, which should be the gcd
	return b;
}

/*****************************************************************************
* Method that computes and returns a number from a sequence generated by
* (x^2 + 1) mod n, where x is the initial value selected, and n is the number
* being factored.
*
* Normally, g(x) = (x^2 - 1) mod n, but it is more popular nowadays to use the
* function chosen.
*/
int gFunc(int x, long n) {

	// TODO: Write g(x) method

	return (((x * x) + 1) % n);
}

int rhoAlgo(long x, long y, long n) { // Should have parameters...?

	// Get our x value
	x = gFunc(x, n);

	// Get our y value
	y = gFunc(gFunc(y, n), n);

	// Find our GCD
	short f = gcd(abs(x - y), n);

	// Result storage
	short result = 0;

	if (result < f) {

		// If our result is less than our new GCD, update it
		result = f;
	}

	// Now that our result is the largest of the GCDs so far...
	// If our 
	if(f < n) {
		rhoAlgo(x, y, n);
	}

	return f;

	// TODO: Migrate the actual rho algorithm here.
}

/**********************
* Main driver function.
*/
int main() {

	// Using Pollard's rho algorithm

	long n        = 8051; // Number we would like to find the prime factors of.
	int  x        = 2           ; // Arbitrarily-chosen value, to be fixed.
	long y        = 2           ; // Arbitrarily-chosen value, variable.
	long f        = 1           ; // Storage for checking if our prime factor is 1.
	int  cycleNum = 2           ; // Initial cycle value.

	

	std::cout << "The factor is " << rhoAlgo(x, y, n) << std::endl;
	
	return EXIT_SUCCESS;
}