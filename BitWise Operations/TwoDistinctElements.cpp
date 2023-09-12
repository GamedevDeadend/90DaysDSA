#include<iostream>
using namespace std;

//Two Distinct Elements in a array of paired numbers 
int main()
{
    int a[] = {1,2,3,4,3,2,1,4,5,6};
    int b = 0;  //XOR among all elements of array
    int setbit_no = 0;

   for( auto i : a)
   {
        b ^= i;
   }

   cout<<b<<endl;

   setbit_no = b&~(b-1);
   cout<<setbit_no<<endl;

//    int* c = new int[sizeof(int)];
//    int* d = new int [sizeof(int)];
   int c = 0;
   int d = 0;

   for(int j = 0; j<10; j++)
   {
     if(a[j] & setbit_no)
     {
          cout<<"sdfhksdfkjhsdf"<<endl;
          c = c^a[j]; 
     }
     else
     {
          d ^= d^a[j];
     }
   }

 cout<<endl<<"Two Distinct Elements are-"<<endl<<c<<","<<d;
}
