#include <iostream>
using namespace std;

long long calculatePow(long long a, long long b)
{
    if( b == 0) return 1;
    
    long long temp  = calculatePow(a, b/2);
    return b&1 == 1? a*temp*temp : temp*temp;
}
int main() 
{
   long long a,b;

   cin>>a>>b;

   cout<<"Power : "<< calculatePow(a,b);

   //In this problem we need a^b;
   // a*4 = a*4/2 * a*4/2
   // a*5 = a*a^4/2*a*4/2
   // if b is even a^b = a^b/2 * a^b/2
   // if b is odd  a^b odd = a^b/2 *a^b/2 *a
}