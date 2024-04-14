//Majority Element Using Moore’s Voting Algorithm:

#include <iostream>
using namespace std;
int main() 
{
   int a[] = {0,0,0,2,2,1,7,56,1,1,1,1,1,1,1};
   int n = sizeof(a)/sizeof(int);

    int majEle = a[0];
    int count = 1;

   for(int i = 1; i<n; i++)
   {
        if( a[i] == majEle)
        {count++;}
        else
        {count--;}

        if(count == 0)
        {
			majEle = a[i];
			count = 1;
        }
   }

count  = 0;

for( int i  = 0; i<n; i++)   
{
    if(a[i] == majEle)
    {
        count ++;
    }
}

if(count > n/2)
{
    cout<<"Element : "<<majEle;
}
}