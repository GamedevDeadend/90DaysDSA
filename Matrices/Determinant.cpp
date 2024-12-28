//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    
    vector<vector<int>> getCofactor( vector<vector<int>> &mat, int p, int q)
    {
        
        int n = mat.size();
        vector<vector<int>> temp(n-1, vector<int>(n-1));
        int i = 0, j = 0;
        
        for( int row = 0; row < n; row ++)
        {
            //vector<int> currRow;
            for( int col = 0; col < n; col++)
            {
                
                if(row != p && col != q)
                {
                    temp [i][j++] = mat [row][col];
                }
                
                
                if( j == n-1)
                {
                    j = 0;
                    i++;
                }
            }
        }
        
        return temp;
    }
    
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        int d = 0;
        int sign = 1;
        
        if(n == 1)
            return matrix[0][0];
        
        
        for(int i = 0; i < n; i++)
        {
            auto tempv = getCofactor(matrix, 0, i);
            
            d += sign*matrix[0][i]*determinantOfMatrix(tempv, tempv.size()-1);
            
            sign *= -1;
        }
        
        return d;
        // code here 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends