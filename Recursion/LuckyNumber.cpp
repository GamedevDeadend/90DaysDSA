//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False
//https://www.youtube.com/watch?v=sleTfhsPPIE
class Solution{
public:

    int pass  = 2;
    
    bool isLucky(int n) 
    {
       
       if(pass>n)
            return true;
        
        if( n%pass == 0)
            return false;
        
        n = n - (n/pass);
        pass++;
        return isLucky(n);
        // code here
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends