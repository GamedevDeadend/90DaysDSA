#include <iostream>
#include<cmath>
using namespace std;
int main() 
{
   double a;
   cin>>a;

   double r = sqrt(2*M_PI*a)*pow((a/M_E), a);
   ///Log 10 to calculate digits in factorial
   cout<< floor(log10(r)) + 1;
}