#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() 
{
    vector<int> v;
    for(int i  = 0 ; i <= 10; i++)
    {   
        v.push_back(i*20);
    }

    for(int i : v)
    {
        cout<<i<<"\t";
    }
    cout<<endl;
    cout<<is_sorted(v.begin(), v.end())<<endl;

    v.insert(v.begin()+2,11);
    v.insert(v.begin()+5,3);
    v.insert(v.begin()+7,6);

    for(int i : v)
    {
        cout<<i<<"\t";
    }

    cout<<endl;
    cout<<is_sorted(v.begin(), v.end())<<endl;
}