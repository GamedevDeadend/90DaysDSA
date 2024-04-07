//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){


        //SOLVED IT AT FIRST TIME BUT IT WAS HARD
        // code here
                vector<vector<int>>days;
        int profit = 0;
        
        vector<int>day;
        
        for(int i = 0; i<n; i++)
        {
           // cout<< "INDEX "<<i<<endl;
            
            if( i != n-1  && A[i+1] > A[i])
            {
                if( day.empty())
                {
                    day.push_back(i);
                  //  cout<<"BUY "<<i<<endl;
                }
            }
            else
            {
                if(A[i+1] != A[i])
                {
                    if( !day.empty())
                    {
                        day.push_back(i);
                        
                        if( day.size() == 2)
                        {
                            //cout<<"buy day "<<day[0]<<" Sell day"<<day[1]<<endl;
                            days.push_back(day);
                            day.clear();
                        }
                    }
                    
                   // cout<<" SELL"<<i<<endl;
                }
            }
            

        }
        
        return days;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends