#include <iostream>
using namespace std;

//We are looping to root n because pair will repeat for exanple : 10 = (2,5) then (5,2) will also exists
void PrintDivisor(int n)
{
    int i = 1;
    for( i = 1; i*i<n; i++ )
    {
        if(n%i == 0 )
        {
            cout<<i<<"\t";
        }
    }

// after printing all small divisor in ( a, b ) we will print bigger divisors by n/i;
    i--;

    for (; i>=1; i--)
    {
        if( n%i == 0)
        {
            cout<<n/i<<"\t";
        }
    }
}

int main() 
{
    int a = 0;
   cout<<"Enter The Number"<<endl;
   cin>>a;
   PrintDivisor(a);

}