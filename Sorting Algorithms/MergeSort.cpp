#include<iostream>
using namespace std;

int* Merge(int a[],int l, int mid, int h)
{
    int b[5];
    int i = l;
    int j = mid+1;
    int k = l;
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

    for( k = l; k<=h ; k++)
    {
        a[k] = b[k];
    }

    return a;
}

void MergeSort(int a[],int l, int h)
{
    if(l<h)
    {
        int mid = ((l+h)/2);
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,h);
        Merge(a,l,mid,h);
    }
}




int main()
{
 int a[] = {25,1,85,6,7};  
 for(int i = 0; i<5;i++)
 {
    cout<<a[i]<<" ";
 }
    cout<<endl;

 MergeSort(a,0,4);

 for(int i = 0; i<5;i++)
 {
    cout<<a[i]<<" ";
 }
    cout<<endl;

}