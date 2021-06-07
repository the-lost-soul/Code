class Solution {
public:
    int search(vector<int>& nums, int target) ;
};

int Solution :: search(vector<int>& arr , int target)
{
    int low = 0 , high = arr.size() - 1 ;
    while(low <= high)
    {
        // This may cause integer overflow for larger arrays .
        // Try to use --> mid = low + (end - low)/2 ;
        int mid = (low + high)/2 ;
        if(arr[mid] == target)return mid ;
        else if(arr[mid] > target)high = mid - 1 ;
        else low = mid + 1 ;
    }
    return -1 ;
    
}
