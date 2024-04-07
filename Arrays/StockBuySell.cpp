#include <iostream>
using namespace std;

// This is simple and optimized method
int main() 
{
    // max profit : 4+5+1+2+25 = 37;
   int arr[] = {1,5,10,0,1,3,0,25}; //24 :

   int maxProfit = 0;

   for(int i = 0; i<(sizeof(arr)/sizeof(int)); i++)
   {
        if( arr[i+1] > arr[i])
        {
            maxProfit+=(arr[i+1]-arr[i]);
        }
   } 

   cout<<"Max Profit : "<<maxProfit;
}