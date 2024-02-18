#include <iostream>
using namespace std;

string PowerSet(string str, int i, string curr)
{
    if(i == str.length())
    {
        cout<<curr<<endl;
        return curr;
    }

    PowerSet(str, i+1, curr + str[i]);
    PowerSet(str, i+1, curr);
}
int main()
{
    string str,curr;
    cout<<"Enter String"<<endl;
    cin>>str;
    PowerSet(str, 0,curr);
}

//Base Condition: going through whole array from 0 till length at length printing the curr string
//two branches going on one branch curr character is include and in other character is not included
// Leap of faith 