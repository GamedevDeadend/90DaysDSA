#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


//Function to return the lexicographically sorted power-set of the string.
vector<string> recursionSet(string str, string curr, vector<string>vec, int i)
{
    if( i >=  str.length())
    {
        vec.push_back(curr);
        //cout<<curr<<" ";
        return vec;
    }
    
    vec = recursionSet(str, curr, vec, i+1);
    vec = recursionSet(str, curr+str[i], vec, i+1);
    return vec;
}
vector <string> powerSet(string s)
{
    vector <string>vec = recursionSet(s,"",{},0); //{} shortcut for empty vector
    return vec;
   //Your code here
}


//{ Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;//testcases
    while(T--)
    {
        string s;
        cin>>s;//input string
        
        //calling powerSet() function
        vector<string> ans = powerSet(s);
        
        //sorting the result of the powerSet() function
        sort(ans.begin(),ans.end());
        
        //printing the result
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
}