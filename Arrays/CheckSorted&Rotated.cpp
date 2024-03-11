class Solution{
    public:
    // arr: input array
    // num: length of array
    // This function returns true or false
    //Function to check if array is sorted and rotated.
    bool checkRotatedAndSorted(int arr[], int num)
    {
        int count = 0;
        
        for(int i = 0; i<num; i++)
        {
            if( arr[i] > arr[(i+1)%num])
            {
                count++;
            }
            
            if( count > 1)
            {
                return false;
            }
        }
        
        return true;
        // Your code here
        
    }
};