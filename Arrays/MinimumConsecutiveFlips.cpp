//https://www.geeksforgeeks.org/batch/dsa-4/track/DSASP-Arrays/article/MTAwNDY%3D

#include <iostream>
using namespace std;
int main() 
{
    bool arr[] = { 0, 1, 1, 0, 0, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    for( int i = 1; i<n; i++)
    {
        if( arr[i] != arr[i-1])
        {
            if(arr[i] != arr[0])
            {
                cout<<"from "<<i;
            }
            else
            {
                cout<<" to "<<i-1<<endl;
            }
        }
    }

    if( arr[n-1] != arr[0])
    {
        cout<<" to "<<n-1<<endl;
    }
}