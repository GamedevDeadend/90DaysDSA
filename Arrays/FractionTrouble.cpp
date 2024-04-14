//{ Driver Code Starts
//https://www.youtube.com/watch?v=niUkBbIU_0I
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int gcd(int n1, int n2)
	{
	    if( n2 == 0)
	    {
	        return n1;
	    }
	    
	    return gcd(n2, n1%n2);
	}
	
	vector<int>LargestFraction(int n, int d)
	{
	    
	    int Max = 10000;
	    
	    int num = 0;
	    int deno = 1;
	    
	    for( int q = 10000; q > 1; q--)
	    {
	        int p = ((n*q-1)/d);

            //The subtraction of 1 from n*q ensures just smaller fraction than previous p/q;

	        if( (gcd(p,q) == 1) && (num * q <= deno * p)) //p/q is greater than the stored one
	            num = p;
	            deno = q;
	        }
	    }
	    
	    return  vector<int>{num, deno};;
	        // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, d;
		cin >> n >> d;
		Solution ob;
		vector<int>ans = ob.LargestFraction(n, d);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}