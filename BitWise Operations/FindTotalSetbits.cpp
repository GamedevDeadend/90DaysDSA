#include <iostream>
using namespace std;
int main() 
{
    //Find Total SetBits
    int a;
   cin>>a;

    int res = 0;
   while ( a > 0)
   {
        a = a & (a-1);
        res += 1;
   }

   cout<<"Res : "<<res;
}