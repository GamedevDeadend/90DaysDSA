#include<iostream>
using namespace std;

#define MAX 1000
void heapify(int a[], int n, int i)
{
    if(i<=0)
        return;
    if(a[i/2] < a[i])
        swap(a[i/2], a[i]);


    heapify(a,n,i/2);
}



void Insert(int a[], int& n, int& val)
{
    n++;
    a[n-1] = val;

    heapify(a, n, n-1);
}


void display(int a[],int n)
{
    for(int i = 0 ; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}


int main()
{
    int arr[MAX] = { 10, 5, 3, 2, 4 };
 
    int n = 5;
 
    int key = 15;
 
    display(arr, n);
    Insert(arr, n, key);
    display(arr, n);
    // Final Heap will be:
    // 15
    //    /   \
    // 5     10
    //  / \   /
    // 2   4 3
}