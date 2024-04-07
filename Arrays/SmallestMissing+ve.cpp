//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        bool present [n] = {false};
        for (int i = 0; i<n; i++)
        {
            if( (arr[i]>0) && (arr[i]<= n) )
            {
                present[arr[i]-1] = true;
            }
            
        }
        
        for (int i = 0; i<n; i++)
        {
            if( present[i] != true)
            {
                return (i+1);        
            }
        }// Your code here
        
        return (n+1);
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 


//Used My own logic but for intution see this
//https://www.youtube.com/watch?v=aBhla9jSAeg&t=1010s