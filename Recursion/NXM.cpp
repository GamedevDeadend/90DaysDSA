#include <iostream>
using namespace std;

int nxm(int m, int n);
int main() 
{
   int m,n;
   cout<<"Enter m and n dimensions of matrice"<<endl;
   cin>>m>>n;
   cout<<"No. Of Ways "<<nxm(m,n)<<endl;
}

nxm(int m, int n)
{
   if(m ==1 || n==1 )
   {
      return 1;
   }  
   else
   {
      return nxm(m-1,n) + nxm(m,n-1);
   }
}

// Base Condition  one dimension should be one
// (m,n-1) + (m-1,n) sub problem
// General relation m,n = (m,n-1) + (m-1,n)