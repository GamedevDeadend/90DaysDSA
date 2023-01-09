#include<iostream>
using namespace std;

int* Merge(int a[],int l, int h)
{
    int b[20];
    int i = l;
    int k = 0;
    int mid = (l+h)/2;
    int j = mid+1;
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        {
            b[k] = a[i]; i++;
        }
        else
        {
            b[k] = a[j]; j++;
        }
        k++;
    }

    if( i > mid )
    {
        while(j <= h)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }

    else
    {
        while(i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }

    return b;
}




int main()
{
   
}