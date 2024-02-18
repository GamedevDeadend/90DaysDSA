#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/// @brief Max no of rope cuts in a,b,c ratio
int FindMaxPossibleRopeCuts(int n, int a, int b, int c)
{
    if( n == 0) return 0;
    if( n < 0) return -1;

    int maxCuts = max( FindMaxPossibleRopeCuts( n-a, a,b,c), FindMaxPossibleRopeCuts( n-b, a,b,c));
    maxCuts = max(maxCuts,FindMaxPossibleRopeCuts( n-c,a, b,c));

    if( maxCuts < 0) return -1;



    return maxCuts + 1;
}

int main() 
{
   int n = 11, a = 2, b = 3, c = 4;

   cout<<FindMaxPossibleRopeCuts(n,a,b,c);
}