#include <iostream>
using namespace std;
int main() 
{
   //Set ith bit means setting bit at 1

    int a = 5;
    int i = 3; // pos of bit from right hand side

   //Step 1 - create a mask for bit pos
   // mask 1<<i (Left Shift 1 by i)
   // Step 2 - or operation for numb and mask created;

    a = a|(1<<i);
    cout<<"a: "<<a<<endl;
}