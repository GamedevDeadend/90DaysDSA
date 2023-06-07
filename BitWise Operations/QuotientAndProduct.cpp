// Division and Multiplication by 2
#include <iostream>
using namespace std;
int main() 
{
   int a;
   cout<<"Enter Number"<<endl;
   cin>>a;

   cout<<"Product : "<< (a<<1) <<endl; // Left shift by one means multiplication by 2
   cout<<"Quotient : "<< (a>>1) <<endl;// Right shift by one means division by 2
}