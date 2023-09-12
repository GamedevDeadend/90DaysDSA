#include <bits/stdc++.h>
// #include <iostream>

//Here We are Taking Example with triplets.Find Distinct Element which is not repeating.
//Here instead of 3(Triplets) we can do it for K(K times repeating)
using namespace std;
int main() 
{
    int k  = 3; // K here represent repeatation of all elements except disitinct element
    int c[32];
    for( int i = 0; i<32; i++)
     c[i] = 0;

   int a[] = { 1,1,1,2,2,2,5};
    int b = 0;

   for(auto i : a)
   {
     int n = 31;
     while( i != 0)
     {
          if( ((i%2)^1) == 0)
          {
            // cout<<(i^1)<<endl;
               c[n]++;
          }

          i = i>>1;
          n--;
     }
   }

   for( auto i : c)
   {
    i = i%k;
    //  cout<< i;
   }

  int res = 0;
   for( int i = 31; i>=0; i--)
   {
      res += (c[i]%k)*(pow(2,31-i));
   }

   cout<<endl<<res;


}