/* The efficient approach comprises of 2 steps:

Getting the transpose of the matrix by swapping arr[i][j] with arr[j][i]
Reversing the transpose to get the final array.
Time Complexity: O(N*N)

Space Complexity: O(1)

 */
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix) 
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for(int j = i + 1; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        
        
        for( int i = 0; i < matrix.size(); i++)
        {
            int high = (matrix.size()-1), low = 0;
            
            while(low < high)
            {
                swap(matrix[low][i], matrix[high][i]);
                
                low++;
                high--;
            }
        }
        // code here
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
