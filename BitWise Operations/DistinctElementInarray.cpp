//find non-repeating number in a array while other are in pair

#include <iostream>
using namespace std;
int main() 
{
   int a[] = {0,1,2,3,4,5,4,0,2,1,3}; // ever same no. xor will beacome 0;
   int res = 0;
   for( int i : a)
   {
        res = res^i;
   }

   cout<<res;
}