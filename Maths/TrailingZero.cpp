#include <iostream>
using namespace std;

// here for example 5!
// 5! = 5*4*3...1;
// but if 27! = 0*1*2*3*4*5....*25
// so in this case 5 in 27! != 27!/5
// because 25 have two fives in it that's why here 5s  = n/5 + n/25;
// so generalization 5s in 27! = sum of n/i where i = 5 to n and increment by multiple of 5

// More Explanation
//https://www.youtube.com/watch?v=69jsFIMINpI&list=PLUcsbZa0qzu3yNzzAxgvSgRobdUUJvz7p&index=5

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