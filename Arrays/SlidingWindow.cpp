//Given an array of integers of size 'n'. Our aim is to calculate the maximum sum of 'k' consecutive elements in the array.
//Sliding Window Way (can be used for XOR, product, division etc.)

#include <iostream>
using namespace std;

//Naive Method
int maxSum(int arr[], int n, int k)
{
    int curr = 0; int sum = 0;

    for(int i = 0; i < n; i++)
    {
        for( int j = i; j < (i+k); j++ )
        {
            curr += arr[j];
        }

        sum = max(curr, sum);
        curr = 0;
    }
    return sum;
}

int maxSum_eff(int arr[], int n, int k)
{
    int max_Sum = 0;
    int curr = 0;

    for(int i = 0; i < k; i++)
    {
        curr += arr[i];
    }

    int res = 0;

    for(int i = k; i < n; i++)
    {
        curr += arr[i];
        curr -= arr[i-k];

        res = max(curr,res);
    }

    return res;
}
int main() 
{
    int arr[] = {1, 8, 30, -5, 20, 7}, n = 6, k = 3;
     cout<<maxSum(arr, n, k)<<endl;
     cout<<maxSum_eff(arr, n, k);
}