//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    {
        long long max = n-1;
        long long min = 0;
        
        long long maxElement = arr[max] + 1;
        
        // TwoINONE = arr[i]*(MAX) +  arr[max]
        //arr[max] = twoINONE%MAX
        //arr[i] = twonInone/MAX
        
        for(int i = 0; i < n; i++)
        {
            if( (i&1) == 0)
            {
                //here we are doing moulo with max to ensure we multiplie old values not modified
                arr[i] = (arr[max] % maxElement)* maxElement + arr[i];
                max--;
            }
            else
            {
                arr[i] = (arr[min] % maxElement)* maxElement + arr[i];
                min++;
            }
        }
        
        for (int i = 0; i<n ; i++)
        {
            arr[i]/=maxElement;
        }
        	// Your code here
    	 
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends