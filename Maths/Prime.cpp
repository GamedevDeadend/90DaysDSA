#include <iostream>
using namespace std;
int main() 
{
    
   int n;
   cin>>n;

   bool res = true;

   if(n == 1)
    res = false;

//Naive(Brute force)
   /*for( int i = 2; i<n ; i++)
   {
        if(n%i == 0)
            res = false;
   }*/

// Bit better
      for( int i = 2; i<sqrt(n) ; i++)
   {
        if(n%i == 0)
            res = false;
   }

   cout<<res;

//
//for more better remove multiples of 2 and 3 while checking

/*	if(n==2 || n==3)
		return true;

	if(n%2==0 || n%3==0)
		return false;

	for(int i=5; i*i<=n; i=i+6)
	{
		if(n % i == 0 || n % (i + 2) == 0)
			return false; 
	}*/

}