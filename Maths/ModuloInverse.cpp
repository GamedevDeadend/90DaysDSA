#include <iostream>
using namespace std;

long long FindModuloInverse( long long a, long long m)
{
    long long temp  = -1;
        
        for(int i = 1; i<=m; i++)
        {
            if((a*i)%m == 1)
            {
               temp = i;
               return temp;
            }
        }
        
    return temp;
}

int main() 
{
   /*Modulo Inverse 'b' of 'a' exist such that
    (a*b)% m = 1. (here m is modulo num)*/

    long long a,m;
    cout<<"Enter num and modulo"<<endl;
    cin>>a>>m;

    cout<<FindModuloInverse(a,m);
}