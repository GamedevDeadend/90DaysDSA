#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    

        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    {
        int rightMax[n];
        int leftMin[n];
        
        rightMax[n-1] = a[n-1];
        leftMin[0] = a[0];
        
        for( int i = 1; i<n; i++)
        {
            leftMin[i] = min<int>(a[i],leftMin[i-1]);
        }
        
        for( int j = n-2; j>-1; j--)
        {
            rightMax[j] = max<int>(a[j], rightMax[j+1]);
        }
        
        int x = 0;
        int y = 0;
        
        int res = INT_MIN;
        
        while( x<n && y<n)
        {
            if( rightMax[y] >= leftMin[x] )
            {
                res = max<int>(y-x, res);
                y++;
            }
            else
            {
                x++;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends