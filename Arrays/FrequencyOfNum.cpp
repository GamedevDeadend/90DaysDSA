//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


//https://www.youtube.com/watch?v=t3vikCLXctg
// } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // normal index of Arry 0,1,2,3,4
        // index without'0' 1,2,3,4,5
        // 
        
        int i = 0;
        while( i<N )
        {
            if( arr[i] <= 0 || arr[i] > N)
            {
                i++;
                continue;
            }
            
            int indexFromOne = arr[i]-1;
            
            if( arr[indexFromOne] > 0)
            {
                arr[i] = arr[indexFromOne];
                arr[indexFromOne] = -1;
            }
            else
            {
                arr[i] = 0;
                arr[indexFromOne]--;
                i++;
            }
        }
        
        for(int i = 0; i<N; i++)
        {
            if( arr[i] < 0)
            {
                arr[i]*=(-1);
            }
            else
            {
                arr[i] = 0;
            }
        }
        // code here
    }
};


//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}





// } Driver Code Ends