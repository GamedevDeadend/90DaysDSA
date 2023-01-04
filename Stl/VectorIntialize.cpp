#include <iostream>
#include <vector>
using namespace std;
int main() 
{
   int a[] = {0,2,3,4,5,6};
   vector<int> v(a,a+6);

   for (int i : v)
   {
        cout<<i<<"->";
   }

   for(auto i = v.rbegin() ; i<v.rend(); i++)
   {
        cout<<*i<<endl;
   }

   vector<int> :: iterator i;

   for(i = v.begin() ; i!=v.end(); i++)
   {
    cout<<*i<<"\t";
   }





//    for (auto i = v.begin(); i <= v.rend(); i++)
//    {

//    }
// }
}