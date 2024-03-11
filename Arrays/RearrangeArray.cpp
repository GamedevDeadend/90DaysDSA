//{ Driver Code Starts
#include<bits/stdc++.h> // O(1) space
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    
    // let a = arr[i] & b = arr[arr[i]]
    // if n = lenth of arr
    // let v = arr[arr[i]]*n + arr[i]
    // arr[i] = v%n;
    // arr[arr[i]] = v/n;
    //https://www.youtube.com/watch?v=hjMUPcwkpJ8
    
    void arrange(long long arr[], int n)
    {
        // Your code here
        for(int i = 0; i<n; i++)
        {
            long long newElement = (arr[arr[i]])%n;
            arr[i] = newElement*n + arr[i];
        }
        
        for(int i = 0; i<n; i++)
        {
            arr[i] = arr[i]/n;
        }
        
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends