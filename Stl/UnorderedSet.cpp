#include <iostream>
#include <unordered_set>
using namespace std;

//Unordered Set are based on hashing while set are based on binary search tree


int main()
{
   unordered_set<int> s;
   s.insert(5);
   s.insert(10);
   s.insert(12);
   s.insert(11);
   if(s.find(5) == s.end())
        cout<<"Not found"<<endl;

    else
    {
        cout<<"Found"<<endl;
    }

    for(auto itr = s.begin(); itr != s.end(); itr++)
    {
        cout<<*itr<<"   ";
    }

    s.erase(10);

    cout<<"no. of 10 in set: "<<s.count(10)<<endl;
     
    for(auto itr = s.begin(); itr != s.end(); itr++)
    {
        cout<<*itr<<"   ";
    }
   
   s.clear();

   cout<<"\nSize: "<<s.size()<<endl;

}