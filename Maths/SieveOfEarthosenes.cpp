#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void PrintSieve( int n )
{

    //Array of boolean to accomodate prime status of every no. 1 to n;
    bool sieve[n+1];

    //To set value of  all elements of array
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = true;

//1st loop to check for every no. till n
// 2nd loop to mark every multiple of i as not prime
    for(int i=2; i<=n; i++)
    {
        for( int j = 2*i; j<=n; j+=i)
        {
            sieve[j] = false;
        }
    }

// loop to print left out prime numbers
    for(int i = 0; i<=n; i++)
    {
        if(sieve[i])
        {
            cout<<i<<"\t";
        }
    }
}

int main() 
{
    // Input value of no. for which prime factor are to be found
   int a = 0;
   cin>>a;

   PrintSieve(a);
}