#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Normal Method
    /*    int arr[3][2] =  {   {10,20},
                            {20,30},
                            {40,50}
                        };
                for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout<< arr[i][j] << " ";
            }

            cout<<"\n";
        }
                        */

    // Double pointer Method
    /*   int **arr;
      int m = 3, n = 2;
      arr = new int*[m];
      for(int i = 0; i < m; i++)
      {
          arr[i] = new int[n];
          arr[i][0] = 0 + i;
          arr [i][1] = 1 + i;
      }

      for(int i = 0; i < 3; i++)
      {
          for (int j = 0; j < 2; j++)
          {
              cout<< arr[i][j] << " ";
          }

          cout<<"\n";
      } */

    // Using Stack allocated array of pointers
    /*      int m = 3, n=2;
         int *arr[m];

         for(int i = 0; i < m; i++)
         {
            arr[i] = new int[n];
         }

         for (int i = 0; i < m; i++)
         {
            for(int j = 0; j < n; j++)
            {
                arr[i][j] = i+j;
            }
         }


         for (int i = 0; i < m; i++)
         {
            for(int j = 0; j < n; j++)
            {
                cout<< arr[i][j] << "\t";
            }

            cout<<endl;
         } */

   /*     Methods using Array of Vectors
    (Main Advantages individual rows are dynamic)

     int m = 3, n = 2;

    vector<int> arr[m];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i].push_back(i+j);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }

        cout<<endl;
    } */

/*        // Methods using Vector of Vectors
    //(Main Advantages individual rows are dynamic)

     int m = 3, n = 2;

    vector<vector<int>> arr;

    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(i+j);
        }

        arr.push_back(v);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << "\t";
        }

        cout<<endl;
    } */
}