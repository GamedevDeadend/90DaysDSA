/// Medium lvl questions because time complexity (log n)
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n<2) return n;
        
        // MSB in n
        int msb = log2(n);
        
        // msb*(2^(msb-1)) => count of set bits when msb is set
        // ( (n-(1<<msb))+1 ) =>count of numbers less than n with MSB not set. Adding 1 includes n
        // countSetBits(n-(1<<msb) => Recursively calls the function to count the set bits for numbers less than n with the MSB not set.
        
        return ( msb * (1<<(msb-1)) ) + ( (n-(1<<msb))+1 ) + ( countSetBits(n-(1<<msb)) );
         
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends