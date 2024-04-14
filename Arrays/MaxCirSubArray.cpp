#include <iostream>
#include <bits/stdc++.h>
using namespace std;

   //naive
   //Important for every element in array as 1st element there will be n subarrays
int maxSum( int arr[], int n)
{
    int res{0};

    for(int i = 0; i < n; i++)
    {
        int currSum = arr[i];
        int currMax = arr[i];

        for (int j = 1; j<n; j++)
        {
            int index = (i+j)%n;
            currSum += arr[index];
            currMax = max(currMax, currSum);
        }

        res = max(currMax, res);
    }

    return res;
}
int main() 
{
    int a[] = {5,-2,3,4};

    cout<<"Max Sum "<<maxSum(a, 4);
}