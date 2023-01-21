#include<iostream>
using namespace std;

template<class t>
void MySwap(t&,t&);


template<class t>
void BubbleSort(t a[], int size)
{
    for(int i  = 0; i < size ; i++)     //Outer loop to pick an element
    {
        for(int j = i+1; j<size; j++) //Inner loop to compare with rest of the elements
        {
            if( a[i] > a[j])
            {
                MySwap(a[i],a[j]);
            }
        }
    }
}

template<class t>
void MySwap(t& a, t& b)
{
    t temp;
    temp = a;
    a = b;
    b = temp;
}


int main()
{
   int a[6] = {1,50,6,80,9,100};
   BubbleSort<int>(a,6);

   for(int i = 0; i<6;i++)
   {
        cout<<a[i]<<"-)";
   }

}