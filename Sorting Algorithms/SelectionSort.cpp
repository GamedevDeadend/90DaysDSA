#include<iostream>
using namespace std;

template<class t>
void MySwap(t&,t&);


template<class t>
void SelectionSort(t a[], int size)
{
    
    for(int i  = 0; i < size ; i++)
    {
        t min = a[i];

        for(int j = i+1; j<size; j++)
        {
            if(a[j] < min)
                MySwap(min,a[j]);            
        }

        if(min != a[i])
        {
            MySwap(min,a[i]);
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
   SelectionSort<int>(a,6);

   for(int i = 0; i<6;i++)
   {
        cout<<a[i]<<"-)";
   }

}