#include<iostream>
using namespace std;

// TO CONVERT RANDOM ARRAY INTO MAX HEAP BUT TIME COMPLEXITY WILL BE O(N)

//To Convert ith node tree to valid max heap 
void Heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;
    if(l<=n && a[l] > a[largest])
        largest = l;
    if(r<=n && a[r] > a[largest])
        largest = r;

    if(largest != i)
    {
        swap(a[i],a[largest]);
        Heapify(a,n,largest);
    }
}


// To convert tree at each node to valid max heap.Instead of n we are going with n/2 as leaf nodes will always have valid max heap.
void BuildHeap(int a[], int n)
{
    for(int i = n/2; i>=0; i--)
    {
        Heapify(a,n,i);
    }
}

void display(int a[],int n)
{
    for(int i = 0 ; i<n; i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

// To convert max heap into sorted array
void HeapSort(int a[], int n)
{
    for(int i = n; i>=0 ; i--)
    {
        swap(a[0],a[i]);
        Heapify(a,i-1,0);
    }
}

int main()
{
   int a[] = {20,10,30,5,50,40};
   int n = 6;
   display(a,n);
   BuildHeap(a,n);
   display(a,6);
   HeapSort(a,6);
   display(a,6);
   
}