#include <iostream>
using namespace std;


void ReverseArr( int arr[], int start, int end)
{
    while (start < end)
    {
        arr[start] = arr[start]^arr[end];
        arr[end] = arr[start]^arr[end];
        arr[start] = arr[start]^arr[end];

        start++;
        end--;
    }
}
void LeftRotateByD_Optimised(int arr[], int n, int d)
{
    d = d%n;
    ReverseArr(arr,0,d-1);
    ReverseArr(arr,d,n-1);
    ReverseArr(arr,0,n-1);
}

void LeftRotateByD_Brute(int arr[], int n, int d)
{
    // if d > n then rotation after n times will repeat themselves
    d = d%n;

    int temp[d];

    for(int i = 0; i<d; i++)
    {
        temp[i] = arr[i];
    }

    for(int i = d; i < n; i++)
    {
        arr[i-d] = arr[i];
    }

    for(int i = 0; i < d; i++)
    {
        arr[n-d + i] = temp[i];
    }
}

int main() 
{
   int arr [] = {0,1,2,3,4,5};
   int n = sizeof(arr)/sizeof(int);

   cout<<"number of elements "<<n<<endl;

   //LeftRotateByD_Brute(arr, n, 3);
   LeftRotateByD_Optimised(arr,n,3);

   for(auto a : arr)
   {
        cout<<a<<" "<<endl;
   }

}