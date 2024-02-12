#include <iostream>
#include <string>
using namespace std;

void PrintPowSet(string st)
{
    int l = st.length();
    int msb = 1<<l;

    for( int i = 0; i < msb; i++)
    {
        for( int j = 0; j < l; j++)
        {
            if( (i&(1<<j)) != 0 )
                cout<<st[j];
        }

        cout<<"\n";
    }
}
int main() 
{
   // Power set of "abc" = "no character",a,b,c,ab,ac,bc,abc
   /*
     so we can map it using bits
     abc
     000 = ""
     001 = "c"
     010 = "b"
     011 = "bc"
     100 = "a"
     101 = "ac"
     110 = "ab"
     111 = "abc"
   */
  string st;
  cout<<"Enter string with different characters"<<endl;
  cin>>st;

  PrintPowSet(st);

}