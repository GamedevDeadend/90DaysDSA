#include <iostream>
#include <string>
using namespace std;


int count  = 0;
bool IsPalindrome(string &CString, int i, int j)
{
    if(i>=j)
    {
        return true;
    }
    if( CString[i] != CString[j])
    {
        return false;
    }

    return IsPalindrome(CString, i+1,j-1);
}

int main() 
{
  string PalString;
  cout<<"Enter String"<<endl;
  cin>>PalString;
  int size = PalString.size();

  if(IsPalindrome(PalString,0,size-1))
    {cout<<"True"<<endl;}
  else
    cout<<"False";
}


//Base Condition if starting index and ending index become same or cross each other then return true
//sub problem IsPalindrome(i,j) = IsPalindrome(i+1,j-1) + something