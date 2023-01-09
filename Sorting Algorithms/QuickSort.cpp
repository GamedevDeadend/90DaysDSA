#include<iostream>
using namespace std;

int a[] ={4,6,2,5,7,9,1,3}; 

void MySwap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partioning(int l, int h)
{
    int pivot = a[l];
    int i  = l;
    int j = h;

    while( i < j)
    {
        while(a[i] <= pivot)
            i++;
        while(a[j]>pivot)
            j--;

        if(i < j)
            MySwap(a[j],a[i]);
    }

    MySwap(a[j],a[l]);

    return j;
}

void QuickSort(int l,int h)
{
    if(l<h)
    {
        int pivot = partioning(l,h);
        QuickSort(l,pivot - 1);
        QuickSort(pivot + 1, h);
    }
}

int main()
{
    for(int i  = 0; i<8; i++)
    {
        cout<<a[i]<<"->";
    }
    cout<<endl;

   QuickSort(0,7);

    for(int i  = 0; i<8; i++)
    {
        cout<<a[i]<<"->";
    }
    cout<<endl;
}