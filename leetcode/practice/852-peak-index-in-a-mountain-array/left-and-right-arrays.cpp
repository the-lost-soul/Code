class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) ;
};

int Solution :: peakIndexInMountainArray(vector<int>& arr)
{
    int len = arr.size() ;
    // stores the index of element greater than the current
    // element in the window [0 , i] .
    int right[len] = {} ;
    // Zeroth element will be maximum in the window [0 , 0] .
    right[0] = 0 ;
    for(int i = 1 ; i < len ; i++)
    {
        if(arr[right[i - 1]] >= arr[i])right[i] = right[i - 1] ;
        else right[i] = i ;
    }
    // stores the index of element greater than the current
    // element in the window [i , len) .
    int left[len] = {} ;
    // By default ast element will be max .
    left[len - 1] = len - 1 ;
    for(int i = len - 2 ; i >= 0 ; i--)
    {
        if(arr[left[i + 1]] >= arr[i])left[i] = left[i + 1] ;
        else left[i] = i ;
    }
    
    // Retuen the index where both the left and right arrays have same index .
    for(int i = 0 ; i < len ; i++)
    {
        if(right[i] == left[i])return i ;
    }
    return 0 ;
}
