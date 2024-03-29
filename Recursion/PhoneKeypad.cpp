//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    //add possible
    
    vector<string> KeysMapper = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    
    void CombinationCreator(int a[], int N, string temp, int i)
    {
        if( i >= N)
        {
            ans.push_back(temp);
            return;
        }
            
        for( int j = 0; j<KeysMapper[a[i]].size(); j++)
        {
            CombinationCreator(a, N, temp+KeysMapper[a[i]][j], i+1);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
         CombinationCreator(a,N,"",0);
         return ans;
        //Your code here
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}