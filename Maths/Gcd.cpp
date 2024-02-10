//GCD of two numbers doesn’t change if a smaller number is subtracted from a bigger number. 

// C++ program to find GCD of two numbers
#include <iostream>
using namespace std;
// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
	// Everything divides 0
	if (a == 0)
	return b;
	if (b == 0)
	return a;

	// base case
	if (a == b)
		return a;

	// a is greater
	if (a > b)
		return gcd(a-b, b);
	return gcd(a, b-a);
}

int gcd_sl(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);	
}

//Brute Force
int gcd_naive( int a, int b)
{
	int res = min(a,b);

	while( res != 1)
	{
		if( a%res == 0 && b%res == 0)
		{
			break;
		}

		res--;
	}

	return res;

}

// Driver program to test above function
int main()
{
	int a = 98, b = 56;
	cout<<"\nGCD of "<<a<<" and "<<b<<" is "<<gcd(a, b);
	cout<<"\nGCD of "<<a<<" and "<<b<<" is "<<gcd_naive(a,b);
	cout<<"\nGCD of "<<a<<" and "<<b<<" is "<<gcd_sl(a,b);

	return 0;
}

//Here in gcd_sl( a, b)(56,98)
// if a>b then in 1st Call  = it will become ( 98, b%a = 56);( it means it'll swap)