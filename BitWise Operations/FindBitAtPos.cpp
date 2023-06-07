#include <iostream>
using namespace std;
int main() 
{
   int a = 405;
   int i = 3; // pos of bit from right hand side

   //Step 1 - create a mask for bit pos
   // mask 1<<i (Left Shift 1 by i)
   // Step 2 - check if bit at i after mask i 0 or 1.

   if( (a&1<<i) == 0)
   {
        cout<<"Bit at ith Position is 0"<<endl;
   }
   else
   {
        cout<<"Bit at ith Position is 1"<<endl;
   }
}