#include <iostream>
using namespace std;

//No of bits requires to convert a to b;
int main() 
{
    int a = 3;
    int b = 2;
    int bitsReq = 0;

    int Mask = a^b; //Will return same bits of an b as 0 and diffrent as 1;

    while( Mask != 0)
    {
        Mask = Mask&(Mask - 1);
        bitsReq++;
    }

    cout<<bitsReq;
   
}