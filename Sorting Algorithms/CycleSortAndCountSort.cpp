#include <iostream>
using namespace std;
 
// Function sort the array using Cycle sort
void cycleSort (int arr[], int n)
{
    // count number of memory writes
    int writes = 0;
 
    // traverse array elements and put it to on
    // the right place
    for (int cycle_start=0; cycle_start<=n-2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];
 
        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start+1; i<n; i++)
            if (arr[i] < item)
                pos++;
 
        // If item is already in correct position
        if (pos == cycle_start)
            continue;
 
        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;
 
        // put the item to it\'s right position
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }
 
        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;
 
            // Find position where we put the element
            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos += 1;
 
            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;
 
            // put the item to it\'s right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
 
    // Number of memory writes or swaps
    // cout << writes << endl ;
}
 
// Driver program to test above function
int main()
{
    int arr[] = {1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cycleSort(arr,  n) ;
 
    cout << "After sort : " <<endl;
    for (int i =0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}

//Short Notes
/* Short Note for Revision:
Cycle Sort Algorithm

Concept:
Cycle Sort is an in-place sorting algorithm that minimizes the number of writes (swaps) to the array. It is best suited for situations where minimizing memory writes is important (e.g., flash memory).

Algorithm Steps:

For every cycle, determine the correct position of the element by counting the number of smaller elements on its right.
If the element is not already in the correct position:
Swap it to its correct position.
Continue rotating the rest of the cycle to place remaining elements in their correct positions.
Skip duplicates during the rotation.
Time Complexity:

Best, Average, and Worst Case: 
𝑂
(
𝑛
2
)
O(n 
2
 ), as it involves nested loops.
Efficient in terms of memory writes, minimizing them to 
𝑂
(
𝑛
)
O(n).
Space Complexity: 
𝑂
(
1
)
O(1) (in-place sorting).

Key Points:

It works efficiently on distinct elements.
Avoids unnecessary writes for duplicate elements.
Not stable (does not maintain the relative order of duplicates). */