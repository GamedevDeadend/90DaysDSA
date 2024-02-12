//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    
    //function to check how many elemnt in array have pattern mask msb as set bit in their binary form 
    int check_bit(int a [], int n, int pattern)
    {
        int count = 0;
        for(int i = 0; i<n;i++)
        {
            if( (pattern & a[i]) == pattern) count++;
        }

        return count;
        
    }
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        // observation needed max AND value must msb as set bit.
        int res = 0;
        int mask = 0;
        int count = 0;
        
        // i  = bit; iterating from msb to lsb
        for (int i = 31 ; i>=0; i--)
        {
            mask = res | (1<<i); // mask for msb at first run 00000..(32 zeros) then 1000..(31 zeros)
            count = check_bit(arr, N, mask);// count will return no. of int in array having msb of mask as set in their binary form;
            
             // if there are two or more elements in array like that then set next msb bit; 
            //for ex mask  = 1000 then next mask 1100
            if( count >= 2)
            {
                res = res | (1<<i);
            }
            
        }// Your code here
        
            return res;
        
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}