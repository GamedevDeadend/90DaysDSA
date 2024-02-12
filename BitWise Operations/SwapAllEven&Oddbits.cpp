#include<bits/stdc++.h>
using namespace std;

// Ref link - https://www.youtube.com/watch?v=GWLCF808oVI

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        // mask n with 0xAAA to get bits at even pos
        // right shift even bits by 1 as we see in pattern all even bits are 1 right shifted
        // mask n with 0x555 to get bits at odd pos
        // left shift odd bits by 1 as we see in pattern all odd bits are 1 left shifted

        int even_bit = n&0xAAAAAAAA; // 0xAAAAAAA = 1010...
        int odd_bit = n&0x55555555; // 0x55555 = 01010101...
        
        even_bit = even_bit >> 1;
        odd_bit = odd_bit << 1;
        
        //then or of even & odd will given n with odd and even pos bit switched.
        return(even_bit|odd_bit);
    	// Your code here
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}

