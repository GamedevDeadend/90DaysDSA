#include<iostream>
using namespace std;

// Replace the root or element to be deleted by the last element.
// Delete the last element from the Heap.
// Since, the last element is now placed at the position of the root node. So, it may not follow the heap property. Therefore, heapify the last node placed at the position of root.

//Method to Convert to max heap
void Heapify(int a[], int i, int& n)
{
    int l = 2*i;
    int r = 2*i+1;
    if(i >n || r>n || l>n)
        return;

    int largChild = l>r ? l : r;

    if(a[largChild] > a[i])
    {
        swap(a[largChild],a[i]);
    }

    Heapify(a, largChild, n);
}

//To Delete Node
void Hdelete(int a[],  int& n)
{
    a[0] = a[n-1];
    n--;

    Heapify(a,0,n);
}

void display(int a[],int n)
{
    for(int i = 0 ; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
     // Array representation of Max-Heap
    //     10
    //    /  \
    //   5    3
    //  / \
    // 2   4

    int arr[] = { 10, 5, 3, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Hdelete(arr, n);
    display(arr, n);
}