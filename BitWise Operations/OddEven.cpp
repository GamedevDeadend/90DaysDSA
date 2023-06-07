#include <iostream>
using namespace std;
int main() 
{
   int a;
   cout<<"Enter the number"<<endl;
   cin>>a;

   if( (a&1) == 0 ) //XOR(Mask with 1) if result is 0 then it is even
   {
        cout<<a<<" is even"<<endl;
   }
   else
   {
        cout<<a<<" is odd"<<endl;
   }
}