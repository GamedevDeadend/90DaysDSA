#include <iostream>
using namespace std;
int main() 
{
   int a,b;

   a = 100;
   b = 50;

   a = a^b; //XOR
   b = a^b;
   a = a^b;

   cout<<"A: "<<a<<endl;
   cout<<"B: "<<b<<endl;
}