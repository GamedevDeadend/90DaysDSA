#include <iostream>
using namespace std;

/*
Examples : 

Input: x = 2, n = 3
Output: 8     

Input: x = 7, n = 2
Output: 49  



In this video, we solve the problem using, Iterative Power (Binary Exponentiation)

Some important concepts related to this approach:

Every number can be written as the sum of powers of 2
We can traverse through all the bits of a number from LSB to MSB in O(log n) time.
Time Complexity: O(log n)

Auxiliary Space: O(1)
*/

/* 1st
    b = 5;
    res = 4;
    a = 16;
    b = 2;

   2nd
    b = 2
    a = 256
    b = 1

   3rd
    b = 1
    res = 256*4 = 1024;
    a = 256*256
    b = 0
*/

int FindPower( int a, int b)
{
    int res = 1;


    while( b > 0)                           
    {
        if( b&1 == 1)
        {
            res = (res*a);
        }

        a = (a*a);
        b = (b>>1);
    }

    return res;
}

int main() 
{

   int a;          // for ex 4^5 ??
   int b;            
   cin>> a >> b;

   cout<<"Result : "<<FindPower(a,b);   // a=4, b = 5
}