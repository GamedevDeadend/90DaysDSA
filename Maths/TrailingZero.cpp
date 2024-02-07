#include <iostream>
using namespace std;

int TrailingZeroes(const int& n )
{
    int res = 0;
    for(int i = 5; i<=n ; i*=5)
    {
        res += n/i;
    }

    return res;
}
int main() 
{
   int n = 0;
   cout<<"Enter the no."<<endl;
   cin>>n;



}