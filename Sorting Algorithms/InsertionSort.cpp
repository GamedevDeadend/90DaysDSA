#include<iostream>
using namespace std;

// we will take array divide it in two parts sorted and unsorted
// and then make unsorted to sorted

template<class t>
void InsertionSort(t a[], int size)
{
    for (int i = 1; i< size; i++)
    {
        t temp = a[i];
        int j = i-1;

        while( j>-1 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = temp;
    }
}

int main()
{
  int a[] = {54,8,96,35,23};

cout<<"Elements Before Sorting"<<endl;
  for (int i  = 0; i < 5;  i++)
  {
    cout<<a[i]<<"-";
  } 
  cout<<endl;

InsertionSort<int>(a,5);

cout<<"Elements After Sorting"<<endl;
  for (int i  = 0; i < 5;  i++)
  {
    cout<<a[i]<<"-";
  } 
  cout<<endl;

}