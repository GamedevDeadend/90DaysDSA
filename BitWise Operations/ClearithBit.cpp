// Clear bit at ith pos( make bit 0)

#include <iostream>
using namespace std;
int main() 
{
   int a = 401;
   int i = 0;

//For this we have to create mask such that bit at i th pos i 0 and other bits are not affected
//To calculate that shift 1<<i and invert it

   a = a&(~(1<<i));
   cout<<"A: "<<a<<endl;
}